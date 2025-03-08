#pragma once
#include "TLBSWidget.h"
#pragma pack(push, 1)

class TEWCustomPanelWidget;
class TEWLabel;

class TNTMaskingGaugeWidget : public TLBSWidget
{
public:
	static constexpr std::string_view NAME = "TNTMaskingGaugeWidget";
	void setMaxValue(int32_t Value) { maxValue = Value; }
	void setCurrentValue(int32_t Value) { currentValue = Value; }

private:
	TEWCustomPanelWidget* unknownPanel;		//0x24
	TEWCustomPanelWidget* gaugeBackground;	//0x28
	TEWCustomPanelWidget* unknownPanel2;	//0x2C
	TEWCustomPanelWidget* unknownPanel3;	//0x30
	TEWCustomPanelWidget* unknownPanel4;	//0x34
	char unknown3[16];						//0x38
	int32_t maxValue;						//0x48
	int32_t currentValue;					//0x4C
	int32_t bonusValue;						//0x50
	float percentValue;						//0x54
	char unknown4[4];						//0x58 On change, Update UI prob Callback
	TLBSWidget* parent;						//0x5C
	int32_t currentValue2;					//0x60
	char unknown5[8];						//0x64
	TEWLabel* valuesLabel;					//0x6C
};
static_assert(sizeof(TNTMaskingGaugeWidget) == 0x70, "TNTMaskingGaugeWidget does not have a size of 0x70");

#pragma pack(pop)
