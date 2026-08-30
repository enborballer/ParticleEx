#include "PObjectMgr.h"
#include "ParticleEx.h"
#include <windows.h>
#include <fstream>

char *aPObjectType[] =
{
	"POBJECT_PAVEMENT_STEAM",
	"POBJECT_PAVEMENT_STEAM_SLOWMOTION",
	"POBJECT_WALL_STEAM",
	"POBJECT_WALL_STEAM_SLOWMOTION",
	"POBJECT_DARK_SMOKE",
	"POBJECT_FIRE_HYDRANT",
	"POBJECT_CAR_WATER_SPLASH",
	"POBJECT_PED_WATER_SPLASH",
	"POBJECT_SPLASHES_AROUND",
	"POBJECT_SMALL_FIRE",
	"POBJECT_BIG_FIRE",
	"POBJECT_DRY_ICE",
	"POBJECT_DRY_ICE_SLOWMOTION",
	"POBJECT_FIRE_TRAIL",
	"POBJECT_SMOKE_TRAIL",
	"POBJECT_FIREBALL_AND_SMOKE",
	"POBJECT_ROCKET_TRAIL",
	"POBJECT_EXPLOSION_ONCE",
	"POBJECT_CATALINAS_GUNFLASH",
	"POBJECT_CATALINAS_SHOTGUNFLASH"
};

char *aParticleObjectState[] =
{
	"NONE",
	"CLOSE",
	"FAR",
	"FREE"
};



CParticleObject &getPObject(unsigned int i)
{
	//CParticleObject (&gPObjectArray)[MAX_PARTICLEOBJECTS] = *(CParticleObject(*)[MAX_PARTICLEOBJECTS])AddressByVersion(0x62A58C, 0x62A58C, 0x63A58C);
	
	CParticleObject **_gPObjectArray = (CParticleObject**)(AddressByVersion(0x4BC4A0, 0x4BC590, 0x4BC520) + 1);
	
	return (*_gPObjectArray)[i];
}

unsigned int getMaxPObjects()
{
	static unsigned int size = (unsigned int)-1;
	if ( size == (unsigned int)-1 )
	{
		size = 0;
		for ( CParticleObject *p= CParticleObject::pCloseListHead; p; p = p->m_pNext )
			size++;
		
		for ( CParticleObject *p= CParticleObject::pFarListHead; p; p = p->m_pNext )
			size++;
		
		for ( CParticleObject *p= CParticleObject::pUnusedListHead; p; p = p->m_pNext )
			size++;
	}
	
	return size;
}


void DumpPObject(CParticleObject *pobj)
{
	Log("pos: %f, %f, %f", pobj->m_sCoords.pos.x, pobj->m_sCoords.pos.y, pobj->m_sCoords.pos.z);
	Log("up: %f, %f, %f", pobj->m_sCoords.up.x, pobj->m_sCoords.up.y, pobj->m_sCoords.up.z);
	Log("right: %f, %f, %f", pobj->m_sCoords.right.x, pobj->m_sCoords.right.y, pobj->m_sCoords.right.z);
	Log("m_pNext: 0x%X", pobj->m_pNext);
	Log("m_pPrev: 0x%X", pobj->m_pPrev);
	Log("m_pParticle: 0x%X", pobj->m_pParticle);
	Log("m_nRemoveTimer: %d", pobj->m_nRemoveTimer);
	Log("m_Type: %d", pobj->m_Type);
	Log("m_ParticleType: %d", pobj->m_ParticleType);
	Log("m_nNumEffectCycles: %d", pobj->m_nNumEffectCycles);
	Log("m_nSkipFrames: %d", pobj->m_nSkipFrames);
	Log("m_nFrameCounter: %d", pobj->m_nFrameCounter);
	Log("m_nState: %d", pobj->m_nState);
	Log("m_vecTarget: %f, %f, %f", pobj->m_vecTarget.x, pobj->m_vecTarget.y, pobj->m_vecTarget.z);
	Log("m_fRandVal: %f", pobj->m_fRandVal);
	Log("m_fSize: %f", pobj->m_fSize);
	Log("m_Color: %d, %d, %d, %d", pobj->m_Color.r, pobj->m_Color.g, pobj->m_Color.b, pobj->m_Color.a);
	Log("m_bRemove: %d", pobj->m_bRemove);
	Log("m_nCreationChance: %d", pobj->m_nCreationChance);
}

