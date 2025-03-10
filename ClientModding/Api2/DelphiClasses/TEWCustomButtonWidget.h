#pragma once
#include "TEWCustomPanelWidget.h"
#include "../Properties/Logical/Callback.h"
#pragma pack(push, 1)

/* TODO :
* Find unknowns
*/

class TEWCustomButtonWidget : public TEWCustomPanelWidget
{
public:
	explicit TEWCustomButtonWidget() {}
	TEWCustomButtonWidget(uint32_t VTable, int8_t EvenThing, TLBSWidget* Parent, TLBSWidgetList* Childs, Border Border)
		: TEWCustomPanelWidget(VTable, EvenThing, Parent, Childs, Border)
	{
		makeSound = true;
	}

	[[nodiscard]] Callback getCallback() const { return callback; }
	void setCallback(Callback Callback) { callback = Callback; }

	void setIsChecked(bool value) {
		isChecked = value;
	}
	bool getChecked() { return isChecked; }

protected:
	char unknown17[4];						// 0x00A4
	bool clickedAndHovered;					// 0x00A8
	bool hovered;							// 0x00A9
	char unknown18[6];						// 0x00AA
	Callback callback;						// 0x00B0 onclick i guess => rajouter des instructions � �a par exemple genre this->callback->AddFunction()
	char unknown19[8];						// 0x00B8
	bool isChecked;							// 0x00C0 Strange behaviour : unknown8 ^= 1 on every click on button, but not when triggered by keyboard
	char unknown21;							// 0x00C1
	bool makeSound;							// 0x00C2
	char unknown23[21];						// 0x00C3 some things with a pointer and bool
};
static_assert(sizeof(TEWCustomButtonWidget) == 0x00D8, "TEWCustomButtonWidget does not have a size of 0x00D8.");

#pragma pack(pop)
