#pragma once
#include "TEWCustomFormWidget.h"
#include "../Enums/WidgetResizeType.h"
#pragma pack(push, 1)

class TEWFormWidget : public TEWCustomFormWidget
{
public:
	static constexpr std::string_view NAME = "TEWFormWidget";

	void setResizeFlag(WidgetResizeType ResizeFlag) { resizeFlag = ResizeFlag; }

protected:
	char unknown22[4];				// 0xBC
	WidgetResizeType resizeFlag;	// 0xC0
	char unknown24[3];				// 0xC1 probably padding
};
static_assert(sizeof(TEWFormWidget) == 0xC4, "TEWFormWidget does not have a size of 0xC4.");

#pragma pack(pop)