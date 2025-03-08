#pragma once
#include "TEWCustomFormWidget.h"
#include "TEWLabels.h"
#pragma pack(push, 1)

/* TODO :
* Find unknowns
*/

class TNTItemUpgradeWidget : public TEWCustomFormWidget
{
public:
	static constexpr std::string_view NAME = "TNTItemUpgradeWidget";

	TNTItemUpgradeWidget(TLBSWidget* Parent, Border Border, ImageData ImageData, ImagePadding ImagePadding)
		: TEWCustomFormWidget(ClassSearcher::GetClassInfoFromName("TNTItemUpgradeWidget").GetVTable()
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

		allLabels = new TEWLabels();
		for (int i = 0; i < 10; i++)
		{
			allLabels->addTextStyle(TextStyle());
			allLabels->addTextPosition(TextPosition(0, 0, 0, 0, nullptr, false));
		}

		eqIcon = new TNTIconWidget();
		eqIcon->setIconProperties(new IconProperties());

		requirementIcons[0] = new TNTIconWidget();
		requirementIcons[0]->setIconProperties(new IconProperties());

		requirementIcons[1] = new TNTIconWidget();
		requirementIcons[1]->setIconProperties(new IconProperties());

		requirementIcons[2] = new TNTIconWidget();
		requirementIcons[2]->setIconProperties(new IconProperties());
	}

protected:
	char unknown21[4];						//0xBC
	TEWLabels* allLabels;					//0xC0
	TNTIconWidget* eqIcon;					//0xC4
	TNTIconWidget* requirementIcons[3];		//0xC8
	char unknown22[8];						//0xD4
	int32_t unknown23;						//0xDC
	ItemDataProperties* eqItem;				//0xE0
	uint16_t eqItemId;						//0xE4
	char unknown24[58];						//0xE6
	ItemDataProperties* firstReqItem;		//0x120
	uint16_t firstReqItemId;				//0x124
	char unknown25[58];						//0x126
	ItemDataProperties* secondReqItem;		//0x160
	uint16_t secondReqItemId;				//0x164
	char unknown26[58];						//0x166
	ItemDataProperties* thirdReqItem;		//0x1A0
	uint16_t thirdReqItemId;				//0x1A4
	char unknown27[50];						//0x1A6
	TEWGraphicButtonWidget* reinforceBtn;	//0x1D8
	char unknown28[4];						//0x1DC
	char unknown29[4];						//0x1E0
};
static_assert(sizeof(TNTItemUpgradeWidget) == 0x1E4, "TNTItemUpgradeWidget does not have a size of 0x1E4.");

#pragma pack(pop)
