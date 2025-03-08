#include "NosbazarManager.h"
#include "../MemoryHelper/Patch.h"
#include "../Api/DelphiClasses/TNTConsignmentWidget.h"
#include "../Api/DelphiClasses/TEWEditWidget.h"
#include "../Api/DelphiClasses/TEWControlWidgetMouseEvent.h"

namespace
{
	uintptr_t jmpbackKeyPressReturn, jmpbackKeyPressOriginal;
	uintptr_t fnSearchNb;
	TNTConsignmentWidget* nbWidget;

	void __declspec(naked) hk_onKeyPress() noexcept
	{
		__asm
		{
			mov ebx, eax;
			mov ax, [ecx];

			cmp ax, 0x0D;
			jne backOri;

			pushad;
			pushfd;

			mov eax, nbWidget;
			call fnSearchNb;

			popfd;
			popad;

			jmp jmpbackKeyPressReturn;

		backOri:
			jmp jmpbackKeyPressOriginal;
		}
	}
}

NosbazarManager::NosbazarManager(const NosbazarManagerConfig& Config) noexcept
	: Manager(Config, "NosbazarManager")
{}

bool NosbazarManager::initialize() noexcept
{
	if (!config.Activated)
		return true;

	void* pattern = PatternScan("\xff\x52\x50\x66\x83\x00\x00\x00\x00\x00\x00\x74\x00\x8b\xd3\x8b\x00\x00\x00\x00\x00\xff\x00\x00\x00\x00\x00\x5b\xc3",
		"xxxxx?????xx?xxx?????x?????xx", 11);
	if (pattern == nullptr)
	{
		Logger::Error("pattern is nullptr");
		return false;
	}
	if (!PatchSingleByte((BYTE*)pattern, (BYTE)'\xEB'))
	{
		Logger::Error("Failed patching pattern: %x", pattern);
		return false;
	}
	Logger::Log("pattern: %x", pattern);

	void* fnPattern = PatternScan("\x55\x8b\xec\x33\xc9\x51\x51\x51\x51\x53\x8b\xd8\x33\xc0\x55\x68\x00\x00\x00\x00\x64\xff\x30\x64\x89\x20\x80\x00\x00\x00\x00\x00\x00\x0f\x85\x00\x00\x00\x00",
		"xxxxxxxxxxxxxxxx????xxxxxxx?????xxx????", 0);
	if (fnPattern == nullptr)
	{
		Logger::Error("fnPattern is nullptr");
		return false;
	}
	Logger::Log("fnPattern: %x", fnPattern);
	fnSearchNb = (uintptr_t)fnPattern;

	void* delayPattern = PatternScan("\x53\x8b\xd8\x8b\xc3\xe8\x00\x00\x00\x00\xe8\x00\x00\x00\x00\x8b\x00\x00\x00\x00\x00\x81\xc2\xb8\x0b\x00\x00\x3b\xc2",
		"xxxxxx????x????x?????xxxxxxxx", 23);
	if (delayPattern == nullptr)
	{
		Logger::Error("delayPattern is nullptr");
		return false;
	}
	Logger::Log("delayPattern: %x", delayPattern);

	if (!Patch((BYTE*)delayPattern, (BYTE*)&config.SearchDelay, 4))
	{
		Logger::Error("Failed patching delay");
		return false;
	}

	nbWidget = TNTConsignmentWidget::getNtInstance();
	TEWControlWidgetMouseEvent* nbBody = nbWidget->getBodyWidget();

	std::vector<TLBSWidget*> widgets = nbBody->findClassesWithExpectedSize(TEWEditWidget::NAME, 1);
	if (widgets.size() == 0)
		return false;

	TEWEditWidget* searchEditWidget = reinterpret_cast<TEWEditWidget*>(widgets[0]);
	Logger::Log("searchEditWidget: %x", searchEditWidget);

	int32_t funcAddr = searchEditWidget->getOnKeyPressCallback().getFunc() + 4;
	if (!Hook((BYTE*)funcAddr, (BYTE*)hk_onKeyPress, 5))
	{
		Logger::Error("Failed hooking");
		return false;
	}

	jmpbackKeyPressOriginal = funcAddr + 5;
	Logger::Log("jmpbackKeyPressOriginal = %x", jmpbackKeyPressOriginal);

	jmpbackKeyPressReturn = (uintptr_t)PatternScan("\x5b\x5d\xc2\x04\x00",
		"xxxxx", 0,
		(uint32_t)funcAddr
	);
	if (jmpbackKeyPressReturn == NULL)
	{
		Logger::Error("Failed scanning pattern");
		return false;
	}
	Logger::Log("jmpbackKeyPressReturn = %x", jmpbackKeyPressReturn);

	Logger::Success("Successfully initialized");
	return true;
}

bool NosbazarManager::unload() noexcept
{
	return false;
}

void NosbazarManager::tick() noexcept
{}
