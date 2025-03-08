#pragma once
#include "TEWCustomFormWidget.h"
#include "../../MemoryHelper/Patch.h"
#include "../../MemoryHelper/PatternScan.h"
#include "../Properties/Graphical/IconProperties.h"
#pragma pack(push, 1)

// TODO: Deep reverse
// TODO: Remove this namespace
namespace TNTNewCharacterSkillInfoWidgetInternal
{
	static uintptr_t jmpback;
	static std::map<int32_t, std::function<void()>> skillFuncs;

	static void __stdcall callSkill(void* skillStruct)
	{
		int32_t id = *(int32_t*)skillStruct;
		if (skillFuncs.count(id) == 0)
			return;
		skillFuncs[id]();
	}

	static void __declspec(naked) hk_addMotionSkillEvent() noexcept
	{
		__asm
		{
			push ebp;
			mov ebp, esp;
			push ecx;
			mov ecx, 0x9;

			pushad;
			pushfd;

			push ebx;

			call callSkill;

			popfd;
			popad;

			jmp jmpback;
		}
	}
};

class TNTItemList;
class TEWCustomPanelWidget;
class TEWGraphicButtonWidget;
class TNTTimeAniIcon;
class TEWScrollBar;
class TNTIconWidget;
class TEWStringListView;
class TEWLabel;
class TEWLabels;

class TNTNewCharacterSkillInfoWidget : public TEWCustomFormWidget
{
public:
	static constexpr std::string_view NAME = "TNTNewCharacterSkillInfoWidget";

	TNTItemList* getMotionList() noexcept { return motionList; }
	[[nodiscard]] int32_t getTabIndex() noexcept { return tabIndex; }
	[[nodiscard]] TEWCustomPanelWidget* getTitle() noexcept { return tabTitlePanel; }

	[[nodiscard]] static bool addMotionSkillEvent(int32_t SkillId, std::function<void()> Func)
	{
		static void* patternAddr = nullptr;

		if (patternAddr == nullptr)
		{
			auto _ = Logger::PushPopModuleName(NAME.data());

			patternAddr = PatternScan(
				"\x55\x8b\xec\x51\xb9\x09\x00\x00\x00\x6a\x00\x6a\x00\x49\x75\xf9\x51\x87\x4d\xfc\x53\x56\x8b\xda",
				"xxxxxxxxxxxxxxxxxxxxxxxx", 0
			);
			if (patternAddr == nullptr)
			{
				Logger::Error("Fail scanning pattern");
				return false;
			}
			Logger::Log("patternAddr = %x", patternAddr);

			if (!Hook((BYTE*)patternAddr, (BYTE*)TNTNewCharacterSkillInfoWidgetInternal::hk_addMotionSkillEvent, 9))
			{
				Logger::Error("Fail creating hook");
				return false;
			}
			TNTNewCharacterSkillInfoWidgetInternal::jmpback = ((uintptr_t)patternAddr + 9);

			Logger::Success("Successfully initialized");
		}

		TNTNewCharacterSkillInfoWidgetInternal::skillFuncs.emplace(SkillId, Func);

		return true;
	}

	char unknown22[4];									//0x0BC
	TEWGraphicButtonWidget* trainingBtn;			//0x0C0
	TEWGraphicButtonWidget* skillBtn;				//0x0C4
	TEWGraphicButtonWidget* tattooBtn;			//0x0C8
	TEWGraphicButtonWidget* motionBtn;			//0x0CC
	int32_t tabIndex;									//0x0D0
	TEWCustomPanelWidget* mainDisplayBg;			//0x0D4
	TEWCustomPanelWidget* descPanel;				//0x0D8
	TEWCustomPanelWidget* tabTitlePanel;			//0x0DC
	TEWCustomPanelWidget* skillBonusLabelPanel;	//0x0E0
	TEWLabel* tabTitleLabel;						//0x0E4
	TEWLabel* skillBonusLabel;					//0x0E8
	TEWLabel* cpRemainingLabel;					//0x0EC
	TNTTimeAniIcon* aSlotsAniIcons[24];         	//0x0F0
	int16_t unknown23;									//0x150
	int16_t nbIconDisplayed;							//0x152
	TNTItemList* trainingList;					//0x154
	TNTItemList* skillList;						//0x158
	TNTItemList* tattooList;						//0x15C
	TNTItemList* motionList;         				//0x160
	TEWScrollBar* scrollBar;						//0x164
	TNTIconWidget* skillBonusIcons[4];       		//0x168
	TEWStringListView* description;				//0x178
	TEWLabel* unknownLabel;						//0x17C
	TEWLabel* trainingTabLabel;					//0x180
	TEWLabel* skillTabLabel;						//0x184
	TEWLabel* tattooTabLabel;						//0x188
	TEWLabel* motionTabLabel;						//0x18C
	TEWCustomPanelWidget* tattooDescPanel[2];		//0x190
	TEWLabels* tattooName[2];						//0x198
	TEWStringListView* tattooDesc[2];				//0x1A0
	int32_t unknown24;									//0x1A8
	int32_t unknown25;									//0x1AC
	TEWGraphicButtonWidget* skillRefundBtn;		//0x1B0
	TEWStringListView* skillRefundBtnText;		//0x1B4
	IconProperties* selectedIconProp;					//0x1B8
	char unknown26[4];									//0x1BC
	uint32_t iconId;									//0x1C0
	char unknown27[8];									//0x1C4
	uint32_t unknown28;									//0x1CC
	char unknown29[4];									//0x1D0
	uint32_t unknown30;									//0x1D4
	bool unknown31;										//0x1D8
	char pad[11];       								//0x1D9
};
static_assert(sizeof(TNTNewCharacterSkillInfoWidget) == 0x1E4, "TNTNewCharacterSkillInfoWidget does not have a size of 0x1E4");

#pragma pack(pop)
