#pragma once
#include "TObject.h"
#include "../Properties/Logical/MapGrid.h"
#include "../../MemoryHelper/PatternScan.h"
#include "../../Utils/Logger.h"
#pragma pack(push, 1)

class TMapPlayerObj;
class TSvrCtlObjManager;
class TLBSBkFxItem;
class TLBSCamera;
template<typename T> class TList;

class TSceneManager : public TObject
{
public:
	static constexpr std::string_view NAME = "TSceneManager";

	[[nodiscard]] MapGrid* getMapGrid() { return mapGrid; }
	[[nodiscard]] TLBSCamera* getCamera() { return camera; }
	[[nodiscard]] int16_t getWindowWidth() { return windowWidth; }
	[[nodiscard]] int16_t getWindowHeight() { return windowHeight; }
    [[nodiscard]] int32_t getPlayerId() { return playerID; }
    [[nodiscard]] TMapPlayerObj* getPlayerObj() { return mapPlayerObjPtr; }

	[[nodiscard]] static TSceneManager* getNtInstance()
	{
		static void* patternAddr = nullptr;

		if (patternAddr == nullptr)
		{
			auto _ = Logger::PushPopModuleName(NAME.data());

			patternAddr = PatternScan(
				"\xA1\x00\x00\x00\x00\x00\x00\x00\x00\x58\x00\x0F\x84\xBF",
				"x????????xxxxx", 1
			);
			if (patternAddr == nullptr)
			{
				Logger::Error("Failed scanning pattern");
				return nullptr;
			}
			Logger::Log("patternAddr = %x", patternAddr);

			Logger::Success("Successfully initialized");
		}
		
		// Note: if it gets delete-d and new-ed, a refresh of the dereferenced address will be required.
		// Since I don't know if this object ever gets deleted (I HIGHLY doubt it), I am not handling it.
		return ***(TSceneManager****)patternAddr;
	}

private:
    void* playerListPtr;                    // 0x04 TObjAtkTimeArr
    void* monsterListPtr;                   // 0x08 MapObjectBaseList
    void* npcListPtr;                       // 0x0C
    void* itemListPtr;                      // 0x10
    void* unknownPtr1;                      // 0x14
    void* unknownPtr2;                      // 0x18
    void* unknownPtr3;                      // 0x1C TLBSBkFxList
    MapGrid* mapGrid;                       // 0x20
    int32_t timestamp;                      // 0x24
    char unknownn[4];                       // 0x28
    int32_t playerID;                       // 0x2C
    TMapPlayerObj* mapPlayerObjPtr;         // 0x30
    char pad_0034[8];                       // 0x34
    TSvrCtlObjManager* objManager;          // 0x3C
    char pad_0040[8];                       // 0x40 Camera related change when move with right click
    char pad_0048[4];                       // 0x48 Set to 0 every tick
    int16_t cursorPosX;                     // 0x4C Unchanged when widget which handle click is on foreground
    int16_t cursorPosY;                     // 0x4E Unchanged when widget which handle click is on foreground
    int16_t windowWidth;                    // 0x50
    int16_t windowHeight;                   // 0x52
    int16_t targetSkillX;                   // 0x54 ?????
    int16_t targetSkillY;                   // 0x56 ?????
    bool cursorIsOnScreen;                  // 0x58
    char pad_0059[3];                       // 0x59 zeros
    char pad_005C[12];                      // 0x5C related to cursor deplacement
    char pad_0068[4];                       // 0x68 related to cursor deplacement
    TLBSCamera* camera;                     // 0x6C
    TList<void*>* unknownPtr5;              // 0x70
    TList<void*>* unknownPtr6;              // 0x74
    TList<void*>* unknownPtr7;              // 0x78
    TList<void*>* unknownPtr8;              // 0x7C
    TList<void*>* unknownPtr9;              // 0x80
    TList<TLBSBkFxItem*>* fxList;           // 0x84 NOT a TLBSBkFxList
    char pad_0088[12];                      // 0x88
    void* unknownPtr11;                     // 0x94
    int16_t unknownInt;                     // 0x98
    char pad_009C[6];                       // 0x9A
};
static_assert(sizeof(TSceneManager) == 0xA0, "TSceneManager does not have a size of 0xA0");

#pragma pack(pop)
