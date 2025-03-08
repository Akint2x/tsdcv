#pragma once
#include "TEWCustomButtonWidget.h"
#include "../Properties/Graphical/ImageData.h"
#pragma pack(push, 1)

/* TODO :
* Find unknowns
*/

class TEWGraphicButtonWidget : public TEWCustomButtonWidget
{
public:
	static constexpr std::string_view NAME = "TEWGraphicButtonWidget";
	explicit TEWGraphicButtonWidget() {}
	TEWGraphicButtonWidget(TLBSWidget* Parent, Border Border, Bgra ButtonBgra, ImageData ButtonImages, ImagePadding ImagePadding, Callback Callback, char Unknown15, int8_t NbUsablePictureViews, bool isCheckbox = false, int VTable = ClassSearcher::GetClassInfoFromName("TEWGraphicButtonWidget").GetVTable())
		: TEWCustomButtonWidget(VTable, 0x1, Parent, nullptr, Border)
	{
		callback = Callback;
		isHandlingClick = true;
		nbUsablePictureViews = NbUsablePictureViews;
		unknown15 = Unknown15; // This value is weird. from 0 to 5 it drastically changes the button style
		this->isCheckbox = isCheckbox;

		setWidgetBgra(ButtonBgra);
		setImageData(ButtonImages);
		setImagePadding(ImagePadding);
	}

	void setChecked(bool value) {
		setIsChecked(value);
		setCurrentPictureViewIndex(value);
	}

protected:
	bool isCheckbox;	// 0xD8
	char unknown24[3];	// 0xD9
};
static_assert(sizeof(TEWGraphicButtonWidget) == 0xDC, "TEWGraphicButtonWidget does not have a size of 0xDC.");

#pragma pack(pop)
