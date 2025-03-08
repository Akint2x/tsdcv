#pragma once
#include "TEWControlWidget.h"
#include "../Properties/Logical/Callback.h"
#include "../Properties/Graphical/Border.h"
#pragma pack(push, 1)

class TEWScrollBarTrack;
class TEWGraphicButtonWidget;

class TEWScrollBar : public TEWControlWidget
{
public:
	static constexpr std::string_view NAME = "TEWScrollBar";
	TEWScrollBar(TLBSWidget* Parent, Border Border, Callback Callback = Callback())
		: TEWControlWidget(ClassSearcher::GetClassInfoFromName("TEWScrollBar").GetVTable(), 0x01, Parent, nullptr, Border)
		, callback(Callback)
	{
		isHandlingClick = true;
		unknown13 = 1;
	}

	TEWScrollBar(TLBSWidget* Parent, Border Border, Callback Callback, TEWScrollBarTrack* ScrollerTrack, TEWGraphicButtonWidget* ButtonScrollPrevious, TEWGraphicButtonWidget* ButtonScrollNext)
		: TEWControlWidget(ClassSearcher::GetClassInfoFromName("TEWScrollBar").GetVTable(), 0x01, Parent, nullptr, Border)
		, scrollTrack(ScrollerTrack)
		, buttonScrollNextWidget(ButtonScrollNext)
		, buttonScrollPreviousWidget(ButtonScrollPrevious)
		, callback(Callback)
	{
		isHandlingClick = true;
		unknown13 = 1;
		TLBSWidget::addWidget(reinterpret_cast<TLBSWidget*>(scrollTrack)); // TODO: remove the reinterpret_cast while using cpp file
		TLBSWidget::addWidget(reinterpret_cast<TLBSWidget*>(buttonScrollPreviousWidget));
		TLBSWidget::addWidget(reinterpret_cast<TLBSWidget*>(buttonScrollNextWidget));
	}

	void setScrollTrack(TEWScrollBarTrack* ScrollTrack) noexcept { scrollTrack = ScrollTrack; }
	void setPreviousButton(TEWGraphicButtonWidget* Button) noexcept { buttonScrollPreviousWidget = Button; }
	void setNextButton(TEWGraphicButtonWidget* Button) noexcept { buttonScrollNextWidget = Button; }

	[[nodiscard]] Callback getCallback() const { return callback; }
	void setCallback(Callback Callback) { callback = Callback; }

	[[nodiscard]] TEWScrollBarTrack* getScrollTrack() noexcept { return scrollTrack; }
	[[nodiscard]] TEWGraphicButtonWidget* getButtonScrollPreviousWidget() noexcept { return buttonScrollPreviousWidget; }
	[[nodiscard]] TEWGraphicButtonWidget* getButtonScrollNextWidget() noexcept { return buttonScrollNextWidget; }

private:
	TEWScrollBarTrack* scrollTrack;						// 0x68
	TEWGraphicButtonWidget* buttonScrollPreviousWidget;	// 0x6C
	TEWGraphicButtonWidget* buttonScrollNextWidget;		// 0x70
	int32_t unknown13;											// 0x74 if 0, the scrollbar is white, else it applies the style
	Callback callback;											// 0x78 eax is equal to parent, and ecx to index of scroll (0 top, 1 scrolled once, etc)
};
static_assert(sizeof(TEWScrollBar) == 0x80, "TEWScrollBar does not have a size of 0x80.");

#pragma pack(pop)
