#pragma once
#include "TLBSBkFxItem.h"
#pragma pack(push, 1)

class TMapNpcObj;
class TMapPlayerObj;

class TLockOnTargetMarkedCore : public TLBSBkFxItem
{
public:

protected:
	char unknown9[4];		// 0x30
	TMapNpcObj* target;		// 0x34 Most probably the parent (TMapMovObj or something like that) but not tested
	bool active;			// 0x38
	char unknown10[3];		// 0x39 prob padding
	float targetHeight;		// 0x3C Used to display the arrow above the character, regardless of his size, as it is stored there
	TMapPlayerObj* player;	// 0x40 Pointer to the character you are controlling
};
static_assert(sizeof(TLockOnTargetMarkedCore) == 0x44, "TLockOnTargetMarkedCore does not have a size of 0x44.");

#pragma pack(pop)
