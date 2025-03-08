// https://github.com/ApourtArtt/DelphiClassInfo

#pragma once
#include <string>
#include <map>
#include <vector>
#include <Windows.h>
#include <Psapi.h>
#include "../../Utils/Logger.h"
#include "../../Utils/Obfuscator.h"

#ifndef OBFUSCATOR_H
#define OBFUSCATOR_H
#define _xor(str) str
#endif

class ClassInfo
{
public:
	ClassInfo() : size(0), addrPtrVTable(0), addrPtrName(0) {}
	ClassInfo(const std::string& Name, uint32_t Size, uintptr_t AddrPtrVTable, uintptr_t AddrPtrName)
		: name(Name)
		, size(Size)
		, addrPtrVTable(AddrPtrVTable)
		, addrPtrName(AddrPtrName)
	{}

	const std::string& GetName() const				{ return name; }
	const uint32_t GetClassSize() const				{ return size; }
	const uintptr_t GetAddressPtrVTable() const		{ if (addrPtrVTable == 0) return 0; return addrPtrVTable; }
	const uintptr_t GetVTable() const				{ if (addrPtrVTable == 0) return 0; return *(uintptr_t*)addrPtrVTable; }
	const uintptr_t GetAddressPtrName() const		{ if (addrPtrName == 0) return 0; return  addrPtrName + 1; }
	const uintptr_t GetNameAddress() const			{ if (addrPtrName == 0) return 0; return *(uintptr_t*)(addrPtrName + 1); }

private:
	std::string name{ _xor("Not implemented") };
	uint32_t size;
	uintptr_t addrPtrVTable;
	uintptr_t addrPtrName;
};

