#pragma once
#include "TEWCustomFormWidget.h"
#pragma pack(push, 1)

/* TODO :
* Find unknowns
*/

class TNTSpecialCardPlusWidget : public TEWCustomFormWidget
{
public:
	static constexpr std::string_view NAME = "TNTSpecialCardPlusWidget";

	TNTSpecialCardPlusWidget(TLBSWidget* Parent, Border Border, ImageData ImageData, ImagePadding ImagePadding)
		: TEWCustomFormWidget(ClassSearcher::GetClassInfoFromName("TNTSpecialCardPlusWidget").GetVTable()
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

		spIcon = new TNTIconWidget();
		spIcon->setIconProperties(new IconProperties());

		goldIcon = new TNTIconWidget();
		goldIcon->setIconProperties(new IconProperties());

		jewelIcon = new TNTIconWidget();
		jewelIcon->setIconProperties(new IconProperties());

		goldQuantityLabel = new TEWLabel();
		jewelQuantityLabel = new TEWLabel();
	}

protected:
	char unknown21[4];						//0xBC
	TEWLabel* title;						//0xC0
	TEWGraphicButtonWidget* helpBtn;		//0xC4
	TEWGraphicButtonWidget* closeBtn;		//0xC8
	TEWCustomPanelWidget* bgPanel;			//0xCC
	TNTIconWidget* spIcon;					//0xD0
	TEWLabel* cardLabel;					//0xD4
	TEWControlWidgetEX* plusIcon;			//0xD8
	TNTIconWidget* goldIcon;				//0xDC
	TNTIconWidget* jewelIcon;				//0xE0
	TNTItemList* itemList;					//0xE4
	TEWLabel* goldDemandLabel;				//0xE8
	TEWLabel* jewelDemandLabel;				//0xEC
	TEWLabel* goldQuantityLabel;			//0xF0
	TEWLabel* jewelQuantityLabel;			//0xF4
	TEWGraphicButtonWidget* upgradeBtn;		//0xF8
	TEWLabel* upgradeBtnLabel;				//0xFC
	char unknown22[4];						//0x100
	uint32_t goldQuantity;					//0x104
	uint32_t jewelQuantity;					//0x108
	uint32_t jewelIconId;					//0x10C
	uint32_t currentGoldAmount;				//0x110
};
static_assert(sizeof(TNTSpecialCardPlusWidget) == 0x114, "TNTSpecialCardPlusWidget does not have a size of 0x114.");

#pragma pack(pop)
