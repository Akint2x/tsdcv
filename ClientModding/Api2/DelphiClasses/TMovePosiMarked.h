#pragma once
#include "TLBSBkFxItem.h"
#pragma pack(push, 1)

class TMapPlayerObj;

class TMovePosiMarked : public TLBSBkFxItem
{
public:

protected:
	bool active;					// 0x30 if true, is displayed, if false, not displayed
	char unk2[3];					// 0x31 prob padding
	TMapPlayerObj* entity;	// 0x34 It is probably a TMapMoveObjBase but not checked
};
static_assert(sizeof(TMovePosiMarked) == 0x38, "TMovePosiMarked does not have a size of 0x38.");

#pragma pack(pop)
