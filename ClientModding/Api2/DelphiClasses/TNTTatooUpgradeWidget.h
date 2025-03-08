#pragma once
#include "TEWCustomFormWidget.h"
#include "../Properties/Graphical/TextStyle.h"
#include "../Properties/Graphical/TextPosition.h"
#include "../../Utils/WStringConvertor.h"
#include "../../Utils/Split.h"
#include "../../Utils/PrettyPrintQuantity.h"
#pragma pack(push, 1)

class TEWLabel;
class TNTIconWidget;
class TEWGraphicButtonWidget;
class TEWControlWidgetEX;
class TNTItemList;

class TNTTatooUpgradeWidget : public TEWCustomFormWidget
{
public:
	static constexpr std::string_view NAME = "TNTTatooUpgradeWidget";


	[[nodiscard]] TNTIconWidget* getCurrentIcon() { return iconSelectedTattoo; }

	TEWLabel* getSuccessRate() noexcept { return successRate; }
	TEWLabel* getFailRate() noexcept { return failRate; }
	TEWLabel* getMajorFailRate() noexcept { return majorFailRate; }

	TEWLabel* getFirstQuantity() noexcept { return firstQuantity; }
	TEWLabel* getSecondQuantity() noexcept { return secondQuantity; }
	TEWLabel* getThirdQuantity() noexcept { return thirdQuantity; }
	TEWLabel* getFourthQuantity() noexcept { return fourthQuantity; }
	TEWLabel* getFifthQuantity() noexcept { return fifthQuantity; }
	TEWLabel* getSixthQuantity() noexcept { return sixthQuantity; }

	std::vector<TEWLabel*> getAllQuantities() noexcept 
	{ 
		std::vector<TEWLabel*> output { firstQuantity, secondQuantity, thirdQuantity, fourthQuantity, fifthQuantity, sixthQuantity  };
		return output;
	}

	TEWLabel* getFirstAsk() noexcept { return firstAsk; }
	TEWLabel* getSecondAsk() noexcept { return secondAsk; }
	TEWLabel* getThirdAsk() noexcept { return thirdAsk; }
	TEWLabel* getFourthAsk() noexcept { return fourthAsk; }
	TEWLabel* getFifthAsk() noexcept { return fifthAsk; }
	TEWLabel* getSixthAsk() noexcept { return sixthAsk; }

	std::vector<TEWLabel*> getAllAsks() noexcept
	{
		std::vector<TEWLabel*> output{ firstAsk, secondAsk, thirdAsk, fourthAsk, fifthAsk, sixthAsk };
		return output;
	}

	TNTIconWidget* getFirstIcon() noexcept { return firstIcon; }
	TNTIconWidget* getSecondIcon() noexcept { return secondIcon; }
	TNTIconWidget* getThirdIcon() noexcept { return thirdIcon; }
	TNTIconWidget* getFourthIcon() noexcept { return fourthIcon; }
	TNTIconWidget* getFifthIcon() noexcept { return fifthIcon; }
	TNTIconWidget* getSixthIcon() noexcept { return sixthIcon; }

	std::vector<TNTIconWidget*> getAllIcons() noexcept
	{
		std::vector<TNTIconWidget*> output { firstIcon, secondIcon, thirdIcon, fourthIcon, fifthIcon, sixthIcon };
		return output;
	}

	void setSelectedTattooIcon(TNTIconWidget* icon) noexcept { iconSelectedTattoo = icon; }

	TEWLabel* getTattooNameLabel() noexcept { return nameUpgradeSelectedTattoo; }

	bool shouldBlockDrop() { return isActionBlocked && isActionBlocked2; }

protected:
	char unknown22[4];							//0xBC
	TEWLabel* title;							//0xC0
	TEWGraphicButtonWidget* helpButton;			//0xC4
	TEWGraphicButtonWidget* closeButton;		//0xC8
	TNTIconWidget* iconSelectedTattoo;			//0xCC
	TEWLabel* nameUpgradeSelectedTattoo;		//0xD0
	TEWLabel* successRate;						//0xD4
	TEWLabel* majorFailRate;					//0xD8
	TEWLabel* failRate;							//0xDC
	TEWControlWidgetEX* plusIcon;				//0xE0
	TNTIconWidget* firstIcon;					//0xE4
	TNTIconWidget* secondIcon;					//0xE8
	TNTIconWidget* thirdIcon;					//0xEC
	TNTIconWidget* fourthIcon;					//0xF0
	TNTIconWidget* fifthIcon;					//0xF4
	TNTIconWidget* sixthIcon;					//0xF8
	TNTItemList* itemList;						//0xFC
	TEWLabel* firstAsk;							//0x100
	TEWLabel* secondAsk;						//0x104
	TEWLabel* thirdAsk;							//0x108
	TEWLabel* fourthAsk;						//0x10C
	TEWLabel* fifthAsk;							//0x110
	TEWLabel* sixthAsk;							//0x114
	TEWLabel* firstQuantity;					//0x118
	TEWLabel* secondQuantity;					//0x11C
	TEWLabel* thirdQuantity;					//0x120
	TEWLabel* fourthQuantity;					//0x124
	TEWLabel* fifthQuantity;					//0x128
	TEWLabel* sixthQuantity;					//0x12C
	TEWGraphicButtonWidget* upgradeButton;		//0x130
	TEWLabel* upgradeButtonText;				//0x134
	TEWGraphicButtonWidget* removeTatooButton;	//0x138
	TEWLabel* removeTatooButtonText;			//0x13C
	char unknown23;								// 0x140
	bool isActionBlocked;						// 0x141
	bool isActionBlocked2;						// 0x142
	char unknown24;								//0x143
	char unknown25[4];							//0x144
	char unknown26[28];							//0x148
};
static_assert(sizeof(TNTTatooUpgradeWidget) == 0x164, "TNTTatooUpgradeWidget does not have a size of 0x164.");

#pragma pack(pop)
