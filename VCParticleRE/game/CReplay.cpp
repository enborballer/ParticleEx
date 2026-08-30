#include "CReplay.h"

unsigned char &CReplay::Mode = *(unsigned char *)AddressByVersion(0xA10AF6, 0xA10AFE, 0xA0FAFE);	
	
void CReplay::RecordParticle(tParticleType type, CVector const &vecPos, CVector const &vecDir, float fSize, RwRGBA const&color)
{
	return ((void (__cdecl *)(tParticleType, CVector const &, CVector const &, float, RwRGBA const&))AddressByVersion(0x624600, 0x6245E0, 0x624250))(type, vecPos, vecDir, fSize, color);
}
