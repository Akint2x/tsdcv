#pragma once
#include "TEWCustomFormWidget.h"
#include "TLBSWidgetHandler.h"
#include "TGameRootWidget.h"
#pragma pack(push, 1)

class TNTItemExchangeWidget : public TEWCustomFormWidget
{
public:
	static constexpr std::string_view NAME = "TNTItemExchangeWidget";

	static TNTItemExchangeWidget* getNtInstance()
	{
		static TNTItemExchangeWidget* itemExchangeWidget = nullptr;

		if (itemExchangeWidget == nullptr)
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

			itemExchangeWidget = reinterpret_cast<TNTItemExchangeWidget*>(widgets[0]);

			Logger::Success("Successfully initialized");
		}

		return itemExchangeWidget;
	}

protected:
	char unknown141[204]; // 0xBC
};
static_assert(sizeof(TNTItemExchangeWidget) == 0x188, "TNTItemExchangeWidget does not have a size of 0x188.");

#pragma pack(pop)