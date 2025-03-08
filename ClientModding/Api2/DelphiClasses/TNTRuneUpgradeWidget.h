#pragma once
#include "TEWCustomFormWidget.h"
#include "../Properties/Graphical/TextStyle.h"
#include "../Properties/Graphical/TextPosition.h"
#include "../../Utils/WStringConvertor.h"
#include "../../Utils/Split.h"
#pragma pack(push, 1)

class TEWLabel;
class TNTIconWidget;
class TEWGraphicButtonWidget;
class TEWCustomPanelWidget;
class TNTIconWidget;
class TEWControlWidgetEX;
class TNTItemList;

class TNTRuneUpgradeWidget : public TEWCustomFormWidget
{
public:
	static constexpr std::string_view NAME = "TNTRuneUpgradeWidget";

	[[nodiscard]] TNTIconWidget* getCurrentIcon() { return iconSelectedItem; }

	TEWLabel* getSuccessRate() noexcept { return successRate; }
	TEWLabel* getFailRate() noexcept { return failRate; }
	TEWLabel* getDamageRate() noexcept { return damageRate; }

	TEWLabel* getFirstQuantity() noexcept { return firstQuantity; }
	TEWLabel* getSecondQuantity() noexcept { return secondQuantity; }
	TEWLabel* getThirdQuantity() noexcept { return thirdQuantity; }
	TEWLabel* getFourthQuantity() noexcept { return fourthQuantity; }
	TEWLabel* getFifthQuantity() noexcept { return fifthQuantity; }
	TEWLabel* getSixthQuantity() noexcept { return sixthQuantity; }

	std::vector<TEWLabel*> getAllQuantities() noexcept
	{
		std::vector<TEWLabel*> output{ firstQuantity, secondQuantity, thirdQuantity, fourthQuantity, fifthQuantity, sixthQuantity };
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
		std::vector<TNTIconWidget*> output{ firstIcon, secondIcon, thirdIcon, fourthIcon, fifthIcon, sixthIcon };
		return output;
	}

	void setSelectedItemIcon(TNTIconWidget* icon) noexcept { iconSelectedItem = icon; }

	TEWLabel* getItemNameLabel() noexcept { return nameUpgradeSelectedItem; }

	bool shouldBlockDrop() { return isActionBlocked && isActionBlocked2; }

protected:
	char unknown22[4];							//0xBC
	TEWLabel* title;							//0xC0
	TEWGraphicButtonWidget* helpButton;			//0xC4
	TEWGraphicButtonWidget* closeButton;		//0xC8
	TEWCustomPanelWidget* unknownPanel;			//0xCC
	TNTIconWidget* iconSelectedItem;			//0xD0
	TEWLabel* nameUpgradeSelectedItem;			//0xD4
	TEWLabel* successRate;						//0xD8
	TEWLabel* damageRate;						//0xDC
	TEWLabel* failRate;							//0xE0
	TEWControlWidgetEX* plusIcon;				//0xE4
	TNTIconWidget* firstIcon;					//0xE8
	TNTIconWidget* secondIcon;					//0xEC
	TNTIconWidget* thirdIcon;					//0xF0
	TNTIconWidget* fourthIcon;					//0xF4
	TNTIconWidget* fifthIcon;					//0xF8
	TNTIconWidget* sixthIcon;					//0xFC
	TNTIconWidget* firstUselessIcon;			//0x100
	TNTIconWidget* secondUselessIcon;			//0x104
	TEWLabel* firstAsk;							//0x108
	TEWLabel* secondAsk;						//0x10C
	TEWLabel* thirdAsk;							//0x110
	TEWLabel* fourthAsk;						//0x114
	TEWLabel* fifthAsk;							//0x118
	TEWLabel* sixthAsk;							//0x11C
	TEWLabel* firstUselessAsk;					//0x120
	TEWLabel* secondUselessAsk;					//0x124
	TEWLabel* firstQuantity;					//0x128
	TEWLabel* secondQuantity;					//0x12C
	TEWLabel* thirdQuantity;					//0x130
	TEWLabel* fourthQuantity;					//0x134
	TEWLabel* fifthQuantity;					//0x138
	TEWLabel* sixthQuantity;					//0x13C
	TEWLabel* firstUselessQuantity;				//0x140
	TEWLabel* secondUselessQuantity;			//0x144
	TNTItemList* itemList;						//0x148
	TEWGraphicButtonWidget* upgradeButton;		//0x14C
	TEWLabel* upgradeButtonText;				//0x150
	TEWGraphicButtonWidget* removeRunicButton;	//0x154
	TEWLabel* removeRunicButtonText;			//0x158
	char unknown23[4];							//0x15C
	bool isEnoughtIngredients;					//0x160
	bool isActionBlocked;						//0x161
	bool isActionBlocked2;						//0x162
	bool isRemoveLastClicked;					//0x163
	int16_t goldRequired;						//0x164
	char unknown25[26];							//0x166
	uint32_t goldAmount;						//0x180
	bool unknown26;								//0x184
	char unknown27[7];							//0x185
};
static_assert(sizeof(TNTRuneUpgradeWidget) == 0x18C, "TNTRuneUpgradeWidget does not have a size of 0x18C.");

#pragma pack(pop)