#pragma once
#include "TEWCustomPanelWidget.h"
#pragma pack(push, 1)

class TNTChatEditWidget : public TEWCustomPanelWidget
{
public:

private:
	char unknown19[1388];
};
static_assert(sizeof(TNTChatEditWidget) == 0x610, "TNTChatEditWidget does not have a size of 0x610.");

#pragma pack(pop)
