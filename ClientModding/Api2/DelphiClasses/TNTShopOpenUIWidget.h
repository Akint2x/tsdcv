#pragma once
#include "TEWCustomPanelWidget.h"
#pragma pack(push, 1)

class TEWRollOverButtonWidget;
class TEWLabel;

class TNTShopOpenUIWidget : public TEWCustomPanelWidget
{
public:
	static constexpr std::string_view NAME = "TNTShopOpenUIWidget";

protected:
	char unknown19[4];						//0xA4
	TEWRollOverButtonWidget* tabBtn[6];		//0xA8
	TEWCustomPanelWidget* hintWidget;		//0xBC
	TEWLabel* hintLabel;					//0xC0
	int32_t unknown20;						//0xC4
	int32_t unknown21;						//0xC8
	int32_t tabId;							//0xD0
};
static_assert(sizeof(TNTShopOpenUIWidget) == 0xD4, "TNTShopOpenUIWidget does not have a size of 0xD4.");

#pragma pack(pop)