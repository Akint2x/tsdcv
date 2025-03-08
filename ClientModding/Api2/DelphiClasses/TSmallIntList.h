#pragma once
#include "TBaseList.h"
#pragma pack(push, 1)

class TSmallIntList : public TBaseList<int32_t>
{
public:

protected:
	char unknown2[4];	// 0x20
};
static_assert(sizeof(TSmallIntList) == 0x24, "TSmallIntList does not have a size of 0x24.");

#pragma pack(pop)
