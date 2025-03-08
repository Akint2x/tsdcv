#pragma once
#include "TEWCustomFormWidget.h"
#pragma pack(push, 1)

class TNTWebBrowserFormWidget : public TEWCustomFormWidget
{
public:
	static constexpr std::string_view NAME = "TNTWebBrowserFormWidget";

protected:
	char unknown22[4];			//0xBC
	void* unknown23;			//0xC0
	int16_t xOffset;			//0xC4
	int16_t yOffset;			//0xC6
	char unknown24[4];			//0xC8
	int32_t xWindowPosition;	//0xCC
	int32_t yWindowPosition;	//0xD0
	char unknown25[24];			//0xD4
	char* url;					//0xEC
	char unknown26[12];			//0xF0
	void* closeCallback;		//0xFC
};
static_assert(sizeof(TNTWebBrowserFormWidget) == 0x100, "TNTWebBrowserFormWidget does not have a size of 0x100.");

#pragma pack(pop)