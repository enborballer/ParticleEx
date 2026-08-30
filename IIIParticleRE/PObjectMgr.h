#pragma once
#include "_config.h"
#include "_precl.h"


class CPObjectMgr
{
public:
	static bool SelectFile(bool save, char *out);
	
	static void Save();
	static void Load();
};

extern unsigned int getMaxPObjects();
extern CParticleObject &getPObject(unsigned int i);