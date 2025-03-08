#include "ScrollBar.h"
#include "../../../MemoryHelper/PatternScan.h"

namespace
{
	void __fastcall onScroll(ScrollBar::IndexType index, TEWScrollBarTrack* scrollTrack)
	{
		ScrollBar::SubCallback cb = *reinterpret_cast<ScrollBar::SubCallback*>(scrollTrack->getCallback().getArg());
		cb(index);
	}

	uintptr_t getNextButtonFunc()
	{
		uintptr_t* patternAddr = (uintptr_t*)PatternScan("\x89\x46\x41\x8b\x43\x68\x89\x86\xb4\x00\x00\x00\xc7\x86\xb0\x00\x00\x00\x00\x00\x00\x00\x8b\xcb\xb2\x01",
			"xxxxxxxxxxxxxxxxxx????xxxx",
			18
		);
		if (patternAddr == nullptr || *(uintptr_t*)patternAddr == NULL)
		{
			Logger::Error("ScrollBar::getNextButtonFunc() pattern is not valid");
			return NULL;
		}
		Logger::Log("ScrollBar::getNextButtonFunc() %x", *(uintptr_t*)patternAddr);
		return *(uintptr_t*)patternAddr;
	}

	uintptr_t getPreviousButtonFunc()
	{
		uintptr_t* patternAddr = (uintptr_t*)PatternScan("\x89\x46\x41\x8b\x43\x68\x89\x86\xb4\x00\x00\x00\xc7\x86\xb0\x00\x00\x00\x00\x00\x00\x00\xc6\x43\x74\x01\x8b\xc3",
			"xxxxxxxxxxxxxxxxxx????xxxxxx",
			18
		);
		if (patternAddr == nullptr || *(uintptr_t*)patternAddr == NULL)
		{
			Logger::Error("ScrollBar::getPreviousButtonFunc() pattern is not valid");
			return NULL;
		}
		Logger::Log("ScrollBar::getPreviousButtonFunc() %x", *(uintptr_t*)patternAddr);
		return *(uintptr_t*)patternAddr;
	}
}