void DumpPObjects()
{
	static const char *particleSwitch[] = { "PC", "Xbox", "PS2" };
	
	Log("---------------------------------------------");
	Log("PObjectDump");
	Log("Current Particle %s", particleSwitch[CParticleEx::GetCurrentParticle()]);
	Log("---------------------------------------------");
	for ( Int32 i = 0; i < getMaxPObjects(); i++ )
	{
		Log("gPObjectArray[%d]", i);
		DumpPObject(&getPObject(i));
		Log("\n");
	}
	Log("---------------------------------------------\n");
}

Int32 PObject2Index(CParticleObject *pobj)
{
	if ( pobj != NULL )
	{
		ASSERT(pobj >= &getPObject(0));
		ASSERT(pobj <= &getPObject(getMaxPObjects() - 1));
	}

	if ( pobj == NULL )
		return -1;
	else
		return Int32(pobj - &getPObject(0));
}

CParticleObject *Index2PObject(Int32 index)
{
	if ( index != -1 )
	{
		ASSERT(index >= 0);
		ASSERT(index < getMaxPObjects());
	}
	
	if ( index == -1 )
		return NULL;
	else
		return &getPObject(index);
}

Int32 Timer2Value(Int32 time)
{
	if ( time == 0 )
		return 0;
	else
	{
		if ( time < CTimer::m_snTimeInMilliseconds )
			return 0;
		else
			return time - CTimer::m_snTimeInMilliseconds;
	}
}

Int32 Value2Timer(Int32 time)
{
	if ( time == 0 )
		return 0;
	else
		return time + CTimer::m_snTimeInMilliseconds;
}

bool CPObjectMgr::SelectFile(bool save, char *out)
{
	CHAR Title[MAX_PATH];
	CHAR Path[MAX_PATH];
	CHAR FileName[MAX_PATH];
	
	if ( save )
		sprintf(Title, "Export a Particle Object file");
	else
		sprintf(Title, "Import a Particle Object file");

	sprintf(Path,"%s\\ParticleEx", GetAsiPath().c_str());

	if ( save )
		sprintf(FileName, "particleobjects.pobj");
	else
		sprintf(FileName, "");

	OPENFILENAME		ofn;
	
	ZeroMemory(&ofn, sizeof(OPENFILENAME));
	
	ofn.lStructSize       = sizeof(OPENFILENAME);
	ofn.hwndOwner         = NULL;
	ofn.hInstance         = NULL;
	ofn.lpstrFilter       = "Particle Object Files\0*.pobj\0\0";
	ofn.lpstrCustomFilter = NULL;
	ofn.nMaxCustFilter    = 0;
	ofn.nFilterIndex      = 0;
	ofn.lpstrFile         = FileName;
	ofn.nMaxFile          = MAX_PATH;
	ofn.lpstrFileTitle    = NULL;
	ofn.nMaxFileTitle     = 0;
	ofn.lpstrInitialDir   = Path;
	ofn.lpstrTitle        = Title;
	ofn.Flags             = OFN_PATHMUSTEXIST | OFN_HIDEREADONLY | OFN_FILEMUSTEXIST;
	ofn.nFileOffset       = 0;
	ofn.nFileExtension    = 0;
	ofn.lpstrDefExt       = "pobj";
	ofn.lCustData         = NULL;
	ofn.lpfnHook          = NULL;
	ofn.lpTemplateName    = NULL;


	HWND hActive = PSGLOBAL(window);
	
	bool bHideMouseAgain = false;
	if (hActive)
	{
		ShowWindow(hActive, SW_HIDE);
		SetCursor(LoadCursor(NULL, IDC_ARROW));
		bHideMouseAgain = ShowCursor(true) <= 0;
		while (ShowCursor(true) < 0)
			;
	}
	
	CHAR  curr_directory[MAX_PATH];
	GetCurrentDirectory(MAX_PATH, curr_directory);
	
	BOOL r;
	if(save)
		r = GetSaveFileName(&ofn);
	else
		r = GetOpenFileName(&ofn);
	
	SetCurrentDirectory(curr_directory);
	
	if (hActive)
	{
		if (bHideMouseAgain)
		{
			while (ShowCursor(false) >= 0)
				;
		}
		ShowWindow(hActive, SW_SHOW);
	}
	
	if ( r )
		sprintf(out,"%s", FileName);

	return r;
}


