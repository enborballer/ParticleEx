#include "CClock.h"

unsigned char& CClock::ms_nGameClockHours = *(unsigned char*)AddressByVersion(0xA10B6B, 0xA10B74, 0xA0FB75);
unsigned char& CClock::ms_nGameClockMinutes = *(unsigned char*)AddressByVersion(0xA10B92, 0xA10B9B, 0xA0FB9C);
unsigned short& CClock::ms_nGameClockSeconds = *(unsigned short*)AddressByVersion(0xA10A3C, 0xA10A44, 0xA0FA44);