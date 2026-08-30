#include "CParticle.h"

CParticle *&CParticle::m_pUnusedListHead = *(CParticle **)AddressByVersion(0x98002C, 0x980034, 0x97F034);
	

// Converted from static void __cdecl CParticle::ReloadConfig() 0x50C430
void CParticle::ReloadConfig()
{
	((void (__cdecl *)())AddressByVersion(0x565940, 0x565960, 0x565830))();
}

// Converted from static void __cdecl CParticle::Initialise() 0x50C570
void CParticle::Initialise()
{
	((void (__cdecl *)())AddressByVersion(0x564EC0, 0x564EE0, 0x564DB0))();
}

// Converted from static void __cdecl CParticle::Shutdown() 0x50CF40
void CParticle::Shutdown()
{
	((void (__cdecl *)())AddressByVersion(0x564AE0, 0x564B00, 0x5649D0))();
}

void CParticle::AddParticlesAlongLine(tParticleType type, CVector const &vecStart, CVector const &vecEnd, CVector const &vecDir, Float fPower, CEntity *pEntity, Float fSize, Int32 nRotationSpeed, Int32 nRotation, Int32 nCurFrame, Int32 nLifeSpan)
{
	((void (__cdecl *)(tParticleType, CVector const &, CVector const &, CVector const &, Float, CEntity *, Float, Int32, Int32, Int32, Int32))AddressByVersion(0x564940, 0x564960, 0x564830))(type, vecStart, vecEnd, vecDir, fPower, pEntity, fSize, nRotationSpeed, nRotation, nCurFrame, nLifeSpan);
}

// Converted from static CParticle * __cdecl CParticle::AddParticle(tParticleType type, CVector const &vecPos, CVector const &vecDir, CEntity *pEntity, Float fSize, Int32 nRotationSpeed, Int32 nRotation, Int32 nCurFrame, Int32 nLifeSpan) 0x50D140
CParticle* CParticle::AddParticle(tParticleType type, CVector const& vecPos, CVector const& vecDir, CEntity* pEntity, float fSize, int nRotationSpeed, int nRotation, int nCurFrame, int nLifeSpan)
{
	return ((CParticle* (__cdecl *)(tParticleType, CVector const&, CVector const&, CEntity*, float, int, int, int, int))AddressByVersion(0x5648F0, 0x564910, 0x5647E0))(type, vecPos, vecDir, pEntity, fSize, nRotationSpeed, nRotation, nCurFrame, nLifeSpan);
}

// Converted from static CParticle * __cdecl CParticle::AddParticle(tParticleType type, CVector const &vecPos, CVector const &vecDir, CEntity *pEntity, Float fSize, RwRGBA const &color, Int32 nRotationSpeed, Int32 nRotation, Int32 nCurFrame, Int32 nLifeSpan) 0x50D190
CParticle* CParticle::AddParticle(tParticleType type, CVector const& vecPos, CVector const& vecDir, CEntity* pEntity, float fSize, RwRGBA const& color, int nRotationSpeed, int nRotation, int nCurFrame, int nLifeSpan)
{
	return ((CParticle* (__cdecl *)(tParticleType, CVector const&, CVector const&, CEntity*, float, RwRGBA const&, int, int, int, int))AddressByVersion(0x563CC0, 0x563CE0, 0x563BB0))(type, vecPos, vecDir, pEntity, fSize, color, nRotationSpeed, nRotation, nCurFrame, nLifeSpan);
}

// Converted from static void __cdecl CParticle::Update() 0x50DCF0
void CParticle::Update()
{
	((void (__cdecl *)())AddressByVersion(0x561E10, 0x561E30, 0x561D00))();
}

// Converted from static void __cdecl CParticle::Render() 0x50EE20
void CParticle::Render()
{
	((void (__cdecl *)())AddressByVersion(0x5608C0, 0x5608E0, 0x5607B0))();
}

// Converted from static void __cdecl CParticle::RemovePSystem(tParticleType type) 0x50F6E0
void CParticle::RemovePSystem(tParticleType type)
{
	((void (__cdecl *)(tParticleType))AddressByVersion(0x560870, 0x560890, 0x560760))(type);
}

// Converted from static void __cdecl CParticle::RemoveParticle(CParticle *pParticle, CParticle *pPrevParticle, tParticleSystemData *pPSystemData) 0x50F720
void CParticle::RemoveParticle(CParticle* pParticle, CParticle* pPrevParticle, tParticleSystemData* pPSystemData)
{
	((void (__cdecl *)(CParticle*, CParticle*, tParticleSystemData*))AddressByVersion(0x560830, 0x560850, 0x560720))(pParticle, pPrevParticle, pPSystemData);
}

void CParticle::HandleShipsAtHorizonStuff()
{
	((void (__cdecl *)())AddressByVersion(0x5BC440, 0x5BC460, 0x5BC270))();
}

void CParticle::HandleShootableBirdsStuff(CEntity *entity, CVector const&camPos)
{
	((void (__cdecl *)(CEntity *, CVector const&))AddressByVersion(0x5D0180, 0x5D01A0, 0x5CFF50))(entity, camPos);
}

void CParticle::AddJetExplosion(CVector const &vecPos, Float fPower, Float fSize)
{
	((void (__cdecl *)(CVector const &, Float, Float))AddressByVersion(0x5604F0, 0x560510, 0x5603E0))(vecPos, fPower, fSize);
}