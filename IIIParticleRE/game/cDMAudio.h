#pragma once
#include "..\address.h"
#include "CVector.h"

class cDMAudio
{
public:
	void PlayFrontEndSound(unsigned short v1, unsigned int v2);
	void PlayOneShot(int v1, unsigned short v2, float v3);
};

extern cDMAudio &DMAudio;

extern void PlayOneShotScriptObject(unsigned char id, CVector const &pos);