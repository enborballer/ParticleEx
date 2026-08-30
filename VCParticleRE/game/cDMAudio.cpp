#include "cDMAudio.h"

void cDMAudio::PlayFrontEndSound(unsigned short v1, unsigned int v2)
{
	((void (__thiscall *)(cDMAudio *, unsigned short, unsigned int))AddressByVersion(0x5F9960, 0x5F9980, 0x5F95C0))(this, v1, v2);
}

void cDMAudio::PlayOneShot(int v1, unsigned short v2, float v3)
{
	((void (__thiscall *)(cDMAudio *, int, unsigned short, float))AddressByVersion(0x5F9DA0, 0x5F9DC0, 0x5F9A00))(this, v1, v2, v3);
}


cDMAudio &DMAudio = *(cDMAudio*)AddressByVersion(0xA10B8A, 0xA10B93, 0xA0FB94);