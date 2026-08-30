#pragma once
#include "CVersion.h"
#include ".\game\types.h"

//#if 1
#define VALIDATE_SIZE(struc, size) static_assert(sizeof(struc) == size, "Invalid structure size of " #struc)
#define VALIDATE_OFFSET(struc, member, offset) \
	static_assert(offsetof(struc, member) == offset, "The offset of " #member " in " #struc " is not " #offset "...")
//#endif

struct tDummy { };
static const tDummy dummy_func;

#define FUNCVMT(index) (*(void ***)this)[index]

//#define DUMMY(c) c(tDummy vmt)
#define DUMMY(c) c(tDummy) {}
#define DUMMYB(c, b) c(tDummy vmt) : b(vmt) {}
#define DUMMYCTOR(b) b(dummy_func)

#define ADDR_RSGLOBAL                       AddressByVersion(0x9B48D8, 0x9B48E0, 0x9B38E0)                     
#define ADDR_RWENGINEINSTANCE               AddressByVersion(0x7870C0, 0x7870C8, 0x7860C8)          
#define ADDR_SCENE                          AddressByVersion(0x8100B8, 0x8100C0, 0x80F0C0)
