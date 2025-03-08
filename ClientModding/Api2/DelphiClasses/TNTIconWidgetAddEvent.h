#pragma once
#include "TNTIconWidget.h"
#pragma pack(push, 1)

class TNTIconWidgetAddEvent : public TNTIconWidget
{
public:
	static constexpr std::string_view NAME = "TNTIconWidgetAddEvent";

protected:
	char unknown22[20];			//0xCC
	Callback unknownCallback;	//0xE0
};
static_assert(sizeof(TNTIconWidgetAddEvent) == 0xE8, "TNTIconWidgetAddEvent does not have a size of 0xE8.");

#pragma pack(pop)