void CPObjectMgr::Save()
{
	getMaxPObjects();
	
	char filepath[MAX_PATH];
	if ( SelectFile(true, filepath) )
	{
		try
		{
			std::ofstream file(filepath);
			if(!file.is_open())
				throw std::ios_base::failure("Unable to open file");
			
			char buff[1024+1];
			
			sprintf(buff, "CloseListHead %d", PObject2Index(CParticleObject::pCloseListHead));
			file << buff << std::endl;
			sprintf(buff, "FarListHead %d", PObject2Index(CParticleObject::pFarListHead));
			file << buff << std::endl;
			sprintf(buff, "UnusedListHead %d", PObject2Index(CParticleObject::pUnusedListHead));
			file << buff << std::endl;
			
			for ( Int32 i = 0; i < getMaxPObjects(); i++ )
			{
				CParticleObject *pobj = &getPObject(i);
				
				sprintf
				(
					buff, "pobj[%d]: %f, %f, %f, %f, %f, %f, %f, %f, %f, %f, %f, %f, %d, %d, %d, %d, %d, %d, %d, %d, %d, %f, %f, %f, %f, %f, %d, %d, %d, %d, %d, %d",
					i,
					pobj->m_sCoords.pos.x,
					pobj->m_sCoords.pos.y,
					pobj->m_sCoords.pos.z,
					pobj->m_sCoords.right.x,
					pobj->m_sCoords.right.y,
					pobj->m_sCoords.right.z,
					pobj->m_sCoords.up.x,
					pobj->m_sCoords.up.y,
					pobj->m_sCoords.up.z,
					pobj->m_sCoords.at.x,
					pobj->m_sCoords.at.y,
					pobj->m_sCoords.at.z,
					PObject2Index(pobj->m_pNext),
					PObject2Index(pobj->m_pPrev),
					Timer2Value(pobj->m_nRemoveTimer),
					pobj->m_Type,
					pobj->m_ParticleType,
					pobj->m_nNumEffectCycles,
					pobj->m_nSkipFrames,
					pobj->m_nFrameCounter,
					pobj->m_nState,
					pobj->m_vecTarget.x,
					pobj->m_vecTarget.y,
					pobj->m_vecTarget.z,
					pobj->m_fRandVal,
					pobj->m_fSize,
					pobj->m_Color.r,
					pobj->m_Color.g,
					pobj->m_Color.b,
					pobj->m_Color.a,
					pobj->m_bRemove,
					pobj->m_nCreationChance
				);
				
				file << buff << std::endl;
			}
			
			file.close();
		}
		catch(const std::exception& e)
		{
			FATAL("%s", e.what());
		}
		catch(...)
		{
			FATAL("Unknown Exception");
		}
	}
}

