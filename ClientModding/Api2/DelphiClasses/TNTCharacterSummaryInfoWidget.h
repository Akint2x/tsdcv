#pragma once
#include "TEWCustomFormWidget.h"
#pragma pack(push, 1)

class TNTCharacterSummaryInfoWidget : public TEWCustomFormWidget
{
public:
	static constexpr std::string_view NAME = "TNTCharacterSummaryInfoWidget";

private:
	char unknown19[0xD0];
};
static_assert(sizeof(TNTCharacterSummaryInfoWidget) == 0x18C, "TNTCharacterSummaryInfoWidget does not have a size of 0x18C.");

#pragma pack(pop)
