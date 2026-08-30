#pragma once
#include "CMatrix.h"
#include "..\address.h"

#pragma pack(push, 4)
class CPlaceable
{
public:
    CMatrix m_sCoords;
	
	CPlaceable()
	{
		((void (__thiscall *)(CPlaceable *))AddressByVersion(0x4BBAD0, 0x4BBAF0, 0x4BB9A0))(this);
	}
	
    ~CPlaceable() { }  //~CPlaceable();
};
#pragma pack(pop)