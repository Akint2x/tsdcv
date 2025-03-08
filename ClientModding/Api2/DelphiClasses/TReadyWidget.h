#pragma once
#include "TLBSWidget.h"
#pragma pack(push, 1)

class TEWGraphicButtonWidget;

class TReadyWidget : public TLBSWidget
{
public:
    static constexpr std::string_view NAME = "TReadyWidget";

protected:
    TEWGraphicButtonWidget* readyButton;    // 0x24
};
static_assert(sizeof(TReadyWidget) == 0x28, "TReadyWidget does not have a size of 0x28.");

#pragma pack(pop)
