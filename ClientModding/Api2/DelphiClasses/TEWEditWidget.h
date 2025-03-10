#pragma once
#include "TEWControlWidget.h"
#include "../Properties/Logical/String.h"
#include "../Properties/Logical/Callback.h"
#include <vector>
#pragma pack(push, 1)

class TEWEditWidget : public TEWControlWidget
{
public:
	static constexpr std::string_view NAME = "TEWEditWidget";

	TEWEditWidget(uint32_t VTable, int8_t EvenThing, TLBSWidget* Parent, TLBSWidgetList* Childs, Border Border)
		: TEWControlWidget(VTable, EvenThing, Parent, Childs, Border)
		, textBgra(255, 255, 255, 255)
		, selectionBgra(255, 255, 255, 255)
		, buffer(nullptr)
	{}

	TEWEditWidget(TLBSWidget* Parent, Border Border, int FontStyle, Bgra TextBgra, Bgra SelectionBgra, std::vector<Callback> cbs)
		: TEWControlWidget(ClassSearcher::GetClassInfoFromName("TEWEditWidget").GetVTable()
		, 0x39, Parent, nullptr, Border)
		, fontStyle(FontStyle)
		, textBgra(TextBgra)
		, selectionBgra(SelectionBgra)
		, buffer(nullptr)
	{
		isHandlingClick = true;
		//useTextCursor(true);

		for (size_t i = 0; i < cbs.size() && i < 4; i++)
		{
			callbacks[i] = cbs[i];
		}
	}

	void setOnClickCallback(Callback Cb) { onClickCallback = Cb; }
	void setOnKeyPressedCallback(Callback Cb) { onKeyPress = Cb; }
	void setText(wchar_t* text) { buffer = text; }
	void setCursorPos(int32_t value) { textCursorPosition = value; }

	wchar_t* getText() const { return buffer; }
	Callback getOnKeyPressCallback() { return onKeyPress; }

protected:
	wchar_t* buffer;						// 0x68
	char unknown13[4];						// 0x6C something with text (got out of memory and asian character appeared)
	char unknown14[4];						// 0x70 used for ctrl+clic on item for ALL chat (speaker), as a packet completion : 2 46 (inventory type, cell)
	char unknown15[4];						// 0x74 used to store only text before item_name (without the "{item_name}" when using ctrl+click item)
	int32_t textCursorPosition;				// 0x78
	int32_t pxBeforeTextCursor;				// 0x7C
	int32_t textPadding;					// 0x80 < 0 : pads to the right, > 0 : pads to the left
	int32_t numberCharactersSelected;		// 0x84 < 0 : textCursor is on the left, > 0 : textCursor is on the right
	uint32_t lastTimeTextCursorBlinked;		// 0x88
	char unknown16[1 * 4];					// 0x8C
	Callback onClickCallback;				// 0x90
	char unknown16_2[2 * 4];				// 0x98
	Callback onKeyPress;					// 0xA0
	Callback callbacks[3];					// 0xA8
	char unknown17[3 * sizeof(Callback)];	// 0xE0 Probably 3 others callback
	int8_t fontStyle;						// 0xD8
	char unknown18;							// 0xD9
	Bgra textBgra;							// 0xDA
	Bgra selectionBgra;						// 0xDE
	char unknown19[2];						// 0xE2
};
static_assert(sizeof(TEWEditWidget) == 0xE4, "TEWEditWidget does not have a size of 0xE4.");

#pragma pack(pop)
