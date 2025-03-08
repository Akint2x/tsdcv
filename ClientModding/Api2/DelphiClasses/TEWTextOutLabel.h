#pragma once
#include "TEWTextOut.h"
#pragma pack(push, 1)

class TEWTextOutLabel : public TEWTextOut
{
public:
	static constexpr std::string_view NAME = "TEWTextOutLabel";

protected:
	char* text;
	char unknown17[16];
};
static_assert(sizeof(TEWTextOutLabel) == 0x8C, "TEWTextOutLabel does not have a size of 0x8C.");

#pragma pack(pop)
