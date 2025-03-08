#pragma once
#include "TObject.h"
#pragma pack(push, 1)

class TNTUnitManager : public TObject
{
public:

protected:
	char unknown1[4];			// 0x04
	bool ce_truc;				// 0x08
	char unknown2[3];			// 0x09 prob padding
	char unknown3[36];			// 0x0C
};
static_assert(sizeof(TNTUnitManager) == 0x30, "TNTUnitManager does not have a size of 0x30.");

#pragma pack(pop)
