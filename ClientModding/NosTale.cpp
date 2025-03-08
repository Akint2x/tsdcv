#include "NosTale.h"
#include <windows.h>
#include "resource.h"
#include "Api/DelphiClasses/TLBSWidgetHandler.h"

// Forward declaration of the window procedure
LRESULT CALLBACK SplashWndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam);

HWND hSplashWnd = nullptr;
HINSTANCE hInstanceGlobal;
HBITMAP hSplashBitmap = nullptr;


NosTale::NosTale(const ClientModdingConfig& Config, HINSTANCE hInstance) noexcept
	: ClientModding(Config), hInstanceGlobal(hInstance)
{
	if (!hInstanceGlobal)
	{
		Logger::Error("Invalid HINSTANCE provided to NosTale constructor.");
		return;
	}
    nostaleDiscordMng.ConfigurePacketManager(packetMng);
    warpMod.ConfigurePacketManager(packetMng);
    nostaleDiscordMng.ConfigureDiscordManager(discordMng);
    nostaleDiscordMng.ConfigureConnectionManager(connectionMng);
}

bool NosTale::beforeRun() noexcept
{
	auto _ = Logger::PushPopModuleName("NosTale2");

    if (!nosbazarMng.Initialize())
        return false;
    if (!channelSelectionMng.Initialize())
        return false;
    if (!nostaleDiscordMng.Initialize())
        return false;
    if(!warpMod.Initialize())
       return false;
	Logger::Success("Successfully initialized");
	return true;
}

void NosTale::onShowNostaleSplash() noexcept
{
    if (hSplashWnd)
        return; // Already showing

    if (!hInstanceGlobal)
    {
        Logger::Error("Invalid HINSTANCE in onShowNostaleSplash.");
        return;
    }

    const wchar_t CLASS_NAME[] = L"SplashWindowClass";

    WNDCLASS wc = { };
    wc.lpfnWndProc = SplashWndProc;
    wc.hInstance = hInstanceGlobal;
    wc.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
    wc.lpszClassName = CLASS_NAME;

    if (!RegisterClass(&wc))
    {
        Logger::Error("Failed to register window class. Error code: %lu", GetLastError());
        return;
    }

    hSplashBitmap = LoadBitmap(hInstanceGlobal, MAKEINTRESOURCE(IDR_SPLASH_IMAGE));

    if (!hSplashBitmap)
    {
        Logger::Error("Failed to load splash image from resources. Error code: %lu", GetLastError());
        return;
    }

    RECT screenRect;
    if (!SystemParametersInfo(SPI_GETWORKAREA, 0, &screenRect, 0))
    {
        Logger::Error("Failed to get screen dimensions. Error code: %lu", GetLastError());
        return;
    }

    int splashWidth = 800;
    int splashHeight = 207;

    int x = (screenRect.right - splashWidth) / 2;
    int y = (screenRect.bottom - splashHeight) / 2;

    hSplashWnd = CreateWindowEx(
        0,
        CLASS_NAME,
        L"nosSplashForm_F",
        WS_POPUP | WS_VISIBLE,
        x, y, splashWidth, splashHeight,
        nullptr,
        nullptr,
        hInstanceGlobal,
        nullptr
    );

    if (!hSplashWnd)
    {
        Logger::Error("Failed to create splash window. Error code: %lu", GetLastError());
        DeleteObject(hSplashBitmap);
        hSplashBitmap = nullptr;
        return;
    }

    ShowWindow(hSplashWnd, SW_HIDE);
    UpdateWindow(hSplashWnd);
}

void NosTale::onFreeNostaleSplash() noexcept
{
    if (hSplashWnd)
    {
        ShowWindow(hSplashWnd, SW_HIDE); // Hide the splash screen
        // Optionally, you could call UpdateWindow to ensure the change is applied immediately
        UpdateWindow(hSplashWnd);
    }
    if (hSplashBitmap)
    {
        DeleteObject(hSplashBitmap);
        hSplashBitmap = nullptr;
    }
}

LRESULT CALLBACK SplashWndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
    switch (msg)
    {
    case WM_PAINT:
    {
        PAINTSTRUCT ps;
        HDC hdc = BeginPaint(hwnd, &ps);

        HDC hdcMem = CreateCompatibleDC(hdc);
        if (!hdcMem)
        {
            Logger::Error("Failed to create compatible DC for painting. Error code: %lu", GetLastError());
            EndPaint(hwnd, &ps);
            return -1;
        }

        HBITMAP hbmOld = (HBITMAP)SelectObject(hdcMem, hSplashBitmap);
        BITMAP bm;
        GetObject(hSplashBitmap, sizeof(bm), &bm);
        BitBlt(hdc, 0, 0, bm.bmWidth, bm.bmHeight, hdcMem, 0, 0, SRCCOPY);
        SelectObject(hdcMem, hbmOld);
        DeleteDC(hdcMem);

        EndPaint(hwnd, &ps);
    }
    break;
    case WM_CLOSE:
        DestroyWindow(hwnd);
        break;
    case WM_DESTROY:
        hSplashWnd = nullptr;
        PostQuitMessage(0);
        break;
    default:
        return DefWindowProc(hwnd, msg, wParam, lParam);
    }
    return 0;
}

void NosTale::tick() noexcept
{
    nosbazarMng.Tick();
    channelSelectionMng.Tick();
    nostaleDiscordMng.Tick();
    warpMod.Tick();
}
