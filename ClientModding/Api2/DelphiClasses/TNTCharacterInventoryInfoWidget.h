#pragma once
#include "TEWCustomFormWidget.h"
#pragma pack(push, 1)

class TNTItemList;
class TNTIconWidget;
class TEWLabel;
class TEWRollOverButtonWidget;
class TEWGraphicButtonWidget;
class TEWScrollBar;
class TEWCustomPanelWidget;
class TNTNewCharacterStandardInfoWidget;

class TNTCharacterInventoryInfoWidget : public TEWCustomFormWidget
{
public:
	static constexpr std::string_view NAME = "TNTCharacterInventoryInfoWidget";

	TNTItemList* getEquipItemList() { return equipItemList; }
	TNTItemList* getMainItemList() { return mainItemList; }
	TNTItemList* getEtcItemList() { return etcItemList; }

	TEWRollOverButtonWidget* getSortBtn() { return sortBtn; }
	TNTIconWidget** getIcons() { return icon; }

	uint8_t getIndexTab() { return indexTab; }
	uint8_t getIndexEquip() { return equipScrollBarIndex; }
	uint8_t getIndexMain() { return mainScrollBarIndex; }
	uint8_t getIndexEtc() { return etcScrollBarIndex; }

	uint32_t getGoldAmount() noexcept { return goldAmount; }

protected:
	char unknown22[4];												//0xBC
	uint8_t nbItemChangedByScrollStep;								//0xC0
	uint8_t unknown23;												//0xC1
	uint8_t nbTotalItemByScrollStep;								//0xC2
	uint8_t unknown24;												//0xC3
	char unknown25[36];												//0xC4
	TNTIconWidget *icon[60];										//0xE8
	TEWLabel* equipTabLabel;										//0x1D8
	TEWLabel* mainTabLabel;											//0x1DC
	TEWLabel* etcTabLabel;											//0x1E0
	TEWLabel* additionalTabLabel;									//0x1E4
	TEWRollOverButtonWidget* additionalBtn;							//0x1E8
	TEWRollOverButtonWidget* fishBtn;								//0x1EC
	TEWGraphicButtonWidget* equipBtn;								//0x1F0
	TEWGraphicButtonWidget* mainBtn;								//0x1F4
	TEWGraphicButtonWidget* etcBtn;									//0x1F8
	TEWScrollBar* scrollBar;										//0x1FC
	int8_t equipNumberBaseItem;										//0x200
	int8_t mainNumberBaseItem;										//0x201
	int8_t etcNumberBaseItem;										//0x202
	uint8_t equipScrollBarIndex;									//0x203
	uint8_t mainScrollBarIndex;										//0x204
	uint8_t etcScrollBarIndex;										//0x205
	char unknown27[2];												//0x206
	TEWRollOverButtonWidget* sortBtn;								//0x208
	TEWCustomPanelWidget* strangePanel;								//0x20D
	TEWLabel* unknownLabel;											//0x210
	uint8_t indexTab;												//0x214
	char unknown28[7];												//0x215
	TNTItemList* equipItemList;										//0x21C
	TNTItemList* mainItemList;										//0x220
	TNTItemList* etcItemList;										//0x224
	int8_t unknown29; 												//0x228 If 0 => can't wear sp	
	char unknown30[7];												//0x229
	uint8_t classType;												//0x230
	char unknown31[3];												//0x231
	uint32_t goldAmount;											//0x234
	char unknown32[12];												//0x231
	void* deleteBtn;												//0x244 TNTIconWidgetAddEvent
	void* cardInventoryWidget;										//0x248 TNTCardInventoryInfoWidget
	void* costumeInventoryWidget;									//0x24C TNTCostumeInventoryInfoWidget
	void* fishWidget;												//0x250 TNTFishInfoWidget
	TNTNewCharacterStandardInfoWidget* characterInfoWidget;			//0x254
	char unknown33[4];												//0X258
};
static_assert(sizeof(TNTCharacterInventoryInfoWidget) == 0x25C, "TNTCharacterInventoryInfoWidget does not have a size of 0x25C.");

#pragma pack(pop)