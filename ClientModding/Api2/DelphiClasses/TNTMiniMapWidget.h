#pragma once
#include "TEWCustomFormWidget.h"
#pragma pack(push, 1)

class TEWLabel;
class TEWGraphicButtonWidget;

class TNTMiniMapWidget : public TEWCustomFormWidget
{
public:
	static constexpr std::string_view NAME = "TNTMiniMapWidget";

protected:
	char unknown22[4];							//0xBC
	void* miniMap;								//0xC0 TMiniMapWidget
	TEWLabel* mapName;							//0xC4
	TEWGraphicButtonWidget* openMapBtn;			//0xC8
	TEWGraphicButtonWidget* collapseWidgetBtn;	//0xCC
	char unknown23[4];							//0xD0
	void* tsMiniMap;							//0xD4 TNTRiskMapWidget
	char unknown24[4];							//0xD8
	void* map;									//0xDC TNTZoneMapWidget
};
static_assert(sizeof(TNTMiniMapWidget) == 0xE0, "TNTMiniMapWidget does not have a size of 0xE0.");

#pragma pack(pop)