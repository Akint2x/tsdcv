#pragma once
#include "TEWLabels.h"
#pragma pack(push, 1)

class TNTHintWidget : public TEWLabels
{
public:
	static constexpr std::string_view NAME = "TNTHintWidget";

private:
	char unknown15[24];
};
static_assert(sizeof(TNTHintWidget) == 0xA0, "TNTHintWidget does not have a size of 0xA0.");

#pragma pack(pop)