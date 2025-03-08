#pragma once
#include "TEWCustomFormWidget.h"
#pragma pack(push, 1)

class TEWLabels;

class TNTCustomMessageCoreWidget : public TEWCustomFormWidget
{
public:
	static constexpr std::string_view NAME = "TNTCustomMessageCoreWidget";

protected:
	char unknown20[4];			// 0xBC
	char* textDisplayed;		// 0xC0 Delphi string ref counted
	char unknown21[4];			// 0xC4
	TEWLabels* labels;			// 0xC8
	TEWLabels* labels2;			// 0xCC
	char unknown22[4];			// 0xCC
};
static_assert(sizeof(TNTCustomMessageCoreWidget) == 0xD4, "TNTCustomMessageCoreWidget does not have a size of 0xD4");

#pragma pack(pop)