void CPObjectMgr::Load()
{
	getMaxPObjects();
	
	char filepath[MAX_PATH];
	if ( SelectFile(false, filepath) )
	{
		try
		{
			std::ifstream file(filepath);
			if(!file.is_open())
				throw std::ios_base::failure("Unable to open file");
			
			unsigned int lastindex = -1;
			
			memset(&getPObject(0), 0, sizeof(CParticleObject) * getMaxPObjects());
			for ( int i = 0; i < getMaxPObjects(); i++ )
				((void (__thiscall *)(CParticleObject *))AddressByVersion(0x4BC3E0, 0x4BC4D0, 0x4BC460))(&getPObject(i));
			
			for (std::string line; getline(file, line); )
			{
				if (line[0] != ';' && line[0] != '#')
				{
					int i, next, prev;
					int m_nRemoveTimer;
					int m_Type;
					CMatrix m_sCoords;
					int m_ParticleType;
					int m_nNumEffectCycles;
					int m_nSkipFrames;
					int m_nFrameCounter;
					int m_nState;
					CVector m_vecTarget;
					float m_fRandVal;
					float m_fSize;
					int r,g,b,a;
					int m_bRemove;
					int m_nCreationChance;
	
					if ( sscanf(line.c_str(), "CloseListHead %d", &i) == 1 )
						CParticleObject::pCloseListHead = Index2PObject(i);
					else if ( sscanf(line.c_str(), "FarListHead %d", &i) == 1 )
						CParticleObject::pFarListHead = Index2PObject(i);
					else if ( sscanf(line.c_str(), "UnusedListHead %d", &i) == 1 )
						CParticleObject::pUnusedListHead = Index2PObject(i);
					else if ( 33 == sscanf(line.c_str(), "pobj[%d]: %f, %f, %f, %f, %f, %f, %f, %f, %f, %f, %f, %f, %d, %d, %d, %d, %d, %d, %d, %d, %d, %f, %f, %f, %f, %f, %d, %d, %d, %d, %d, %d",
							&i,
							&m_sCoords.pos.x,
							&m_sCoords.pos.y,
							&m_sCoords.pos.z,
							&m_sCoords.right.x,
							&m_sCoords.right.y,
							&m_sCoords.right.z,
							&m_sCoords.up.x,
							&m_sCoords.up.y,
							&m_sCoords.up.z,
							&m_sCoords.at.x,
							&m_sCoords.at.y,
							&m_sCoords.at.z,
							&next,
							&prev,
							&m_nRemoveTimer,
							&m_Type,
							&m_ParticleType,
							&m_nNumEffectCycles,
							&m_nSkipFrames,
							&m_nFrameCounter,
							&m_nState,
							&m_vecTarget.x,
							&m_vecTarget.y,
							&m_vecTarget.z,
							&m_fRandVal,
							&m_fSize,
							&r,
							&g,
							&b,
							&a,
							&m_bRemove,
							&m_nCreationChance ) )
					{
						ASSERT(i >= 0);
						ASSERT(i < getMaxPObjects());
						
						if ( i >= 0 && i < getMaxPObjects() )
						{
							lastindex = i;
							CParticleObject *ppobj = &getPObject(i);	
							
							ppobj->m_sCoords.pos.x = m_sCoords.pos.x;
							ppobj->m_sCoords.pos.y = m_sCoords.pos.y;
							ppobj->m_sCoords.pos.z = m_sCoords.pos.z;
							ppobj->m_sCoords.right.x = m_sCoords.right.x,
							ppobj->m_sCoords.right.y = m_sCoords.right.y,
							ppobj->m_sCoords.right.z = m_sCoords.right.z,
							ppobj->m_sCoords.up.x = m_sCoords.up.x,
							ppobj->m_sCoords.up.y = m_sCoords.up.y,
							ppobj->m_sCoords.up.z = m_sCoords.up.z,
							ppobj->m_sCoords.at.x = m_sCoords.at.x,
							ppobj->m_sCoords.at.y = m_sCoords.at.y,
							ppobj->m_sCoords.at.z = m_sCoords.at.z,
							ppobj->m_pNext = Index2PObject(next);
							ppobj->m_pPrev = Index2PObject(prev);
							ppobj->m_pParticle = NULL;
							ppobj->m_nRemoveTimer = Value2Timer(m_nRemoveTimer);
							ppobj->m_Type = m_Type;
							ppobj->m_ParticleType = m_ParticleType;
							ppobj->m_nNumEffectCycles = m_nNumEffectCycles;
							ppobj->m_nSkipFrames = m_nSkipFrames;
							ppobj->m_nFrameCounter = m_nFrameCounter;
							ppobj->m_nState = m_nState;
							ppobj->m_vecTarget.x = m_vecTarget.x;
							ppobj->m_vecTarget.y = m_vecTarget.y;
							ppobj->m_vecTarget.z = m_vecTarget.z;
							ppobj->m_fRandVal = m_fRandVal;
							ppobj->m_fSize = m_fSize;
							ppobj->m_Color.r = r;
							ppobj->m_Color.g = g;
							ppobj->m_Color.b = b;
							ppobj->m_Color.a = a;
							ppobj->m_bRemove = m_bRemove;
							ppobj->m_nCreationChance = m_nCreationChance;
						}
					}
				}
			}
			
			file.close();
			
			if ( ++lastindex < getMaxPObjects() )
			{
				CParticleObject *tail = CParticleObject::pUnusedListHead;
				while ( tail->m_pNext != NULL )
					tail = tail->m_pNext;
			
				for ( int i = lastindex; i < getMaxPObjects(); i++ )
				{
					CParticleObject *pobj = &getPObject(i);
					pobj->m_nState = PARTICLEOBJECTSTATE_FREE;
					
					tail->m_pNext = pobj;
					pobj->m_pPrev = tail;
					pobj->m_pNext = NULL;
					tail = pobj;
				}
			}
		}
		catch(const std::exception& e)
		{
			FATAL("%s", e.what());
		}
		catch(...)
		{
			FATAL("Unknown Exception");
		}
	}
}