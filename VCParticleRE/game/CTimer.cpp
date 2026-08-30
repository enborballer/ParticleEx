#include "CTimer.h"


unsigned char& CTimer::m_CodePause = *(unsigned char *)AddressByVersion(0xA10B76, 0xA10B7F, 0xA0FB80);
unsigned char& CTimer::m_UserPause = *(unsigned char *)AddressByVersion(0xA10B36, 0xA10B3E, 0xA0FB3F);
unsigned int& CTimer::m_FrameCounter = *(unsigned int *)AddressByVersion(0xA0D898, 0xA0D8A0, 0xA0C8A0);
float& CTimer::ms_fTimeStep = *(float *)AddressByVersion(0x975424, 0x97542C, 0x97442C);
unsigned int& CTimer::m_snTimeInMilliseconds = *(unsigned int *)AddressByVersion(0x974B2C, 0x974B34, 0x973B34);