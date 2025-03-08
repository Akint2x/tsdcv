#pragma once
#include "TEWCustomPanelWidget.h"
#pragma pack(push, 1)

class TEWRollOverButtonWidget;
class TEWStringListView;

class TNTBottomMainUIWidget : public TEWCustomPanelWidget
{
public:
	static constexpr std::string_view NAME = "TNTBottomMainUIWidget";

	TEWRollOverButtonWidget* getNosmallBtn() { return nosmallBtn; }

protected:
	char unknown19[4];									//0xA4
	void* cexpGauge;									//0xA8 TNTPlayerCExpGaugeWidget
	void* tray;											//0xAC TNTTrayWidget
	TEWRollOverButtonWidget* optionsBtn;			//0xB0
	TEWRollOverButtonWidget* secondOptionsBtn;	//0xB4
	TEWRollOverButtonWidget* nosmallBtn;			//0xB8
	TEWRollOverButtonWidget* eventBtn;			//0xBC
	TEWRollOverButtonWidget* battlePassBtn;		//0xC0
	TEWCustomPanelWidget* oldPanel;						//0xC4 Old panel unused now
	TEWStringListView* text;						//0xC8 Text for strange panel
	char unknown20[80];									//0xCC
};
static_assert(sizeof(TNTBottomMainUIWidget) == 0x11C, "TNTBottomMainUIWidget does not have a size of 0x11C.");

#pragma pack(pop)