#pragma once
#include "TEWCustomFormWidget.h"
#include "TLBSWidgetHandler.h"
#include "TGameRootWidget.h"
#pragma pack(push, 1)

class TNTIndividualShop : public TEWCustomFormWidget
{
public:
	static constexpr std::string_view NAME = "TNTIndividualShop";

	static TNTIndividualShop* getNtInstance()
	{
		static TNTIndividualShop* individualShop = nullptr;

		if (individualShop == nullptr)
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

			individualShop = reinterpret_cast<TNTIndividualShop*>(widgets[0]);

			Logger::Success("Successfully initialized");
		}

		return individualShop;
	}

protected:
	char unknown141[208]; // 0xBC
};
static_assert(sizeof(TNTIndividualShop) == 0x18C, "TNTIndividualShop does not have a size of 0x18C.");

#pragma pack(pop)