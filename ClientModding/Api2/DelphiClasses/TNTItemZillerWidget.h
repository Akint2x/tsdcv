#pragma once
#include "TEWCustomFormWidget.h"
#include "TEWLabels.h"
#pragma pack(push, 1)

/* TODO :
* Find unknowns
*/

class TNTItemZillerWidget : public TEWCustomFormWidget
{
public:
	static constexpr std::string_view NAME = "TNTItemZillerWidget";

	TNTItemZillerWidget(TLBSWidget* Parent, Border Border, ImageData ImageData, ImagePadding ImagePadding)
		: TEWCustomFormWidget(ClassSearcher::GetClassInfoFromName("TNTItemZillerWidget").GetVTable()
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
		for (int i = 0; i < 6; i++)
		{
			allLabels->addTextPosition(TextPosition());
			allLabels->addTextStyle(TextStyle());
		}

		eqIcon = new TNTIconWidget();
		eqIcon->setIconProperties(new IconProperties());

		goldIcon = new TNTIconWidget();
		goldIcon->setIconProperties(new IconProperties());

		cellaIcon = new TNTIconWidget();
		cellaIcon->setIconProperties(new IconProperties());
	}

protected:
	char unknown21[4];						//0xBC
	TEWLabels* allLabels;					//0xC0
	TNTIconWidget* eqIcon;					//0xC4
	TNTIconWidget* goldIcon;				//0xC8
	TNTIconWidget* cellaIcon;				//0xCC
	char unknown22[8];						//0xD0
	ItemDataProperties* eqItem;				//0xD8
	char unknown23[32];						//0xDC
	void* unknown24;						//0xFC
	char unknown25[24];						//0x100
	ItemDataProperties* goldItem;			//0x118
	uint16_t goldItemId;					//0x11C
	char unknown26[58];						//0x11E
	ItemDataProperties* cellaItem;			//0x158
	uint16_t cellaItemId;					//0x15C
	char unknown27[50];						//0x15E
	TEWGraphicButtonWidget* betBtn;			//0x190
	uint32_t currentGoldAmount;				//0x194
	char unknown29[4];						//0x198
};
static_assert(sizeof(TNTItemZillerWidget) == 0x19C, "TNTItemZillerWidget does not have a size of 0x19C.");

#pragma pack(pop)