ScrollBar::ScrollBar(TLBSWidget* Parent, Border BorderWidget, SubCallback Cb, IndexType MaxSimultaneousShownItems) noexcept
	: maxSimultaneousShownItems(MaxSimultaneousShownItems)
	, currentAnimationPosition(0)
	, targetAnimationPosition(0)
	, animationDuration(0.2f)  // 200ms
	, animationElapsedTime(0)
	, isAnimating(false)
{
	cb = SubCallback([this, Cb](IndexType index)
	{
		if (index < 0 || index == lastIndex || !canScroll())
			return;
		lastIndex = index;
		Cb(index);
	});


	scrollBar = new TEWScrollBar(Parent, BorderWidget, Callback(onScroll, &cb));

	scrollThumb = new TEWScrollBarThumb();
	scrollTrack = new TEWScrollBarTrack();
	scrollThumb->setWidgetBgra(Bgra(255, 255, 255, 255));
	scrollTrack->setWidgetBgra(Bgra(255, 255, 255, 255));

	scrollTrack->addWidget(scrollThumb);

	if (BorderWidget.getWidth() > BorderWidget.getHeight())
		scrollTrack->setIsHorizontal(true);

	scrollThumb->setWidgetParent(scrollTrack);
	scrollTrack->setUnknown15(4);

	scrollTrack->setWidgetParent(scrollBar);		
	scrollTrack->setCallback(Callback(onScroll, &cb));
	scrollTrack->setScrollBarThumb(scrollThumb);

	if (scrollTrack->IsHorizontal())
	{
		scrollThumb->setWidgetBorder(Border(0, 0, 59, 11));
		scrollThumb->setImageData(ImageData(1593835585, 512, 512, new PictureDisplayer(
			{
				PictureView(244, 440, 27, 11),
				PictureView(271, 440, 10, 11),
				PictureView(234, 440, 10, 11),
			})));
		scrollThumb->setImagePadding(ImagePadding(39, 11, 49, 11, 10, 0, 10, 0));
		scrollThumb->setUnknown15(4);

		scrollTrack->setWidgetBorder(Border(0, 0, scrollBar->getWidth(), 11));
		scrollTrack->setImageData(ImageData(1593835585, 512, 512, new PictureDisplayer(
			{
				PictureView(244, 452, 27, 11),
				PictureView(271, 452, 10, 11),
				PictureView(234, 452, 10, 11),
			})));
		scrollTrack->setImagePadding(ImagePadding(scrollBar->getWidth() - 1, 9, scrollBar->getWidth() - 1, 10, 1, 1, 1, 1));
	}
	else 
	{
		scrollThumb->setWidgetBorder(Border(0, 0, 17, 37));
		scrollThumb->setImageData(ImageData(1593835568, 512, 512, new PictureDisplayer(
			{
				PictureView(476, 361, 17, 7),
				PictureView(476, 356, 17, 5),
				PictureView(476, 368, 17, 6),
			})));
		scrollThumb->setImagePadding(ImagePadding(17, 26, 17, 31, 0, 5, 0, 6));

		scrollTrack->setWidgetBorder(Border(0, 18, 17, scrollBar->getBorder().getHeight() - 34));
		scrollTrack->setImageData(ImageData(1593835568, 512, 512, new PictureDisplayer(
			{
				PictureView(507, 401, 3, 1),
				PictureView(506, 400, 1, 1),
				PictureView(507, 400, 3, 1),
				PictureView(510, 400, 1, 1),
				PictureView(510, 401, 1, 1),
				PictureView(510, 402, 1, 1),
				PictureView(507, 402, 3, 1),
				PictureView(506, 402, 1, 1),
				PictureView(506, 401, 1, 1),
			})));
		scrollTrack->setImagePadding(ImagePadding(15, scrollBar->getBorder().getHeight() - 18 - 2, 16, scrollBar->getBorder().getHeight() - 18 - 1, 1, 1, 1, 1));

		buttonNext = new TEWGraphicButtonWidget(
			scrollBar,
			Border(0, 0, 17, 18),
			Bgra(255, 255, 255, 255),
			ImageData(1593835568, 512, 512, new PictureDisplayer(
				{
					PictureView(476, 332, 17, 18),
				}
			)),
			ImagePadding(),
			Callback(getNextButtonFunc(), scrollTrack),
			0, 1
		);

		buttonPrevious = new TEWGraphicButtonWidget(
			scrollBar,
			Border(0, scrollBar->getBorder().getHeight() - 17, 17, 18),
			Bgra(255, 255, 255, 255),
			ImageData(1593835568, 512, 512, new PictureDisplayer(
				{
					PictureView(476, 381, 17, 18),
				}
			)),
			ImagePadding(),
			Callback(getPreviousButtonFunc(), scrollTrack),
			0, 1
		);

		scrollBar->addWidget(buttonNext);
		scrollBar->addWidget(buttonPrevious);

		scrollBar->setNextButton(buttonNext);
		scrollBar->setPreviousButton(buttonPrevious);

		buttonNext->setVisible(true);
		buttonPrevious->setVisible(true);
	}


	scrollBar->addWidget(scrollTrack);
	scrollBar->setScrollTrack(scrollTrack);

	Parent->addWidget(scrollBar);

	scrollThumb->setVisible(false);
	scrollTrack->setVisible(true);
	scrollBar->setVisible(true);

	Logger::Log("ScrollBar: %x, ScrollTrack: %x, ScrollThumb: %x", scrollBar, scrollTrack, scrollThumb);
}

void ScrollBar::SetCurrentItemsNumber(IndexType Value) noexcept
{
	currentItemsNumber = Value;
	auto actualIndex = currentItemsNumber - maxSimultaneousShownItems;
	if (actualIndex < 0) actualIndex = 0;
	scrollTrack->setCurrentMaxIndex(actualIndex);
	updateScrollThumbPadding();
	updateScrollStep();
}

