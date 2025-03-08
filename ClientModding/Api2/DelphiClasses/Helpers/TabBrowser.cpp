#include "TabBrowser.h"

namespace
{
	void onClickFn(void* _, TEWGraphicButtonWidget* button)
	{
		std::function<void()>* fn = reinterpret_cast<std::function<void()>*>(button->getCallback().getArg());
		if (fn == nullptr)
			return;

		fn->operator()();
	}
}

Tab::Tab(TEWGraphicButtonWidget* Button, const std::vector<TLBSWidget*> Widgets) noexcept
	: widgets(Widgets)
	, button(Button)
{
	for (auto& widget : widgets)
		widgetsVisibility.push_back(widget->isVisible());
}

void Tab::Initialize(std::function<void()>* Func)
{
	if (button == nullptr)
		return;

	func = Func;
	button->setCallback(Callback(onClickFn, func));
}

/*void Tab::Show()
{
	if (!isShown) {
		ImageData imageData = button->getImageData();
		button->setImageData(ImageData(imageData.getImageName(), imageData.getImageWidth(), imageData.getImageHeight(), new PictureDisplayer({
			imageData.getPictureViews()[1],
			imageData.getPictureViews()[0]
			})));
	}
	isShown = true;
	for (auto i = 0; i < widgets.size(); i++)
	{
		if (widgetsVisibility[i] == true)
			widgets[i]->setVisible(true);
	}
}

void Tab::Hide()
{
	if (isShown) {
		ImageData imageData = button->getImageData();
		button->setImageData(ImageData(imageData.getImageName(), imageData.getImageWidth(), imageData.getImageHeight(), new PictureDisplayer({
			imageData.getPictureViews()[1],
			imageData.getPictureViews()[0]
			})));
	}
	isShown = false;
	for (auto i = 0; i < widgets.size(); i++)
	{
		if (widgetsVisibility[i] == true)
			widgets[i]->setVisible(false);
	}
}*/

void Tab::AddWidget(TLBSWidget* widget)
{
	widgets.push_back(widget);
	widgetsVisibility.push_back(widget->isVisible());
}

TabBrowser::TabBrowser(const std::vector<Tab>& Tabs, std::function<void(int)> OnClick) noexcept
	: tabs(Tabs)
	, onClick(OnClick)
{
	for (auto i = 0; i < tabs.size(); i++)
	{
		std::function<void()>* f = new std::function<void()>([this, i]
			{
				Show(i);
				onClick(i);
			});
		tabs[i].Initialize(f);
	}
}

void TabBrowser::Show(int Index)
{
	/*if (Index < 0 || Index >= tabs.size())
		return;

	for (auto i = 0; i < tabs.size(); i++)
	{
		if (i != Index)
			tabs[i].Hide();
	}
	tabs[Index].Show();*/
}

void TabBrowser::AddTab(Tab tab)
{
	auto index = tabs.size();
	tabs.push_back(tab);
	std::function<void()>* f = new std::function<void()>([this, tab, index]
		{
			Show(index);
			onClick(index);
		});
	tab.Initialize(f);
}