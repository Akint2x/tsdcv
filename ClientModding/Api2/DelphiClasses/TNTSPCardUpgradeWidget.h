#pragma once
#include "TEWCustomFormWidget.h"
#include "TEWCustomPanelWidget.h"
#include "TEWLabel.h"
#include "TEWGraphicButtonWidget.h"
#include "TNTIconWidget.h"
#include "TNTItemList.h"
#include "TEWControlWidgetEX.h"
#pragma pack(push, 1)

/* TODO :
* Find unknowns
*/

class TNTSPCardUpgradeWidget : public TEWCustomFormWidget
{
public:
	static constexpr std::string_view NAME = "TNTSPCardUpgradeWidget";

	TNTSPCardUpgradeWidget(TLBSWidget* Parent, Border Border, ImageData ImageData, ImagePadding ImagePadding)
		: TEWCustomFormWidget(ClassSearcher::GetClassInfoFromName("TNTSPCardUpgradeWidget").GetVTable()
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

		for (int i = 0; i < 3; i++)
		{
			reqIcon[i] = new TNTIconWidget();
			reqIcon[i]->setIconProperties(new IconProperties());
		}

		goldQuantityLabel = new TEWLabel();
		for (int i = 0; i < 3; i++)
			reqQuantityLabel[i] = new TEWLabel();

		successLabel = new TEWLabel();
		destroyLabel = new TEWLabel();
		failLabel = new TEWLabel();
	}

protected:
	char unknown21[4];						//0xBC
	TEWLabel* title;						//0xC0
	TEWGraphicButtonWidget* helpBtn;		//0xC4
	TEWGraphicButtonWidget* closeBtn;		//0xC8
	TEWCustomPanelWidget* bgPanel;			//0xCC
	TNTIconWidget* spIcon;					//0xD0
	TEWLabel* cardLabel;					//0xD4
	TEWLabel* successLabel;					//0xD8
	TEWLabel* destroyLabel;					//0xDC
	TEWLabel* failLabel;					//0xE0
	TEWControlWidgetEX* plusIcon;			//0xE4
	TNTIconWidget* goldIcon;				//0xE8
	TNTIconWidget* reqIcon[3];				//0xEC
	TNTItemList* itemList;					//0xF0
	TEWLabel* goldDemandLabel;				//0xF4
	TEWLabel* reqDemandLabel[3];			//0x100
	TEWLabel* goldQuantityLabel;			//0x10C
	TEWLabel* reqQuantityLabel[3];			//0x110
	TEWGraphicButtonWidget* upgradeBtn;		//0x11C
	TEWLabel* upgradeBtnLabel;				//0x120
	int8_t unknown22;						//0x124
	int8_t unknown23;						//0x125
	int16_t unknown24;						//0x126
	uint32_t goldQuantity;					//0x128
	uint32_t reqQuantity[3];				//0x12C
	uint32_t thirdReqIconId;				//0x138
	uint32_t currentGoldAmount;				//0x13C
};
static_assert(sizeof(TNTSPCardUpgradeWidget) == 0x140, "TNTSPCardUpgradeWidget does not have a size of 0x140.");

#pragma pack(pop)
