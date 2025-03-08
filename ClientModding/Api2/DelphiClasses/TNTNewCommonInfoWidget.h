#pragma once
#include "TNTCommonInfoBoard.h"
#include "TLBSWidgetHandler.h"
#include "TGameRootWidget.h"
#pragma pack(push, 1)

class TNTNewCommonInfoWidget : public TLBSWidget
{
public:
	static constexpr std::string_view NAME = "TNTNewCommonInfoWidget";

	static TNTNewCommonInfoWidget* getNtInstance()
	{
		static TNTNewCommonInfoWidget* newCommonInfoWidget = nullptr;

		if (newCommonInfoWidget == nullptr)
		{
			auto _ = Logger::PushPopModuleName(NAME.data());

			TLBSWidgetHandler* widgetHandler = TLBSWidgetHandler::getNtInstance();
			if (!widgetHandler)
				return nullptr;
			TGameRootWidget* gameRoot = widgetHandler->getGameRootWidget();
			if (!gameRoot)
				return nullptr;

			auto widgets = gameRoot->findClassesWithExpectedSize(NAME, 1);
			if (widgets.size() == 0)
				return nullptr;

			newCommonInfoWidget = reinterpret_cast<TNTNewCommonInfoWidget*>(widgets[0]);

			Logger::Success("Successfully initialized");
		}

		return newCommonInfoWidget;
	}

	[[nodiscard]] bool isSheetOpened()
	{
		int size = *(int*)(arr - 1);
		for (int i = 0; i < size; i++)
		{
			if (arr[i]->isVisible())
				return true;
		}
		return false;
	}

protected:
	char unknown3[4];			// 0x24 2 int16_t, with left being right - 1 and right being number of opened TNTCommonInfoBoard
	int sizeOfFollowingArray;	// 0x28
	TNTCommonInfoBoard** arr;	// 0x2C -- Ugly, make a DelphiDynArray class template and use it that way - note, 00 ref count 04 size 08 actual array
	char unknown4[28];			// 0x30 no clue
	// 0x44 : TNTItemList
};
static_assert(sizeof(TNTNewCommonInfoWidget) == 0x4C, "TNTNewCommonInfoWidget does not have a size of 0x4C");

#pragma pack(pop)
