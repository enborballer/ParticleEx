#pragma once
#include "..\address.h"

class CFileMgr
{
public:
	static int LoadTextFile(char const *path, unsigned char *buf, int size, char  const* mode);
	static void SetDir(char const *dir);
};