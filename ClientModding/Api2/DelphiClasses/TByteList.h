#pragma once
#include "TBaseList.h"
#pragma pack(push, 1)

class TByteList : public TBaseList<uint8_t>
{
public:

private:
	char unknown2[4];	// 0x20
};
static_assert(sizeof(TByteList) == 0x24, "TByteList does not have a size of 0x24.");

#pragma pack(pop)