void ScrollBar::updateScrollStep()
{
	if (!canScroll())
	{
		scrollThumb->setVisible(false);
		scrollTrack->setScrollStep(0.f);
		return;
	}

	float trackSize = 0.0;
	float thumbSize = 0.0;

	if (!scrollTrack->IsHorizontal())
	{
		trackSize = static_cast<float>(scrollTrack->getHeight());
		thumbSize = static_cast<float>(scrollThumb->getHeight());
	}
	else
	{
		trackSize = static_cast<float>(scrollTrack->getWidth());
		thumbSize = static_cast<float>(scrollThumb->getWidth());
	}

	int16_t nbMaxItem = scrollTrack->getCurrentMaxIndex();
	float scrollStep = (trackSize - thumbSize) / static_cast<float>(nbMaxItem);
	scrollTrack->setScrollStep(scrollStep);

	scrollThumb->setVisible(true);
}

void ScrollBar::updateScrollThumbPadding()
{
	if (scrollTrack->IsHorizontal())
		return;
	if (currentItemsNumber == 0)
		return;

	float trackHeight = static_cast<float>(scrollTrack->getBorder().getHeight());
	float ratio = (float)(scrollTrack->getCurrentMaxIndex()) / (float)currentItemsNumber;
	float newThumbHeight = trackHeight * ratio;
	if (newThumbHeight > trackHeight)
		newThumbHeight = trackHeight;

	scrollThumb->setWidgetBorder(Border(0, 0, 17, (int16_t)newThumbHeight));
	scrollThumb->setWidgetBgra(Bgra(255, 255, 255, 255));
	scrollThumb->setImagePadding(ImagePadding(17, (int16_t)newThumbHeight - 11, 17, (int16_t)newThumbHeight - 6, 0, 5, 0, 6));
}

bool ScrollBar::canScroll()
{
	return currentItemsNumber > maxSimultaneousShownItems;
}

void ScrollBar::SetScrollStep(float Value) noexcept
{
	scrollTrack->setScrollStep(Value);
}

void ScrollBar::SetCurrentIndex(int16_t Value) noexcept
{
	Logger::Log("SetCurrentIndex: %d", Value);
	scrollTrack->setCurrentIndex(Value);
	updateScrollStep();

	float newPosition = Value * scrollTrack->getScrollStep();

	if (!scrollTrack->IsHorizontal())
	{
		scrollThumb->setWidgetPosition(0, static_cast<int16_t>(newPosition));
	}
	else
	{
		scrollThumb->setWidgetPosition(static_cast<int16_t>(newPosition), 0);
	}
	Logger::Log("New thumb position: %d", static_cast<int16_t>(newPosition));
}

void ScrollBar::BlockScroll(bool value) noexcept
{
	scrollTrack->setHandlingClick(!value);
	scrollThumb->setHandlingClick(!value);
	scrollBar->setHandlingClick(!value);
}

void ScrollBar::updateScrollThumbPosition()
{
	float newPosition = scrollTrack->getCurrentIndex() * scrollTrack->getScrollStep();

	if (!scrollTrack->IsHorizontal())
	{
		scrollThumb->setWidgetPosition(0, static_cast<int16_t>(newPosition));
	}
	else
	{
		scrollThumb->setWidgetPosition(static_cast<int16_t>(newPosition), 0);
	}
	Logger::Log("New thumb position: %d", static_cast<int16_t>(newPosition));
}


void ScrollBar::UpdateAnimation(float deltaTime)
{
	if (!isAnimating)
		return;

	animationElapsedTime += deltaTime;
	float t = animationElapsedTime / animationDuration;

	if (t >= 1.0f)
	{
		t = 1.0f;
		isAnimating = false;
	}

	float easedT = 1 - (1 - t) * (1 - t);

	float newPosition = currentAnimationPosition + (targetAnimationPosition - currentAnimationPosition) * easedT;

	if (!scrollTrack->IsHorizontal())
	{
		scrollThumb->setWidgetPosition(0, static_cast<int16_t>(newPosition));
	}
	else
	{
		scrollThumb->setWidgetPosition(static_cast<int16_t>(newPosition), 0);
	}

	if (!isAnimating)
	{
		if (!scrollTrack->IsHorizontal())
		{
			scrollThumb->setWidgetPosition(0, static_cast<int16_t>(targetAnimationPosition));
		}
		else
		{
			scrollThumb->setWidgetPosition(static_cast<int16_t>(targetAnimationPosition), 0);
		}
	}
}