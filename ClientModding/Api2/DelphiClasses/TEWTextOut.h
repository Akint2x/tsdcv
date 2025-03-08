#pragma once
#include "TEWControlWidgetEX.h"
#pragma pack(push, 1)

class TEWTextOut : public TEWControlWidgetEX
{
public:
	static constexpr std::string_view NAME = "TEWTextOut";

protected:
	void* textRender;		//0x68 TLSTextRender
	int8_t unknown13;		//0x6C
	Bgra textColor;			//0x6D
	char unknown14[3];		//0x71
	int16_t unknown15;		//0x74
	bool isBgTransparent;	//0x76
	char unknown16[1];		//0x77
};
static_assert(sizeof(TEWTextOut) == 0x78, "TEWTextOut does not have a size of 0x78.");

#pragma pack(pop)
