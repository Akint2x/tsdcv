#pragma once
#include "TEWControlWidget.h"
#include "../../Api/Properties/Logical/Callback.h"
#pragma pack(push, 1)

/* TODO :
* Find those 8 unknowns bytes (0x68)
*/

class TEWControlWidgetEvent : public TEWControlWidget
{
public:
	explicit TEWControlWidgetEvent() {} // Allows deep copy

	TEWControlWidgetEvent(uint32_t VTable, int8_t EvenThing, TLBSWidget* Parent, TLBSWidgetList* Childs, Border Border)
		: TEWControlWidget(VTable, EvenThing, Parent, Childs, Border)
	{}

protected:
	Callback unknownCallback; //0x68
};
static_assert(sizeof(TEWControlWidgetEvent) == 0x70, "TEWControlWidgetEvent does not have a size of 0x70.");

#pragma pack(pop)
