#pragma once
#include "..\address.h"
#include "CColModel.h"
#include "RenderWare.h"
#include "CVector.h"

class CBaseModelInfo
{
public:
	void *vtable;
	char m_aName[24];
	CColModel *m_pColModel;
	void *m_p2dEffect;
	__int16 m_nObjectDataId;
	__int16 m_nRefCount;
	__int16 m_nTxdId;
	char m_nType;
	char m_nNum2dEffects;
	char field_2C;
	char _padding[3];

};

class CClumpModelInfo : public CBaseModelInfo
{
public:
  RpClump *m_pClump;
};
