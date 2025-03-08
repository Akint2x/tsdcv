#pragma once
#include "../TEWCustomFormWidget.h"

class VerticalWrapper
{
public:
	[[nodiscard]] explicit VerticalWrapper(TLBSWidget* Parent) noexcept;
	void AddWidget(TLBSWidget* Widget) noexcept;
	void SetPadding(int16_t Padding) noexcept;
	void SetPosition(int16_t X, int16_t Y, bool fromRight = false) noexcept;
	void SetVisible(bool Val);

private:
	[[nodiscard]] void update() noexcept;

	TEWCustomFormWidget* form { nullptr };
	std::vector<TLBSWidget*> widgets { };
	int16_t padding = 0;
};
