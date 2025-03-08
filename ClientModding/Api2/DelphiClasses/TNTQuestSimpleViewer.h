#pragma once
#include "TEWMoveWidget.h"
#pragma pack(push, 1)

class TEWGraphicButtonWidget;
class TEWCustomPanelWidget;
class TEWStringListView;
class TEWControlWidgetEX;

class TNTQuestSimpleViewer : public TEWMoveWidget
{
public:
	static constexpr std::string_view NAME = "TNTQuestSimpleViewer";

protected:
	TEWGraphicButtonWidget* collapseBtn;							//0x80
	TEWGraphicButtonWidget* openQuestsBtn;							//0x84
	TEWCustomPanelWidget* innerPanel;								//0x88	
	TEWGraphicButtonWidget* collapseQuestDetailsBtn;				//0x8C
	TEWStringListView* innerPanelText;								//0x90
	TEWStringListView* unknownText;									//0x94
	TEWControlWidgetEX* questMarker;								//0x98
	TEWCustomPanelWidget* unknownPanels[8];							//0x9C
	TEWGraphicButtonWidget* secondCollapseQuestDetailsBtn;			//0xBC
	TEWGraphicButtonWidget* unknownBtns[7];							//0xC0
	TEWStringListView* unknownTexts[16];							//0xDC
	TEWControlWidgetEX* unknownControlWidgets[8];					//0x11C
	TEWCustomPanelWidget* unknownPanels2[5];						//0x13C
	TEWGraphicButtonWidget* unknownBtns2[5];						//0x150
	TEWStringListView* unknownBtns2[10];							//0x164
	bool isInnerPanelOpen;											//0x18C
	char unknown14[3];												//0x18D
	int16_t innerPanelHeight;										//0x190
	char unknown15[26];												//0x192
};
static_assert(sizeof(TNTQuestSimpleViewer) == 0x1AC, "TNTQuestSimpleViewer does not have a size of 0x1AC");

#pragma pack(pop)