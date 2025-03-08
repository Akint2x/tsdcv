#pragma once
#include "TEWControlWidgetEvent.h"
#include "../Properties/Graphical/Border.h"
#include "../Properties/Graphical/IconProperties.h"
#include "../Properties/Logical/Callback.h"
#pragma pack(push, 1)

/* TODO :
* Find unknowns
* Find ImageProperties real structure
* 0x78, 0x90, 0x98 are callbacks
*/

class TNTIconWidget : public TEWControlWidgetEvent
{
public:
	explicit TNTIconWidget() {} // Allows deep copy
	static constexpr std::string_view NAME = "TNTIconWidget";

	TNTIconWidget(uint32_t VTable, int8_t EvenThing, TLBSWidget* Parent, TLBSWidgetList* Childs, Border Border)
		: TEWControlWidgetEvent(VTable, EvenThing, Parent, Childs, Border)
	{
		image = new IconProperties();
		keepTransparency = true;
	}

	TNTIconWidget(TLBSWidget* Parent, Border Border)
		: TEWControlWidgetEvent(ClassSearcher::GetClassInfoFromName("TNTIconWidget").GetVTable(), 0x1, Parent, nullptr, Border)
	{
		keepTransparency = true;
		isHandlingClick = true;
		cursor = Cursor::Hand;
		animate = true;
		allowShowingOrangeBorder = true;
		showBorderOnHover = true;
		showItemWhenDragging = false;
	}

	void setOnDropCallback(Callback OnDrop) { onDrop = OnDrop; }
	Callback getOnDropCallback() { return onDrop; }
	Callback getDoubleClickCallback() { return doubleClick; }
	Callback getSimpleClickCallback() { return simpleClick; }

	void setIconType(uint8_t Value) noexcept { iconType = Value; }
	void setSlot(uint8_t Value) noexcept { slot = Value; }
	void setIsHandlingRightClick(bool Value) noexcept { isHandlingRightClick = Value; }
	void setIsGrabbingItem(bool IsGrabbingItem) noexcept { isGrabbingItem = IsGrabbingItem; }
	void setIconProperties(IconProperties* IconProperties) noexcept { image = IconProperties; }
	void setImageHandlingType(int8_t Value) noexcept { imageHandlingType = Value; }
	void setTransparence(bool Value) noexcept { keepTransparency = Value; }
	void setDoubleClick(Callback Fn) noexcept { doubleClick = Fn; }
	void setSimpleClick(Callback Fn) noexcept { simpleClick = Fn; }
	void setBorderOnHover(bool borderOnHover) noexcept { showBorderOnHover = borderOnHover; }
	IconProperties* getImage() { return image; }
	int16_t getSlot() noexcept { return slot; }
	uint8_t getIconType() noexcept { return iconType; }

	IconProperties* getIconProperties() noexcept { return image; }

protected:
	bool isGrabbingItem;			// 0x70 If you hold the click on the item, true else false
	// 0x78 is a Callback and I __guess__ it is triggered when the icon gets changed
	char unknown14[7];				// 0x71
	Callback onDrop;				// 0x78
	int16_t clickX;					// 0x80
	int16_t clickY;					// 0x82
	bool keepTransparency;			// 0x84
	bool resized;					// 0x85 Weird behaviour, what is it really ?
	char unknown16[10];				// 0x86
	/*
	0x90 : callback single click (left + right)
	*/
	Callback simpleClick;           // 0x90
	Callback doubleClick;			// 0x98
	int8_t imageHandlingType;		// 0xA0 1=character 2=monster 3=monster 4=item other=nothing - 2/3 is redirected to same code btw (entwell)
	bool isHovering;				// 0xA1
	char unknown17;					// 0xA2 Pad differently between 1 and other value
	bool animate;					// 0xA3 if 0xA2 is 0, animate
	bool allowShowingOrangeBorder;	// 0xA4
	char unknown18[3];				// 0xA5 maybe padding
	IconProperties* image;			// 0xA8
	uint8_t iconType;				// 0xAC enum (2 = display on right click item on slot, 3 = tattoos, 7 = display on right click item on icon)
	char unknown19[3];				// 0xAB 
	uint8_t slot;					// 0xB0
	uint8_t unknown19_2;			// 0xB1 Probably inventory type
	char unknown20[22];				// 0xB2
	bool showItemWhenDragging;		// 0xC8
	char unknown21;					// 0xC9
	bool isHandlingRightClick;		// 0xCA
	bool showBorderOnHover;			// 0xCB
};
static_assert(sizeof(TNTIconWidget) == 0xCC, "TNTIconWidget does not have a size of 0xCC.");

#pragma pack(pop)