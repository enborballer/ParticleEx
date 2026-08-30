#include "CMBlur.h"


void CMBlur::AddRenderFx(RwCamera *camera, RwRect *rect, float z, FxType fx)
{
	((void (__cdecl *)(RwCamera *, RwRect *, float, FxType))AddressByVersion(0x55D160, 0x55D180, 0x55D050))(camera, rect, z, fx);
}