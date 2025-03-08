#pragma once
#include "TEWCustomFormWidget.h"
#pragma pack(push, 1)

class TEWControlWidgetEX;
class TNTItemList;
class TEWRollOverButtonWidget;
class TEWLabel;
class TEWTextOutLabel;
class TEWStringListView;
class TNTIconViewer;
class TNTIconWidgetAddEvent;

class TNTSpecialaListInfoWidget /* Yes, they really typo-ed there. */ : public TEWCustomFormWidget
{
public:
	static constexpr std::string_view NAME = "TNTSpecialaListInfoWidget";

protected:
	char unknown20[4];												//0x0BC
	TEWControlWidgetEX* leftCornerImg;								//0x0C0
	TNTIconWidget* skills[10];										//0x0C4
	TNTItemList* itemList;											//0x0EC
	TNTIconWidget* iconBeforeWingSwapper;							//0x0F0
	int8_t unknown21;												//0x0F4
	char unknown22[15];												//0x0F5
	TEWRollOverButtonWidget* wingSwapperBtn;						//0x104
	TEWLabel* unknownLabel;											//0x108
	TEWLabel* unknownLabel2;										//0x10C
	TEWLabel* unknownLabel3;										//0x110
	TEWCustomPanelWidget* strangePanel;								//0x114
	TNTItemList* skillsList;										//0x118
	TEWTextOutLabel* levelLabel;									//0x11C
	TEWTextOutLabel* expPercentLabel;								//0x120
	TEWTextOutLabel* ptsCountLabel;									//0x124
	TEWTextOutLabel* spNameUpgradeLabel;							//0x128
	TEWTextOutLabel* perfectionLabel;								//0x12C
	TEWGraphicButtonWidget* upgradeBtn;								//0x130
	TEWLabel* spConsumptionLabel;									//0x134
	TEWLabel* repNameMinLabel;										//0x138
	TEWLabel* jobMinLabel;											//0x13C
	TNTItemList* repMinLogo;										//0x140
	TEWLabel* attackPtsLabel;										//0x144
	TEWLabel* defencePtsLabel;										//0x148
	TEWLabel* elementPtsLabel;										//0x14C
	TEWLabel* energyPtsLabel;										//0x150
	TEWLabel* attackPerfLabel;										//0x154
	TEWLabel* defencePerfLabel;										//0x158
	TEWLabel* elementPerfLabel;										//0x15C
	TEWLabel* energyPerfLabel;										//0x160
	TEWLabel* fireResPerfLabel;										//0x164
	TEWLabel* waterResPerfLabel;									//0x168
	TEWLabel* lightResPerfLabel;									//0x16C
	TEWLabel* shadowResPerfLabel;									//0x170
	TEWLabel* fireResPtsLabel;										//0x174
	TEWLabel* waterResPtsLabel;										//0x178
	TEWLabel* lightResPtsLabel;										//0x17C
	TEWLabel* shadowResPtsLabel;									//0x180
	TEWStringListView* descText;									//0x184
	TEWGraphicButtonWidget* descArrowUpBtn;							//0x188
	TEWGraphicButtonWidget* descArrowDownBtn;						//0x18C
	TNTIconViewer* maleSpPreview;									//0x190
	TNTIconViewer* femaleSpPreview;									//0x194
	char unknown23[28];												//0x198
	uint8_t unknown24;												//0x1B4
	bool isUpgradeBtnBlink;											//0x1B5
	char unknown25[0x3C0-0x1B6];									//0x1B6
	TEWCustomPanelWidget* upgradePage;								//0x3C0
	TEWControlWidgetEX* attackBorder;								//0x3C4
	TEWControlWidgetEX* defenceBorder;								//0x3C8
	TEWControlWidgetEX* elementBorder;								//0x3CC
	TEWControlWidgetEX* energyBorder;								//0x3D0
	TNTIconWidgetAddEvent* attackIcon;								//0x3D4
	TNTIconWidgetAddEvent* defenceIcon;								//0x3D8
	TNTIconWidgetAddEvent* elementIcon;								//0x3DC
	TNTIconWidgetAddEvent* energyIcon;								//0x3E0
	TEWCustomPanelWidget* attackBg;									//0x3E4
	TEWCustomPanelWidget* defenceBg;								//0x3E8
	TEWCustomPanelWidget* elementBg;								//0x3EC
	TEWCustomPanelWidget* energyBg;									//0x3F0
	TEWGraphicButtonWidget* attackArrowUpBtn;						//0x3F4
	TEWGraphicButtonWidget* attackArrowDownBtn;						//0x3F8
	TEWGraphicButtonWidget* defenceArrowUpBtn;						//0x3FC
	TEWGraphicButtonWidget* defenceArrowDownBtn;					//0x400
	TEWGraphicButtonWidget* elementArrowDownBtn;					//0x404
	TEWGraphicButtonWidget* elementArrowUpBtn;						//0x408
	TEWGraphicButtonWidget* energyArrowUpBtn;						//0x40C
	TEWGraphicButtonWidget* energyArrowDownBtn;						//0x410
	TEWCustomPanelWidget* unknown26;								//0x414
	TEWCustomPanelWidget* unknown27;								//0x418
	TEWCustomPanelWidget* unknown28;								//0x41C
	TEWCustomPanelWidget* unknown29;								//0x420
	TEWCustomPanelWidget* unknown30;								//0x424
	TEWCustomPanelWidget* unknown31;								//0x428
	TEWCustomPanelWidget* unknown32;								//0x42C
	TEWCustomPanelWidget* unknown33;								//0x430
	TEWLabel* attackPtsLabel2;										//0x434
	TEWLabel* defencePtsLabel2;										//0x438
	TEWLabel* elementPtsLabel2;										//0x43C
	TEWLabel* energyPtsLabel2;										//0x440
	TEWLabel* attackToAddLabel;										//0x444
	TEWLabel* defenceToAddLabel;									//0x448
	TEWLabel* elementToAddLabel;									//0x44C
	TEWLabel* energyToAddLabel;										//0x450
	TEWLabel* attackPtsConsumptionLabel;							//0x454
	TEWLabel* defencePtsConsumptionLabel;							//0x458
	TEWLabel* elementPtsConsumptionLabel;							//0x45C
	TEWLabel* energyPtsConsumptionLabel;							//0x460
	TEWLabel* attackSectionLabel;									//0x464
	TEWLabel* defenceSectionLabel;									//0x468
	TEWLabel* elementSectionLabel;									//0x46C
	TEWLabel* energySectionLabel;									//0x470
	TEWLabel* attackBonusToAddLabel;								//0x474
	TEWLabel* defenceBonusToAddLabel;								//0x478
	TEWLabel* elementBonusToAddLabel;								//0x47C
	TEWLabel* energyBonusToAddLabel;								//0x480
	TEWLabel* energyPercentLabel;									//0x484
	TEWCustomPanelWidget* ptsBg;									//0x488
	TEWLabel* ptsSectionLabel;										//0x48C
	TEWLabel* ptsCountLabel2;										//0x490
	TEWLabel* bonusAbilitiesSectionLabel;							//0x494
	TEWCustomPanelWidget* bonusAbilitiesDescBg;						//0x498
	TEWStringListView* bonusAbilitiesDescText;						//0x49C
	TEWGraphicButtonWidget* bonusAbilitiesDescArrowUpBtn;			//0x4A0
	TEWGraphicButtonWidget* bonusAbilitiesDescArrowDownBtn;			//0x4A4
	TEWGraphicButtonWidget* decisionBtn;							//0x4A8
	TEWGraphicButtonWidget* cancelBtn;								//0x4AC
	TEWGraphicButtonWidget* initBtn;								//0x4B0
	TEWGraphicButtonWidget* closeBtn;								//0x4B4
	TEWLabel* decisionBtnLabel;										//0x4B8
	TEWLabel* cancelBtnLabel;										//0x4BC
	TEWLabel* initBtnLabel;											//0x4C0
	TEWLabel* closeBtnLabel;										//0x4C4
	char unknown34[20];												//0x4C8
};
static_assert(sizeof(TNTSpecialaListInfoWidget) == 0x04DC, "TNTSpecialaListInfoWidget does not have a size of 0x04DC.");

#pragma pack(pop)
