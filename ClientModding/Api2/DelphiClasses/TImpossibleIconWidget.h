#pragma once
#include "TLBSWidget.h"
#pragma pack(push, 1)

class TEWControlWidgetEX;

class TImpossibleIconWidget : public TLBSWidget
{
public:
    static constexpr std::string_view NAME = "TImpossibleIconWidget";

protected:
    TEWControlWidgetEX* control1;    // 0x24
    TEWControlWidgetEX* control2;    // 0x28
};
static_assert(sizeof(TImpossibleIconWidget) == 0x2C, "TImpossibleIconWidget does not have a size of 0x2C.");

#pragma pack(pop)
