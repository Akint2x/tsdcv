#pragma once
#include "TEWGraphicButtonWidget.h"
#pragma pack(push, 1)

class TEWRollOverButtonWidget : public TEWGraphicButtonWidget
{
public:
	static constexpr std::string_view NAME = "TEWRollOverButtonWidget";

private:
	char pad[0x104 - 0xDC]; // 0xDC
};
static_assert(sizeof(TEWRollOverButtonWidget) == 0x104, "TEWRollOverButtonWidget does not have a size of 0x104.");

#pragma pack(pop)