class ClassSearcher
{
public:
	[[nodiscard]] static bool Initialize()
	{
		auto _ = Logger::PushPopModuleName(_xor("ClassSearcher"));

		std::vector<std::string> classesName{
			_xor("TBaseList"),
			_xor("TBuddyChatWidget"),
			_xor("TByteList"),
			_xor("TDowsingArrowWidget"),
			_xor("TEWButtonWidget"),
			_xor("TEWCaptionBar"),
			_xor("TEWControlWidget"),
			_xor("TEWControlWidgetEvent"),
			_xor("TEWControlWidgetEX"),
			_xor("TEWControlWidgetMouseEvent"),
			_xor("TEWCustomButtonWidget"),
			_xor("TEWCustomFormWidget"),
			_xor("TEWCustomPanelWidget"),
			_xor("TEWEditWidget"),
			_xor("TEWFormWidget"),
			_xor("TEWGraphicButtonWidget"),
			_xor("TEWLabel"),
			_xor("TEWLabels"),
			_xor("TEWMoveWidget"),
			_xor("TEWParentMoveWidget"),
			_xor("TEWRollOverButtonWidget"),
			_xor("TEWScrollBar"),
			_xor("TEWScrollBarThumb"),
			_xor("TEWScrollBarTrack"),
			_xor("TEWStringListView"),
			_xor("TEWStringListViewCore"),
			_xor("TGameRootWidget"),
			_xor("TImpossibleIconWidget"),
			_xor("TLBSCamera"),
			_xor("TLBSMultiTextureCache"),
			_xor("TLBSMultiTextureList"),
			_xor("TLBSRotDamper"),
			_xor("TLBSWidget"),
			_xor("TLBSWidgetHandler"),
			_xor("TLBSWidgetList"),
			_xor("TList"),
			_xor("TMapMonsterObj"),
			_xor("TMapMoveObjBase"),
			_xor("TMapNpcObj"),
			_xor("TMapObjBase"),
			_xor("TMapPlayerObj"),
			_xor("TMiniMapCore"),
			_xor("TMiniMapWidget"),
			_xor("TNaviChatViewer"),
			_xor("TNaviMultiSelect"),
			_xor("TNaviNameViewer"),
			_xor("TNaviWidget"),
			_xor("TNosTaleGame"),
			_xor("TNTBottomMainUIWidget"),
			_xor("TNTCharacterSummaryInfoWidget"),
			_xor("TNTCharacterInventoryInfoWidget"),
			_xor("TNTChatEditWidget"),
			_xor("TNTCItemDataList"),
			_xor("TNTCommonInfoBoard"),
			_xor("TNTConsignmentWidget"),
			_xor("TNTConstStringList"),
			_xor("TNTCoverIcon"),
			_xor("TNTCustomMessageCoreWidget"),
			_xor("TNTDataList"),
			_xor("TNTGameOptionWidget"),
			_xor("TNTHintWidget"),
			_xor("TNTIconWidget"),
			_xor("TNTIndividualShop"),
			_xor("TNTIntHeadList"),
			_xor("TNTItemExchangeWidget"),
			_xor("TNTItemList"),
			_xor("TNTLoginWidget"),
			_xor("TNTMaskingGaugeWidget"),
			_xor("TNTMiniMapWidget"),
			_xor("TNTMonsterSummaryInfoWidget"),
			_xor("TNTNewCharacterSkillInfoWidget"),
			_xor("TNTNewCharacterStandardInfoWidget"),
			_xor("TNTNewCommonInfoWidget"),
			_xor("TNTNewFamilyInfoWidget"),
			_xor("TNTNewServerSelectWidget2"),
			_xor("TNTNonMemIntHeadList"),
			_xor("TNTPartySummaryInfoWidget"),
			_xor("TNTQuestSimpleViewer"),
			_xor("TNTQuickSlotWidget"),
			_xor("TNTRuneUpgradeWidget"),
			_xor("TNTSpecialaListInfoWidget"),
			_xor("TNTSpecialDragonFx"),
			_xor("TNTSpecialWingFx"),
			_xor("TNTTimeAniIcon"),
			_xor("TNTTaskBarWidget"),
			_xor("TNTTatooUpgradeWidget"),
			_xor("TNTWebBrowserFormWidget"),
			_xor("TNTUnitManager"),
			_xor("TObject"),
			_xor("TPersistent"),
			_xor("TPetSelectIcon"),
			_xor("TPlayerObjManager"),
			_xor("TReadyWidget"),
			_xor("TSceneManager"),
			_xor("TSmallIntList"),
			_xor("TStringList"),
			_xor("TStrings"),
			_xor("TSvrCtlObjManager"),
		};

		MODULEINFO mInfo = { 0 };
		HMODULE hModuleExe = GetModuleHandle(nullptr);
		if (hModuleExe == 0)
		{
			Logger::Error(_xor("Failed getting module handle"));
			return false;
		}
		GetModuleInformation(GetCurrentProcess(), hModuleExe, &mInfo, sizeof(MODULEINFO));
		DWORD base = (DWORD)mInfo.lpBaseOfDll;
		DWORD size = (DWORD)mInfo.SizeOfImage;
		data.resize(size);
		memcpy(data.data(), (char*)base, size);

		for (size_t i = 0; i < classesName.size(); i++)
		{
			std::string pattern = getPattern(classesName[i]);
			int pos = data.find(pattern);
			if (pos == std::string::npos)
			{
				Logger::Error(_xor("Failed finding class %s"), classesName[i].c_str());
				return false;
			}
			int addr = base + pos;

			for (int32_t j = addr - 4;; j--)
			{
				if (j < base)
				{
					Logger::Error(_xor("Failed finding class %s"), classesName[i].c_str());
					return false;
				}
				if (*(int32_t*)j == addr)
				{
					ClassInfo ci(classesName[i], *(int32_t*)(j + 4), j - 0x20, *(int32_t*)j);
					classesInfo.emplace(classesName[i], ci);
					Logger::Log(_xor("Class %s = 0x%x/0x%x (Sz=0x%x)"), ci.GetName().c_str(), ci.GetAddressPtrVTable(), ci.GetVTable(), ci.GetClassSize());
					break;
				}
			}
		}

		Logger::Success(_xor("Successfully initialized"));
		return true;
	}

	static const ClassInfo& GetClassInfoFromName(const std::string& ClassName)
	{
		return classesInfo[ClassName];
	}

	static const ClassInfo GetClassInfoFromAddress(uintptr_t ClassAddress)
	{
		for (auto& [k, v] : classesInfo)
		{
			if (v.GetVTable() == ClassAddress)
				return v;
		}
		return ClassInfo{};
	}

private:
	static std::string getPattern(const std::string& className)
	{
		std::string pattern;
		pattern += className.size();
		pattern += className;
		return pattern;
	}

	inline static std::string data;
	inline static std::map<std::string, ClassInfo> classesInfo;
};
