#pragma once
#include "../TEWGraphicButtonWidget.h"
#include "../TEWLabel.h"

class Tab
{
public:
    [[nodiscard]] explicit Tab(TEWGraphicButtonWidget* Button, const std::vector<TLBSWidget*> Widgets) noexcept;

    void Initialize(std::function<void()>* Func);
    /*void Show();
    void Hide();*/
    void AddWidget(TLBSWidget* widget);

private:
    std::vector<TLBSWidget*> widgets;
    std::vector<bool> widgetsVisibility; // If a widget is not visible by default, changing tab without it would make it visible
    std::function<void()>* func{ nullptr };
    bool isShown = false;

    TEWGraphicButtonWidget* button{ nullptr };
};

class TabBrowser
{
public:
    [[nodiscard]] explicit TabBrowser(const std::vector<Tab>& Tabs, std::function<void(int)> OnClick = [](int) {}) noexcept;

    void Show(int Index);
    void AddTab(Tab tab);

private:
    std::vector<Tab> tabs;
    std::function<void(int)> onClick;
};