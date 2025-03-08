#pragma once
#include "TGameRootWidget.h"
#include "../../MemoryHelper/PatternScan.h"
#pragma pack(push, 1)

class TLBSWidgetHandler : public TObject
{
public:
	static constexpr std::string_view NAME = "TNTNewCharacterSkillInfoWidget";

	TGameRootWidget* getGameRootWidget()
	{
		if (gameRootWidget == nullptr)
		{
			auto _ = Logger::PushPopModuleName(NAME.data());
			Logger::Error("gameRootWidget == nullptr");
		}
		return gameRootWidget;
	}

	static TLBSWidgetHandler* getNtInstance()
	{
		static void* patternAddr = nullptr;

		if (patternAddr == nullptr)
		{
			auto _ = Logger::PushPopModuleName(NAME.data());

			patternAddr = PatternScan(
				"\x83\x3d\x00\x00\x00\x00\x00\x74\x0a\xa1\x00\x00\x00\x00\xe8\x00\x00\x00\x00\xc3",
				"xx????xxxx????x????x", 2
			);
			if (patternAddr == nullptr)
			{
				Logger::Error("Fail scanning pattern");
				return nullptr;
			}
			Logger::Log("patternAddr = %x", patternAddr);

			Logger::Success("Successfully initialized");
		}

		// Note: if it gets delete-d and new-ed, a refresh of the dereferenced address will be required.
		// Since I don't know if this object ever gets deleted (I HIGHLY doubt it), I am not handling it.
		return **(TLBSWidgetHandler***)patternAddr;
	}

	TLBSWidget* getCurrentClickedWidget() { return currentClickedWidget; }
	TLBSWidget* getCurrentHoveredWidget() { return currentHoveredWidget; }
	TLBSWidget* getLastClickedWidget() { return lastClickedWidget; }

	uint16_t getWidth() { return aspectRatioX; }
	uint16_t getHeight() { return aspectRatioY; }

	void setLastClickedWidget(TLBSWidget* widget) { lastClickedWidget = widget; }

private:
	int32_t TNosTaleMainF;				// 0x0004 TODO: class named TNosTaleMainF - also in 0x34
	uint16_t aspectRatioX;				// 0x0008
	uint16_t aspectRatioY;				// 0x000A
	TGameRootWidget* gameRootWidget;	// 0x000C
	TLBSWidget* currentClickedWidget;	// 0x0010
	TLBSWidget* currentHoveredWidget;	// 0x0014
	TLBSWidget* lastClickedWidget;		// 0x0018
	char unknown1[4];					// 0x001C
	char unknown2[5];					// 0x0020 5 bytes so probably a struct
	int16_t mouseXPosition;				// 0x0025
	int16_t mouseYPosition;				// 0x0027
	char unknown3[3];					// 0x0029 Maybe padding
	char padding[0x2dc];				// 0x002C
};
static_assert(sizeof(TLBSWidgetHandler) == 0x0308, "TLBSWidgetHandler does not have a size of 0x0308.");

#pragma pack(pop)
