#pragma once
#include "TObject.h"
#pragma pack(push, 1)

class TLBSMultiTextureList;
template<typename T> class TList;

class TLBSMultiTextureCache : public TObject
{
public:

protected:
	char unknown1[4];						// 0x04
	char unknown2[4];						// 0x08
	TLBSMultiTextureList* unknown3;	// 0x0C
	TLBSMultiTextureList* unknown4;	// 0x10
	TList<void*>* unknown5;					// 0x14
};
static_assert(sizeof(TLBSMultiTextureCache) == 0x18, "TLBSMultiTextureCache does not have a size of 0x18.");

#pragma pack(pop)
