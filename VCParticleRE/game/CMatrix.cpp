#include "CMatrix.h"

CMatrix::~CMatrix()
{
	((void (__thiscall *)(CMatrix *))AddressByVersion(0x4DFAE0, 0x4DFB00, 0x4DF9A0))(this);
}

CMatrix Invert(CMatrix const& in)
{
	return ((CMatrix (__cdecl *)(CMatrix const&))AddressByVersion(0x4DE9C0, 0x4DE9E0, 0x4DE880))(in);
}
