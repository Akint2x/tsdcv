#pragma once
#include "TEWEditWidget.h"
#pragma pack(push, 1)

/* TODO :
* Find those 16 unknowns bytes (0x70)
*/

class TEWNumberEditWidget : public TEWEditWidget
{
public:
	TEWNumberEditWidget(int VTable, int8_t EvenThing, TLBSWidget* Parent, TLBSWidgetList* Childs, Border Border)
		: TEWEditWidget(VTable, EvenThing, Parent, Childs, Border)
	{ }

	static constexpr std::string_view NAME = "TEWNumberEditWidget";

	void setMaxAmount(int32_t value) noexcept { maxValue = value; }

protected:
	char unknown20[4];			// 0xE4
	bool isLimited;				// 0xE8
	char unknown21[3];			// 0xE9
	int32_t minValue;			// 0xEC
	int32_t maxValue;			// 0xF0
};
static_assert(sizeof(TEWNumberEditWidget) == 0xF4, "TEWNumberEditWidget does not have a size of 0xF4.");

#pragma pack(pop)