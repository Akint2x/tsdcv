#pragma once
#include "TEWStringListView.h"
#pragma pack(push, 1)

class TEWListView : public TEWStringListView
{
public:
	static constexpr std::string_view NAME = "TEWListView";

protected:
	char unknown15[0xC8 - 0xB0];
};
static_assert(sizeof(TEWListView) == 0xC8, "TEWListView does not have a size of 0xC8.");

#pragma pack(pop)