#pragma once
#include "TEWCustomFormWidget.h"
#include "../Properties/Graphical/TextPosition.h"
#include "../Properties/Graphical/TextStyle.h"
#include "../Properties/Logical/String.h"
#pragma pack(push, 1)

class TEWEditWidget;
class TEWStringListView;
class TEWScrollBar;
class TEWCustomPanelWidget;
class TEWLabel;

class TBuddyChatWidget : public TEWCustomFormWidget
{
public:
    static constexpr std::string_view NAME = "TBuddyChatWidget";
	TBuddyChatWidget(TLBSWidget* Parent, Border Border)
		: TEWCustomFormWidget(ClassSearcher::GetClassInfoFromName("TBuddyChatWidget").GetVTable()
			, 0x1, Parent, nullptr, Border)
	{ }


    TEWScrollBar* getScrollBar() const { return scrollBar; }
    TEWEditWidget* getInputField() const { return inputField; }
    TEWStringListView* getStringListView() const { return stringListView; }
    uint32_t           getCharacterId() const { return characterId; }
    char*           getCharacterName() const { return characterName; }

protected:
    uint8_t pad_00BC[4];                // 0x00BC
    TEWEditWidget* inputField;          // 0x00C0
    uint8_t pad_00C4[12];               // 0x00C4
    char* characterName;                // 0x00D0
    uint32_t characterId;               // 0x00D4
    char pad_00D8[4];                   // 0x00D8
    TEWStringListView* stringListView;  // 0x00DC
    TEWScrollBar* scrollBar;            // 0x00E0
    TEWCustomPanelWidget* panelWidget;  // 0x00E4
    TEWLabel* labelColor;               // 0x00E8
    uint8_t pad_00EC[28];               // 0x00EC
};
static_assert(sizeof(TBuddyChatWidget) == 0x108, "TBuddyChatWidget does not have a size of 0x108.");

#pragma pack(pop)
