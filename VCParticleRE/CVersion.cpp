#include "CVersion.h"
#include <stdio.h>
#include <stdarg.h>

char *aGameVer [4] = 
{
    "",                //0
    "GTA_VC_1_0",       //1
    "GTA_VC_1_1",       //2
    "GTA_VC_Steam"      //3
};

int            nVersion            =    -1;
bool           bAutoVersionCheck   =    1;

DWORD getGameVersion() 
{
	if(*(unsigned int*)0x667BF5 == 0xB85548EC)
		return GTA_VC_10;
	else if(*(unsigned int*)0x667C45 == 0xB85548EC)
		return GTA_VC_11;
	else if(*(unsigned int*)0x666BA5 == 0xB85548EC)
		return GTA_VC_STEAM;
		
	return Unknown_Game;
}

eGame GetGameVersion()
{
	nVersion = (eGame)getGameVersion();
	return (eGame)nVersion;
}

int AddressByVersion(unsigned int _1_0, unsigned int _1_1, unsigned int _Steam)
{
    if (bAutoVersionCheck && nVersion == -1)
    {
        GetGameVersion();
    }

    switch ( nVersion )
    {
        case GTA_VC_10:
           return _1_0;
           break;
        case GTA_VC_11:
           return _1_1;
           break;
        case GTA_VC_STEAM:
           return _Steam;
           break;
    }

	__asm int 3
	return -1;
}

bool IsGTAVC()
{
	eGame Ver = (eGame)getGameVersion();
	if ( Ver == Unknown_Game )
		return false;
	else
		return true;
}

bool IsVersion_1_0()
{
	return ((eGame)getGameVersion()) == GTA_VC_10;
}

bool IsVersion_1_1()
{
	return ((eGame)getGameVersion()) == GTA_VC_11;
}

bool IsVersion_Steam()
{
	return ((eGame)getGameVersion()) == GTA_VC_STEAM;
}