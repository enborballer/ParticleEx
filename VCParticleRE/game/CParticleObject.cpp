#include "CParticleObject.h"

CParticleObject (&gPObjectArray)[MAX_PARTICLEOBJECTS] = *(CParticleObject(*)[MAX_PARTICLEOBJECTS])(AddressByVersion(0x705584, 0x705584, 0x704584));

CParticleObject *&CParticleObject::pCloseListHead = *(CParticleObject **)AddressByVersion(0x9B48AC, 0x9B48B4, 0x9B38B4);
CParticleObject *&CParticleObject::pFarListHead = *(CParticleObject **)AddressByVersion(0xA0DAF8, 0xA0DB00, 0xA0CB00);
CParticleObject *&CParticleObject::pUnusedListHead = *(CParticleObject **)AddressByVersion(0xA0D870, 0xA0D878, 0xA0C878);

// Converted from static void __cdecl CParticleObject::Initialise() 0x42C760
void CParticleObject::Initialise()
{
	((void (__cdecl *)())AddressByVersion(0x4E8970, 0x4E8990, 0x4E8830))();
}

// Converted from static void __cdecl CParticleObject::UpdateAll() 0x4BCA30
void CParticleObject::UpdateAll()
{
	((void (__cdecl *)())AddressByVersion(0x4E8300, 0x4E8320, 0x4E81C0))();
}

// Converted from static CParticleObject * __cdecl CParticleObject::AddObject(unsigned short Type, CVector const &vecPos, CVector const &vecTarget, float fSize, unsigned int nLifeTime, RwRGBA const &Color, unsigned char bCanRemove) 0x4BC5B0
CParticleObject* CParticleObject::AddObject(unsigned short Type, CVector const& vecPos, CVector const& vecTarget, float fSize, unsigned int nLifeTime, RwRGBA const& Color, unsigned char bCanRemove)
{
	return ((CParticleObject* (__cdecl *)(unsigned short, CVector const&, CVector const&, float, unsigned int, RwRGBA const&, unsigned char))AddressByVersion(0x4E8480, 0x4E84A0, 0x4E8340))(Type, vecPos, vecTarget, fSize, nLifeTime, Color, bCanRemove);
}
