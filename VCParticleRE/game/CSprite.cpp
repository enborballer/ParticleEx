#include "CSprite.h"


float &CSprite::m_f2DNearScreenZ = *(float*)AddressByVersion(0x97863C, 0x978644, 0x977644);
float &CSprite::m_f2DFarScreenZ = *(float*)AddressByVersion(0x97F33C, 0x97F344, 0x97E344);
	
	
bool CSprite::CalcScreenCoors(RwV3d const &posn, RwV3d *out, float *w, float *h, bool Unk)
{
	return ((bool (__cdecl *)(RwV3d const &, RwV3d *, float *, float *, bool))AddressByVersion(0x5778B0, 0x5778D0, 0x5777A0))(posn, out, w, h, Unk);
}

// Converted from static void __cdecl CSprite::InitSpriteBuffer2D() 0x51C5B0
void CSprite::InitSpriteBuffer2D()
{
	((void (__cdecl *)())AddressByVersion(0x577740, 0x577760, 0x577630))();
}

// Converted from static void __cdecl CSprite::FlushSpriteBuffer() 0x51C520
void CSprite::FlushSpriteBuffer()
{
	((void (__cdecl *)())AddressByVersion(0x577790, 0x5777B0, 0x577680))();
}

// Converted from static void __cdecl CSprite::RenderBufferedOneXLUSprite2D(float x, float y, float halfWidth, float halfHeight, RwRGBA const &color, short alpha, unsigned char intensity) 0x51E3C0 
void CSprite::RenderBufferedOneXLUSprite2D(float x, float y, float halfWidth, float halfHeight, RwRGBA const& color, short alpha, unsigned char intensity)
{
	((void (__cdecl *)(float, float, float, float, RwRGBA const&, short, unsigned char))AddressByVersion(0x575680, 0x5756A0, 0x575570))(x, y, halfWidth, halfHeight, color, alpha, intensity);
}

// Converted from static void __cdecl CSprite::RenderBufferedOneXLUSprite2D_Rotate_Dimension(float x, float y, float halfWidth, float halfHeight, RwRGBA const &color, short alpha, float rhw, unsigned char intensity) 0x51E490
void CSprite::RenderBufferedOneXLUSprite2D_Rotate_Dimension(float x, float y, float halfWidth, float halfHeight, RwRGBA const& color, short alpha, float rhw, unsigned char intensity)
{
	((void (__cdecl *)(float, float, float, float, RwRGBA const&, short, float, unsigned char))AddressByVersion(0x575440, 0x575460, 0x575330))(x, y, halfWidth, halfHeight, color, alpha, rhw, intensity);
}

// Converted from static void __cdecl CSprite::RenderBufferedOneXLUSprite_Rotate_Dimension(float x, float y, float z, float halfWidth, float halfHeight, unsigned char red, unsigned char green, unsigned char blue, short alpha, float rhw, float rotate, unsigned char aspect) 0x51D5B0
void CSprite::RenderBufferedOneXLUSprite_Rotate_Dimension(float x, float y, float z, float halfWidth, float halfHeight, unsigned char red, unsigned char green, unsigned char blue, short alpha, float rhw, float rotate, unsigned char aspect)
{
	((void (__cdecl *)(float, float, float, float, float, unsigned char, unsigned char, unsigned char, short, float, float, unsigned char))AddressByVersion(0x5761F0, 0x576210, 0x5760E0))(x, y, z, halfWidth, halfHeight, red, green, blue, alpha, rhw, rotate, aspect);
}

// Converted from static void __cdecl CSprite::RenderBufferedOneXLUSprite(float x, float y, float z, float halfWidth, float halfHeight, unsigned char red, unsigned char green, unsigned char blue, short alpha, float rhw, unsigned char aspect) 0x51C5D0
void CSprite::RenderBufferedOneXLUSprite(float x, float y, float z, float halfWidth, float halfHeight, unsigned char red, unsigned char green, unsigned char blue, short alpha, float rhw, unsigned char aspect)
{
	((void (__cdecl *)(float, float, float, float, float, unsigned char, unsigned char, unsigned char, short, float, unsigned char))AddressByVersion(0x577350, 0x577370, 0x577240))(x, y, z, halfWidth, halfHeight, red, green, blue, alpha, rhw, aspect);
}



