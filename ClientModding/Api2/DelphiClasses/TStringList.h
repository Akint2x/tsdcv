#pragma once
#include "TStrings.h"
#include "ClassSearcher.h"
#include "../Properties/Logical/String.h"
#include <vector>
#pragma pack(push, 1)

struct StringFollowedByFourZeros
{
    StringFollowedByFourZeros() noexcept {}
    StringFollowedByFourZeros(const std::string& Str) noexcept
    {
        String* sStr = new String(Str.c_str());
        str = sStr->get();
    }

    [[nodiscard]] std::string toString()
    {
        return str;
    }

    char* str{ }; // ref counted + size non-null terminated str (TODO: class)
    char* fourZeros{ }; // Seems to always be 00 00 00 00
};

class TStringList : public TStrings
{
public:
    static constexpr std::string_view NAME = "TStringList";

    TStringList()
    {
        vTable = ClassSearcher::GetClassInfoFromName("TStringList").GetVTable();
    }

    uint32_t size() const { return length; }
    uint32_t getCapacity() const { return capacity; }
    
    [[nodiscard]] StringFollowedByFourZeros getItem(int index) noexcept
    {
        if (index >= length || index < 0)
            return StringFollowedByFourZeros{};
        return items[index];
    }
    
    [[nodiscard]] std::vector<StringFollowedByFourZeros> getItems() noexcept
    {
        std::vector<StringFollowedByFourZeros> output;
        output.reserve(length);

        for (int i = 0; i < length; i++)
            output.push_back(items[i]);

        return output;
    }

protected:
    StringFollowedByFourZeros* items;   // 0x10
    uint32_t length;                    // 0x14
    int32_t capacity;                   // 0x18
    bool isSorted;                      // 0x1C
    bool hasDuplicates;                 // 0x1D
    bool isCaseSensitive;               // 0x1E
    uint8_t pad_001F[1];                // 0x1F
    void* onChange;                     // 0x20
    uint8_t pad_0024[4];                // 0x24
    void* onChanging;                   // 0x28
    uint8_t pad_002C[4];                // 0x2C

};
static_assert(sizeof(TStringList) == 0x30, "TStringList does not have a size of 0x30.");

#pragma pack(pop)
