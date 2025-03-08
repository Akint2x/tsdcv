#pragma once
#include "TEWCustomPanelWidget.h"
#include "../Properties/Logical/Callback.h"
#pragma pack(push, 1)

class TEWScrollBarThumb;

class TEWScrollBarTrack : public TEWCustomPanelWidget
{
public:
	TEWScrollBarTrack()
		: TEWCustomPanelWidget(nullptr, Border(), ImageData(), ImagePadding(), ClassSearcher::GetClassInfoFromName("TEWScrollBarTrack").GetVTable())
	{
		currentIndex = 0;
		isHorizontal = false;
		isHandlingClick = true;
	}

	TEWScrollBarTrack(TLBSWidget* Parent, Border Border, ImageData PanelImage, ImagePadding ImagePadding, Callback Callback,  TEWScrollBarThumb* ScrollThumb)
		: TEWCustomPanelWidget(Parent, Border, PanelImage, ImagePadding, ClassSearcher::GetClassInfoFromName("TEWScrollBarTrack").GetVTable())
		, scrollThumb(ScrollThumb)
		, callback(Callback)
	{
		TLBSWidget::addWidget(reinterpret_cast<TLBSWidget*>(ScrollThumb)); // Remove reinterpret_cast while using cpp file
		currentIndex = 0;
		isHorizontal = false;
		isHandlingClick = true;
		widgetBgra = Bgra(255, 255, 255, 255);
	}

	[[nodiscard]] Callback getCallback() const { return callback; }
	void setCallback(Callback Callback) { callback = Callback; }

	void setScrollBarThumb(TEWScrollBarThumb* ScrollThumb) { scrollThumb = ScrollThumb; }

	void setCurrentMaxIndex(int16_t CurrentMaxIndex) noexcept { currentMaxIndex = CurrentMaxIndex; }
	void setCurrentIndex(int16_t CurrentIndex) noexcept { currentIndex = CurrentIndex; }
	void setScrollStep(float ScrollStep) noexcept { scrollStep = ScrollStep; }
	void setIsHorizontal(bool IsHorizontal) noexcept { isHorizontal = IsHorizontal; }

	[[nodiscard]] bool IsHorizontal() noexcept { return isHorizontal; }
	[[nodiscard]] int16_t getCurrentIndex() const noexcept { return currentIndex; }
	[[nodiscard]] int16_t getCurrentMaxIndex() const noexcept { return currentMaxIndex; }
	[[nodiscard]] TEWScrollBarThumb* getScrollThumb() noexcept { return scrollThumb; }
	[[nodiscard]] float getScrollStep() noexcept { return scrollStep; }

protected:
	char unknown19[4];						// 0xA4
	TEWScrollBarThumb* scrollThumb;	// 0xA8
	int16_t currentIndex;					// 0xAC
	int16_t currentMaxIndex;				// 0xAE
	bool isHorizontal;						// 0xB0 
	char unknown20;							// 0xB1
	int16_t nbOfElemPerScroll;				// 0xB2 For example, you have 10 lines in inventory, so this will be 10, friend chat allows 8 lines, s this is 8, etc
	int32_t unknown22;						// 0xB4 Same
	float scrollStep;						// 0xB8
	int32_t unknown23;						// 0xBC Unused
	Callback callback;						// 0xC0 Move scrollThumb function callback
	bool isBeingPressed;					// 0xC8 Note : only on the scrolltrack background, not on the thumb
	char unknown24;							// 0xC9 padding byte, probably
	int16_t mousePositionPressing;			// 0xCA
	char unknown25[12];						// 0xCC
};
static_assert(sizeof(TEWScrollBarTrack) == 0xD8, "TEWScrollBarTrack does not have a size of 0xD8.");

#pragma pack(pop)
