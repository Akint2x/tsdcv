#pragma once
#include "TEWLabels.h"
#include "../Properties/Graphical/TextPosition.h"
#include "../Properties/Graphical/TextStyle.h"
#include "../Properties/Logical/String.h"
#pragma pack(push, 1)

class TStringList;

class TEWStringListViewCore : public TEWLabels
{
public:
    
    [[nodiscard]] TStringList* getLines() noexcept { return lines; }
    [[nodiscard]] void setLines(TStringList* Lines) noexcept { lines = Lines; }

protected:
    TStringList* _last_message;       // 0x0088
    TStringList* _unknown_list;       // 0x008C
    TStringList* lines;               // 0x0090
    TStringList* _unknown_list2;      // 0x0094
    int32_t      _current_line;             // 0x0098 related to scroll
    int32_t      _count;                    // 0x009C nb of lines remaining through scroll
    uint8_t      _pad_00A0[16];             // 0x00A0
    // 0xA4 = pointer to an array of TextStyle (pointer to array, not pointer to array of pointers)
    // 0xAC = something like nb of TextStyle in the ptr
};
static_assert(sizeof(TEWStringListViewCore) == 0xB0, "TEWStringListViewCore does not have a size of 0xB0.");

#pragma pack(pop)
