#include "CFileMgr.h"

int CFileMgr::LoadTextFile(const char *path, unsigned char *buf, int size, const char *mode)
{
	return ((int (__cdecl *)(const char *, unsigned char *, int, const char *))AddressByVersion(0x48DFB0, 0x48DFC0, 0x48DEA0))(path, buf, size, mode);
}

void CFileMgr::SetDir(char const *dir)
{
	((void (__cdecl *)(char const *))AddressByVersion(0x48E030, 0x48E040, 0x48DF20))(dir);
}