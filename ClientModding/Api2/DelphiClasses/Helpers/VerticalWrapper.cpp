#include "VerticalWrapper.h"
#include "../TLBSWidgetHandler.h"

VerticalWrapper::VerticalWrapper(TLBSWidget* Parent) noexcept
{
	form = new TEWCustomFormWidget(
		Parent,
		Border(0, 0, 0, 0),
		ImageData(1593835568, 512, 512, new PictureDisplayer({
			PictureView(0, 0, 1, 1),
		})),
		ImagePadding()
	);

	form->setWidgetBgra(Bgra(0, 0, 0, 255));
	form->setVisible(false);
	form->shouldSavePosition(true);
	Parent->addWidget(form);
}

void VerticalWrapper::AddWidget(TLBSWidget* Widget) noexcept 
{
	if (Widget == nullptr)
		return;
	if (form == nullptr)
		return;

	Widget->setWidgetParent(form);

	Widget->setVisible(true);
	form->addWidget(Widget);

	widgets.push_back(Widget);
	update();
	
	return;
}

void VerticalWrapper::SetPadding(int16_t Padding) noexcept
{
	if (padding == Padding)
		return;

	padding = Padding;
	update();
}

void VerticalWrapper::SetPosition(int16_t X, int16_t Y, bool fromRight) noexcept
{
	form->setWidgetPosition(fromRight ? X - form->getWidth() : X, Y);
}

void VerticalWrapper::update() noexcept
{
	if (widgets.size() == 0)
		return;

	int formWidth = 0;
	for (int i = 0; i < widgets.size(); i++)
	{
		if (i == 0)
			widgets[i]->setWidgetPosition(0, 0);
		else
			widgets[i]->setWidgetPosition(0, widgets[i - 1]->getBorder().botRightY + padding);
		formWidth = form->getWidth() > widgets[i]->getWidth() ? form->getWidth() : widgets[i]->getWidth();
	}

	form->setWidgetSize(formWidth, widgets[widgets.size() - 1]->getBorder().botRightY);
}

void VerticalWrapper::SetVisible(bool Val)
{
	form->setVisible(Val);
}