#include "CDraw.h"

float& CDraw::ms_fNearClipZ = *(float *)AddressByVersion(0x978534, 0x97853C, 0x97753C);
float& CDraw::ms_fFarClipZ = *(float *)AddressByVersion(0xA10678, 0xA10680, 0xA0F680);
