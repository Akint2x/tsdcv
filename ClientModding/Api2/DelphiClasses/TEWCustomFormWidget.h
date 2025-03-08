#pragma once
#include "TEWCustomPanelWidget.h"
#pragma pack(push, 1)

/* TODO :
* Find unknowns
*/

class TEWCaptionBar;

class TEWCustomFormWidget : public TEWCustomPanelWidget
{
public:
	static constexpr std::string_view NAME = "TEWCustomFormWidget";
	TEWCustomFormWidget(uint32_t VTable, int8_t EvenThing, TLBSWidget* Parent, TLBSWidgetList* Childs, Border Border)
		: TEWCustomPanelWidget(VTable, EvenThing, Parent, Childs, Border)
	{}

	TEWCustomFormWidget(TLBSWidget* Parent, Border Border, ImageData ImageData, ImagePadding ImagePadding)
		: TEWCustomPanelWidget(ClassSearcher::GetClassInfoFromName("TEWCustomFormWidget").GetVTable()
			, 0xB, Parent, nullptr, Border)
	{
		imageData = ImageData;
		scrollType = 0x3;
		isHandlingClick = true;
		imagePadding = ImagePadding;
		if (imageData.getNbPictureViews() == 9)
			unknown15 = 0x5;
		else
			unknown15 = 0x2;
	}

	void setIsResizable(bool Val) { isResizable = Val; }
	void setResizeWidth(int8_t Width) { resizeWidth = Width; }
	void setCaptionBar(TEWCaptionBar* CaptionBar) { captionBar = CaptionBar; }
	TEWCaptionBar* getCaptionBar() { return captionBar; }

protected:
	char unknown19[4];					// 0xA4
	TEWCaptionBar* captionBar;			// 0xA8
	bool isResizing;					// 0xAC
	bool isResizable;					// 0xAD
	int8_t resizeWidth;					// 0xAE
	int16_t resizeClickPosXLeft;		// 0xAF
	int16_t resizeClickPosYTop;			// 0xB1
	int16_t resizeClickPosXRight;		// 0xB3
	int16_t resizeClickPosYBot;			// 0xB5
	char unknown20;						// 0xB7 probably padding
	TLBSWidget* blockerWidget;			// 0xB8 this widget avoid clicking on anything else than the messagebox
};
static_assert(sizeof(TEWCustomFormWidget) == 0xBC, "TEWCustomFormWidget does not have a size of 0xBC.");

#pragma pack(pop)
