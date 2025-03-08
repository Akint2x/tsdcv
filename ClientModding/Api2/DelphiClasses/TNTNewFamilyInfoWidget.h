#pragma once
#include "TEWCustomPanelWidget.h"
#pragma pack(push, 1)

class TNTNewFamilyInfoWidget : public TEWCustomPanelWidget
{
public: // TODO make private
	static constexpr std::string_view NAME = "TNTNewFamilyInfoWidget";

	char pad_00A4[316]; //0x00A4
};
static_assert(sizeof(TNTNewFamilyInfoWidget) == 0x1E0, "TNTNewFamilyInfoWidget does not have a size of 0x1E0");

#pragma pack(pop)