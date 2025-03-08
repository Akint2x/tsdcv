#pragma once
#include "TNTMessageBoxWidget.h"
#include "../../MemoryHelper/PatternScan.h"
#pragma pack(push, 1)

class TGameRootWidget;

class TEWRingArrayList : public TObject
{
public:
	static constexpr std::string_view NAME = "TEWRingArrayList";

	static TEWRingArrayList* getNtInstance()
	{
		static void* patternAddr = nullptr;

		if (patternAddr == nullptr)
		{
			auto _ = Logger::PushPopModuleName(NAME.data());

			patternAddr = PatternScan(
				"\xe8\x00\x00\x00\x00\x84\xc0\x74\x00\xa1\x00\x00\x00\x00\x8b\x00\xe8\x00\x00\x00\x00\x8b\xd8\x8b\x47\x60\x89\x43\x60",
				"x????xxx?x????xxx????xxxxxxxx", 10
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
		return ***(TEWRingArrayList****)patternAddr;
	}

	TNTMessageBoxWidget* getNextMessageBoxWidget()
	{
		if (messageBoxes == nullptr)
		{
			Logger::Error("messageBoxes is nullptr");
			return nullptr;
		}
		if (gameRootWidget == nullptr)
		{
			Logger::Error("gameRootWidget is nullptr");
			return nullptr;
		}
		
		int8_t nextIndex = lastUsedIndex + 1;
		if (nextIndex >= 5)
			nextIndex = 0;

		Logger::Debug("Ok");

		if (messageBoxes[nextIndex] == nullptr)
			messageBoxes[nextIndex] = TNTMessageBoxWidget::create(gameRootWidget);

		return messageBoxes[nextIndex];
	}

protected:
	void* TNTMessageBoxWidgetVTable;		// 0x04
	TGameRootWidget* gameRootWidget;	// 0x08 TGameRootWidget in my case
	TNTMessageBoxWidget** messageBoxes;		// 0x0C 5 max I think
	int16_t lastUsedIndex;					// 0x10 messageBoxes[lastUsedIndex] is the last displayed
	int8_t unknown2;						// 0x12
	int8_t unknown3;						// 0x13
};
static_assert(sizeof(TEWRingArrayList) == 0x14, "TEWRingArrayList does not have a size of 0x14.");

#pragma pack(pop)
