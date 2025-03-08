#pragma once
#include "TPersistent.h"
#pragma pack(push, 1)

class TStrings : public TPersistent
{
public:

protected:
	uint8_t pad_0004[12]; // 0x04
};
static_assert(sizeof(TStrings) == 0x10, "TStrings does not have a size of 0x10.");

#pragma pack(pop)
