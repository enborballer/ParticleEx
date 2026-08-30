#include "CTxdStore.h"

int CTxdStore::AddTxdSlot(char  const* name)
{
	return ((int (__cdecl *)(char  const*))AddressByVersion(0x580F00, 0x580F20, 0x580D30))(name);
}

void CTxdStore::RemoveTxdSlot(int index)
{
	((void (__cdecl *)(int))AddressByVersion(0x580E90, 0x580EB0, 0x580CC0))(index);
}


int CTxdStore::FindTxdSlot(char  const* name)
{
	return ((int (__cdecl *)(char  const*))AddressByVersion(0x580D70, 0x580D90, 0x580BA0))(name);
}

bool CTxdStore::LoadTxd(int index, char  const* filename)
{
	return ((bool (__cdecl *)(int, char  const*))AddressByVersion(0x580CD0, 0x580CF0, 0x580B00))(index, filename);
}

void CTxdStore::SetCurrentTxd(int index)
{
	((void (__cdecl *)(int))AddressByVersion(0x580AD0, 0x580AF0, 0x580900))(index);
}

void CTxdStore::PushCurrentTxd()
{
	((void (__cdecl *)())AddressByVersion(0x580AC0, 0x580AE0, 0x5808F0))();
}

void CTxdStore::PopCurrentTxd()
{
	((void (__cdecl *)())AddressByVersion(0x580AA0, 0x580AC0, 0x5808D0))();
}

CTexDictionary *CTxdStore::AddRef(int index)
{
	return ((CTexDictionary *(__cdecl *)(int))AddressByVersion(0x580A60, 0x580A80, 0x580890))(index);
}
