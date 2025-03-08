#pragma once
#include "TEWControlWidgetEX.h"
#pragma pack(push, 1)

class TNTCuttonEffect : public TEWControlWidgetEX
{
public:
	static constexpr std::string_view NAME = "TNTCuttonEffect";

	void setUnknown12(int32_t Value) { unknown12 = Value; }
	void setOpacity(uint8_t Opacity) { opacity = Opacity; }
	void setActive(bool IsActive) { isActive = IsActive; }

protected:
	int32_t unknown12;		// 0x68
	uint8_t opacity;		// 0x6C
	bool isActive;			// 0x6D
	char unknown13;			// 0x6E probably padding (no W/R)
	char unknown14;			// 0x6F probably padding (no W/R)
	int32_t unknown15;		// 0x70 is being compared to unknown12 but with some extra comparison
	int unknown16;			// 0x74 unknown
};
static_assert(sizeof(TNTCuttonEffect) == 0x78, "TNTCuttonEffect does not have a size of 0x78.");

#pragma pack(pop)
