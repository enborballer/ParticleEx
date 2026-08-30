#pragma once
#include <Windows.h>

extern int            nVersion;
extern bool           bAutoVersionCheck;


enum eGame
{
    Unknown_Game    = 0,
	
	GTA_VC_10 = 0,
	GTA_VC_11,
	GTA_VC_STEAM
};

extern char *aGameVer [4];

DWORD getGameVersion();
eGame GetGameVersion();
int AddressByVersion(unsigned int _1_0, unsigned int _1_1, unsigned int _Steam);
bool IsGTAVC();
bool IsVersion_1_0();
bool IsVersion_1_1();
bool IsVersion_Steam();