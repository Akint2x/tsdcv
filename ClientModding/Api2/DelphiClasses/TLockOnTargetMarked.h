#pragma once
#include "TLockOnTargetMarkedCore.h"
#pragma pack(push, 1)

class TLockOnTargetMarked : public TLockOnTargetMarkedCore
{
public:

protected:
	char unknown11[4];			// 0x44
	int32_t timestamp2;			// 0x48
	char unknown12[8];			// 0x4C
};
static_assert(sizeof(TLockOnTargetMarked) == 0x54, "TLockOnTargetMarked does not have a size of 0x54.");

#pragma pack(pop)
