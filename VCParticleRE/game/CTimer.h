#pragma once
#include "..\address.h"

class CTimer
{
public:
	static unsigned char& m_CodePause;
	static unsigned char& m_UserPause;
	static unsigned int& m_FrameCounter;
	static float& ms_fTimeStep;

	static unsigned int& m_snTimeInMilliseconds;
};