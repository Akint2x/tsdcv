#pragma once
#include "TList.h"
#pragma pack(push, 1)

class TLBSMultiTextureList : public TList<void*> // Not enough data to understand this structure
{
public:

protected:
};
static_assert(sizeof(TLBSMultiTextureList) == 0x10, "TLBSMultiTextureList does not have a size of 0x10.");

#pragma pack(pop)
