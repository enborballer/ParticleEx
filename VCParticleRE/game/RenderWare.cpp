#include "RenderWare.h"

void         *RwEngineInstance = *(void **)ADDR_RWENGINEINSTANCE;


// Converted from static RwBool __cdecl RwRenderStateSet(RwRenderState state, void *value) 0x5A43C0
RwBool RwRenderStateSet(RwRenderState state, void* value)
{
	return ((RwBool (__cdecl *)(RwRenderState, void*))AddressByVersion(0x649BA0, 0x649BF0, 0x648B50))(state, value);
}

// Converted from static RwTexture * __cdecl RwTextureRead(const RwChar *name, const RwChar *maskName) 0x5A7580
RwTexture* RwTextureRead(RwChar const* name, RwChar const* maskName)
{
	return ((RwTexture* (__cdecl *)(RwChar const*, RwChar const*))AddressByVersion(0x64E110, 0x64E160, 0x64D0C0))(name, maskName);
}

// Converted from static RwBool __cdecl RwTextureDestroy(RwTexture *texture) 0x5A7330
RwBool RwTextureDestroy(RwTexture* texture)
{
	return ((RwBool (__cdecl *)(RwTexture*))AddressByVersion(0x64DEC0, 0x64DF10, 0x64CE70))(texture);
}