#pragma once
#include "TNTCustomMessageCoreWidget.h"
#pragma pack(push, 1)

class TNTCustomMessageWidget : public TNTCustomMessageCoreWidget
{
public:
	static constexpr std::string_view NAME = "TNTCustomMessageWidget";

private:
	char unknown23[4];			// 0xD4
};
static_assert(sizeof(TNTCustomMessageWidget) == 0xD8, "TNTCustomMessageWidget does not have a size of 0xD8");

#pragma pack(pop)