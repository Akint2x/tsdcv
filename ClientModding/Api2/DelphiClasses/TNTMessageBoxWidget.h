#pragma once
#include "TNTCustomMessageWidget.h"
#pragma pack(push, 1)

class TEWGraphicButtonWidget;
class TGameRootWidget;

class TNTMessageBoxWidget : public TNTCustomMessageWidget
{
public:
	static constexpr std::string_view NAME = "TNTMessageBoxWidget";

	static TNTMessageBoxWidget* create(TGameRootWidget* gameRootWidget)
	{
		uintptr_t vTable = *(uintptr_t*)ClassSearcher::GetClassInfoFromName(NAME.data()).GetAddressPtrVTable();
		uintptr_t TNTMessageBoxWidget_Create = *(uintptr_t*)(vTable + 0x44);
		TNTMessageBoxWidget* widget = nullptr;

		__asm
		{
			pushad;
			pushfd;

			mov ecx, gameRootWidget;
			mov dl, 0x01;
			mov eax, vTable;
			call TNTMessageBoxWidget_Create;
			mov widget, eax;

			popfd;
			popad;
		}
		return widget;
	}

	void setText(char* text)
	{
		textDisplayed = text;

		uintptr_t vTable = *(uintptr_t*)ClassSearcher::GetClassInfoFromName(NAME.data()).GetAddressPtrVTable();
		uintptr_t TNTMessageBoxWidget_UpdateText = *(uintptr_t*)(vTable + 0x48);

		__asm
		{
			pushad;
			pushfd;

			mov eax, this;
			call TNTMessageBoxWidget_UpdateText;

			popfd;
			popad;
		}
	}

	TEWGraphicButtonWidget* getLeftButton() { return leftButton; }
	TEWGraphicButtonWidget* getRightButton() { return rightButton; }
	Callback getOnClose() noexcept { return OnClose; }
	void setOnClose(Callback Value) noexcept { OnClose = Value; }

protected:
	TEWGraphicButtonWidget* leftButton;		// 0xD0
	TEWGraphicButtonWidget* rightButton;	// 0xD4
	Callback				OnClose;		// 0xD8 callback.Arg in my case was TNTUnitManager but I doubt it is stable - don't use it
	char					unknown24[4];	// 0xE0
	char					unknown25[4];	// 0xE4 String freed and realloced, maybe a TextStyle (?)
	wchar_t* arg;			// 0xE8 Delphi string NOT ref counted - often used as a singleshot packet (ex: opening a box, packet sent when accepting, etc)
};
static_assert(sizeof(TNTMessageBoxWidget) == 0xF4, "TNTMessageBoxWidget does not have a size of 0xF4");

#pragma pack(pop)