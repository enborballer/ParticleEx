#include "CWorld.h"

// Converted from static bool __cdecl CWorld::ProcessVerticalLine(CVector const &pos, float a2, CColPoint &point, CEntity *&entity, bool a5, bool a6, bool a7, bool a8, bool a9, bool a10, CStoredCollPoly *a11) 0x4B0DE0
bool CWorld::ProcessVerticalLine(CVector const& pos, float a2, CColPoint& point, CEntity*& entity, bool a5, bool a6, bool a7, bool a8, bool a9, bool a10, CStoredCollPoly* a11)
{
	return ((bool (__cdecl *)(CVector const&, float, CColPoint&, CEntity*&, bool, bool, bool, bool, bool, bool, CStoredCollPoly*))AddressByVersion(0x4B0DE0, 0x4B0ED0, 0x4B0E60))(pos, a2, point, entity, a5, a6, a7, a8, a9, a10, a11);
}

// Converted from static float __cdecl CWorld::FindGroundZFor3DCoord(float x, float y, float z, bool *bOut) 0x4B3AE0
float CWorld::FindGroundZFor3DCoord(float x, float y, float z, bool* bOut)
{
	return ((float (__cdecl *)(float, float, float, bool*))AddressByVersion(0x4B3AE0, 0x4B3BD0, 0x4B3B60))(x, y, z, bOut);
}
