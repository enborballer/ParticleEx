#include "ParticleArray.h"
#include "ParticleEx.h"

std::vector<CParticle>         CParticleArray::ParticlesPC;
std::vector<REXBOX::CParticle> CParticleArray::ParticlesXbox;
std::vector<REPS2::CParticle>  CParticleArray::ParticlesPS2;

void CParticleArray::Initialise()
{
	ReSize(DEFAULT_PARTICLE_ARRAY_SIZE);
}

void CParticleArray::ReInitArrays()
{
	REXBOX::CParticle::InitParticleArray(&ParticlesXbox[0], ParticlesXbox.size());
	REPS2::CParticle::InitParticleArray(&ParticlesPS2[0], ParticlesPS2.size());

	InitOriginalParticleArray(&ParticlesPC[0], ParticlesPC.size());
}


void CParticleArray::InitOriginalParticleArray(CParticle *array, UInt32 size)
{
	CParticle::m_pUnusedListHead = array;
	
	for ( Int32 i = 0; i < size; i++ )
	{
		if ( i == size - 1 )
			array[i].m_pNext = NULL;
		else
			array[i].m_pNext = &array[i + 1];
		
		array[i].m_vecPosition = CVector(0.0f, 0.0f, 0.0f);

		array[i].m_vecVelocity = CVector(0.0f, 0.0f, 0.0f);

		array[i].m_nTimeWhenWillBeDestroyed = 0;

		array[i].m_nTimeWhenColorWillBeChanged = 0;

		array[i].m_fSize = 0.2f;

		array[i].m_fExpansionRate = 0.0f;

		array[i].m_nColorIntensity = 255;

		array[i].m_nFadeToBlackTimer = 0;

		array[i].m_nAlpha = 255;

		array[i].m_nFadeAlphaTimer = 0;

		array[i].m_nCurrentZRotation = 0;

		array[i].m_nZRotationTimer = 0;

		array[i].m_fCurrentZRadius = 0.0f;

		array[i].m_nZRadiusTimer = 0;

		array[i].m_nCurrentFrame = 0;

		array[i].m_nAnimationSpeedTimer = 0;

		array[i].m_nRotation = 0;

		array[i].m_nRotationStep = 0;
	}
}

void CParticleArray::PatchPSystem()
{	
	int ReloadConfigAddress = AddressByVersion(0x50C430, 0x50C520, 0x50C4B0);

	CPatch::SetPointer(ReloadConfigAddress + 0x20 + 0x06, &ParticlesPC[0]);
	CPatch::SetPointer(ReloadConfigAddress + 0x38 + 0x02, &ParticlesPC[0].m_pNext);
	CPatch::SetPointer(ReloadConfigAddress + 0x4A + 0x01, &ParticlesPC[0]);
	CPatch::SetPointer(ReloadConfigAddress + 0x4F + 0x02, &ParticlesPC[0].m_pNext);
	CPatch::SetPointer(ReloadConfigAddress + 0x56 + 0x02, &ParticlesPC[0].m_vecPosition.x);
	CPatch::SetPointer(ReloadConfigAddress + 0x60 + 0x02, &ParticlesPC[0].m_vecPosition.y);
	CPatch::SetPointer(ReloadConfigAddress + 0x6A + 0x02, &ParticlesPC[0].m_vecPosition.z);
	CPatch::SetPointer(ReloadConfigAddress + 0x74 + 0x02, &ParticlesPC[0].m_vecVelocity.x);
	CPatch::SetPointer(ReloadConfigAddress + 0x7E + 0x02, &ParticlesPC[0].m_vecVelocity.y);
	CPatch::SetPointer(ReloadConfigAddress + 0x88 + 0x02, &ParticlesPC[0].m_vecVelocity.z);
	CPatch::SetPointer(ReloadConfigAddress + 0x92 + 0x02, &ParticlesPC[0].m_nTimeWhenWillBeDestroyed);
	CPatch::SetPointer(ReloadConfigAddress + 0x9C + 0x02, &ParticlesPC[0].m_nTimeWhenColorWillBeChanged);
	CPatch::SetPointer(ReloadConfigAddress + 0xA6 + 0x02, &ParticlesPC[0].m_fSize);
	CPatch::SetPointer(ReloadConfigAddress + 0xB0 + 0x02, &ParticlesPC[0].m_fExpansionRate);
	CPatch::SetPointer(ReloadConfigAddress + 0xBA + 0x02, &ParticlesPC[0].m_nColorIntensity);
	CPatch::SetPointer(ReloadConfigAddress + 0xC1 + 0x03, &ParticlesPC[0].m_nFadeToBlackTimer);
	CPatch::SetPointer(ReloadConfigAddress + 0xCA + 0x02, &ParticlesPC[0].m_nAlpha);
	CPatch::SetPointer(ReloadConfigAddress + 0xD1 + 0x03, &ParticlesPC[0].m_nFadeAlphaTimer);
	CPatch::SetPointer(ReloadConfigAddress + 0xDA + 0x03, &ParticlesPC[0].m_nCurrentZRotation);
	CPatch::SetPointer(ReloadConfigAddress + 0xE3 + 0x03, &ParticlesPC[0].m_nZRotationTimer);
	CPatch::SetPointer(ReloadConfigAddress + 0xEC + 0x02, &ParticlesPC[0].m_fCurrentZRadius);
	CPatch::SetPointer(ReloadConfigAddress + 0xF6 + 0x03, &ParticlesPC[0].m_nZRadiusTimer);
	CPatch::SetPointer(ReloadConfigAddress + 0xFF + 0x03, &ParticlesPC[0].m_nCurrentFrame);
	CPatch::SetPointer(ReloadConfigAddress + 0x108 + 0x03, &ParticlesPC[0].m_nAnimationSpeedTimer);
	CPatch::SetPointer(ReloadConfigAddress + 0x111 + 0x03, &ParticlesPC[0].m_nRotation);
	CPatch::SetPointer(ReloadConfigAddress + 0x11A + 0x03, &ParticlesPC[0].m_nRotationStep);

	CPatch::SetUInt(ReloadConfigAddress + 0x30 + 0x02, ParticlesPC.size() - 1); //3
	CPatch::SetUInt(ReloadConfigAddress + 0x126 + 0x02, ParticlesPC.size());  //3
}

void CParticleArray::ReSize(UInt32 size)
{
	try
	{

		ParticlesPC.clear();
		ParticlesPC.resize(size);

		ParticlesXbox.clear();
		ParticlesXbox.resize(size);
		
		ParticlesPS2.clear();
		ParticlesPS2.resize(size);

	}
	catch(std::bad_alloc&)
	{
		FATAL("Caught Bad Alloc Exception");
	}
	catch(const std::exception& e)
	{
		FATAL("%s", e.what());
	}
	catch(...)
	{
		FATAL("Unknown Exception");
	}

	PatchPSystem();
}