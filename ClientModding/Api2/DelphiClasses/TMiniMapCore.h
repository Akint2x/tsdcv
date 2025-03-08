#pragma once
#include "TEWControlWidget.h"
#pragma pack(push, 1)

class TMiniMapCore : public TEWControlWidget
{
public:
	static constexpr std::string_view NAME = "TMiniMapCore";

protected:
	char unknown12[16];							//0x68
};
static_assert(sizeof(TMiniMapCore) == 0x78, "TMiniMapCore does not have a size of 0x78.");

#pragma pack(pop)