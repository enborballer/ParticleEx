#pragma once

#include "types.h"
#include "CVector.h"
#include "CVector2D.h"
#include "CRGBA.h"
#include "CEntity.h"
#include "CMatrix.h"
#include "CParticle.h"
#include "CParticleObject.h"
#include "CGeneral.h"
#include "CTxdStore.h"
#include "CTimer.h"
#include "CColPoint.h"
//#include "CColModel.h"
//#include "CBaseModelInfo.h"
//#include "CAutomobile.h"
#include "CPed.h"
#include "CVehicle.h"
//#include "CBoat.h"
#include "CFileMgr.h"
#include "cDMAudio.h"
//#include "CModelInfo.h"
#include "CSprite.h"
#include "CWorld.h"
#include "CCamera.h"
#include "CShadows.h"
#include "CReplay.h"
#include "CClock.h"
#include "CDraw.h"
#include "CWeather.h"
#include "CFire.h"
#include "CGame.h"
#include "CMBlur.h"


#define RsGlobal (*(RsGlobalType *)ADDR_RSGLOBAL)
#define PsGlobal (*(PsGlobalType *)ADDR_PSGLOBAL)
#define PSGLOBAL(var) (((PsGlobalType *)(RsGlobal.ps))->var)

//#define DEFAULT_SCREEN_WIDTH (640)
//#define DEFAULT_SCREEN_HEIGHT (448)


#define DEFAULT_SCREEN_WIDTH (1.0f / **(float **)(AddressByVersion(0x560C62, 0x560C82, 0x560B52) + 2))
#define DEFAULT_SCREEN_HEIGHT (1.0f / **(float **)(AddressByVersion(0x560CA0, 0x560CC0, 0x560B90) + 2))


#define SCREEN_WIDTH Float(RsGlobal.w)
#define SCREEN_HEIGHT Float(RsGlobal.h)

#define SCREEN_STRETCH_X(a)   Float( a * ( SCREEN_WIDTH / Float(DEFAULT_SCREEN_WIDTH)  ) )
#define SCREEN_STRETCH_Y(a)   Float( a * ( SCREEN_HEIGHT / Float(DEFAULT_SCREEN_HEIGHT) ) )

#define SCREEN_FROM_RIGHT(a)  Float( SCREEN_WIDTH - SCREEN_STRETCH_X(a) )
#define SCREEN_FROM_BOTTOM(a) Float( SCREEN_HEIGHT - SCREEN_STRETCH_Y(a) )



enum eWeaponType
{
	WEAPONTYPE_UNARMED								= 0,
	WEAPONTYPE_BRASSKNUCKLE							= 1,
	WEAPONTYPE_SCREWDRIVER							= 2,
	WEAPONTYPE_GOLFCLUB								= 3,
	WEAPONTYPE_NIGHTSTICK							= 4,
	WEAPONTYPE_KNIFE									= 5,
	WEAPONTYPE_BASEBALLBAT							= 6,
	WEAPONTYPE_HAMMER								= 7,
	WEAPONTYPE_CLEAVER								= 8,
	WEAPONTYPE_MACHETE								= 9,
	WEAPONTYPE_KATANA								= 10,
	WEAPONTYPE_CHAINSAW								= 11,
	WEAPONTYPE_GRENADE								= 12,
	WEAPONTYPE_DETONATOR_GRENADE						= 13,
	WEAPONTYPE_TEARGAS								= 14,
	WEAPONTYPE_MOLOTOV								= 15,
	WEAPONTYPE_ROCKET								= 16,
	WEAPONTYPE_PISTOL								= 17,
	WEAPONTYPE_PYTHON								= 18,
	WEAPONTYPE_SHOTGUN								= 19,
	WEAPONTYPE_SPAS12_SHOTGUN						= 20,
	WEAPONTYPE_STUBBY_SHOTGUN						= 21,
	WEAPONTYPE_TEC9									= 22,
	WEAPONTYPE_UZI									= 23,
	WEAPONTYPE_SILENCED_INGRAM						= 24,
	WEAPONTYPE_MP5									= 25,
	WEAPONTYPE_M4									= 26,
	WEAPONTYPE_RUGER									= 27,
	WEAPONTYPE_SNIPERRIFLE							= 28,
	WEAPONTYPE_LASERSCOPE							= 29,
	WEAPONTYPE_ROCKETLAUNCHER						= 30,
	WEAPONTYPE_FLAMETHROWER							= 31,
	WEAPONTYPE_M60									= 32,
	WEAPONTYPE_MINIGUN								= 33,
	WEAPONTYPE_DETONATOR								= 34,
	WEAPONTYPE_HELICANNON							= 35,
	WEAPONTYPE_CAMERA								= 36,
	WEAPONTYPE_PAD37									= 37,
	WEAPONTYPE_ARMOUR								= 38,
	WEAPONTYPE_RAMMEDBYCAR							= 39,
	WEAPONTYPE_RUNOVERBYCAR							= 40,
	WEAPONTYPE_EXPLOSION								= 41,
	WEAPONTYPE_UZI_DRIVEBY							= 42,
	WEAPONTYPE_DROWNING								= 43,
	WEAPONTYPE_FALL									= 44,
	WEAPONTYPE_UNIDENTIFIED							= 45,
	WEAPONTYPE_ANYMELEE								= 46,
	WEAPONTYPE_ANYWEAPON								= 47
};

static   CVector operator*(CMatrix const& matrix, CVector const& vector)
{
	return ((CVector (__cdecl *)(CMatrix  const&, CVector  const&))AddressByVersion(0x4DFF20, 0x4DFF40, 0x4DFDE0))(matrix, vector);
}


static void PlayOneShotScriptObject(unsigned char id, CVector const &pos)
{
	((void (__cdecl *)(unsigned char, CVector const &))AddressByVersion(0x5F9210, 0x5F9230, 0x5F8E70))(id, pos);
}

static RwTexture *&gpBloodPoolTex = *(RwTexture **)AddressByVersion(0xA0DAC8, 0xA0DAD0, 0xA0CAD0);


static CPed* FindPlayerPed()
{
	return ((CPed *(__cdecl *)())AddressByVersion(0x4BC120, 0x4BC140, 0x4BBFF0))();
}
