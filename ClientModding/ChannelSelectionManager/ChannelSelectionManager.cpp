#include "ChannelSelectionManager.h"
#include "../Api/DelphiClasses/TLBSWidgetHandler.h"
#include "../Api/DelphiClasses/TNTNewServerSelectWidget2.h"
#include "../Api/DelphiClasses/TNTLoginWidget.h"

ChannelSelectionManager::ChannelSelectionManager(const ChannelSelectionManagerConfig& Config) noexcept
	: Manager(Config, "ChannelSelectionManager")
{}

bool ChannelSelectionManager::initialize() noexcept
{
	TGameRootWidget* gameRoot = TLBSWidgetHandler::getNtInstance()->getGameRootWidget();

	std::vector<TLBSWidget*> widgets = gameRoot->findClassesWithExpectedSize(TNTLoginWidget::NAME, 1);
	if (widgets.size() == 0)
		return false;

	widgets = widgets[0]->findClassesWithExpectedSize(TNTNewServerSelectWidget2::NAME, 1);
	if (widgets.size() == 0)
		return false;

	TNTNewServerSelectWidget2* servSelectWidget = reinterpret_cast<TNTNewServerSelectWidget2*>(widgets[0]);
	TEWControlWidgetEX* tracker = servSelectWidget->getServerTrackerWidget();
	int32_t incX = static_cast<int32_t>(static_cast<float>(tracker->getBorder().topLeftX) / 2.);

	TLBSWidgetList&& children = servSelectWidget->getChildren();
	TLBSWidgetList* newList = new TLBSWidgetList;
	for (auto i = 0; i < children.size(); i++)
	{
		TLBSWidget* currItem = children.getItem(i);
		if (currItem->getBorder().topLeftX >= tracker->getBorder().topLeftX)
		{
			currItem->moveWidget(-incX, 0);
			newList->push_back(currItem);
		}
	}
	servSelectWidget->setChildren(newList);

	return true;
}

bool ChannelSelectionManager::unload() noexcept
{
	return false;
}

void ChannelSelectionManager::tick() noexcept
{}
