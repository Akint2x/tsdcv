#pragma once
#pragma pack(push, 1)
#include <stdint.h>

class ItemDataProperties
{
public:
    [[nodiscard]] int16_t getImageId() noexcept { return imageId; }
    int getVnumOffset_0x4() const {
        return imageId;
    }

    [[nodiscard]] char* getName() noexcept { return name; }
    [[nodiscard]] int16_t getLevel() noexcept { return level; }
    [[nodiscard]] int16_t getItemType() noexcept { return itemType; }
    [[nodiscard]] int16_t getItemSubType() noexcept { return itemSubType; }
    [[nodiscard]] char* getDescription() noexcept { return _item_description; }

private:
    // Every offset are + 0x4 because there is an id (IntListElement) before every variables
    int32_t unknown1; // 0x04
    int16_t level; // 0x08
    int16_t unknown2; // 0x0A Probably padding
    int32_t unknown3; // 0x0C
    int32_t unknown4; // 0x10
    int32_t unknown5; // 0x14
    int32_t unknown6; // 0x18
    int32_t unknown7; // 0x1C
    int32_t unknown8; // 0x20
    int32_t unknown9; // 0x24
    int32_t unknown10; // 0x28
    int32_t unknown11; // 0x2C
    int32_t unknown12; // 0x30
    int32_t unknown13; // 0x34
    char* name; // 0x38 Note: not a delphi string
    int32_t unknown14; // 0x3C
    int32_t unknown15; // 0x40
    int32_t unknown16; // 0x44
    int16_t unknown17; // 0x46
    int16_t imageId; // 0x48
    char pad_0x004C[0x4]; //0x004C
    __int8 Female; //0x0050
    __int8 Male; //0x0051
    char pad_0x0052[0x3]; //0x0052
    __int8 _item_hero; //0x0055
    __int8 _item_level; //0x0056
    char pad_0x0057[0x3]; //0x0057
    __int16 itemType; //0x005A
    __int16 itemSubType; //0x005C
    char pad_0x005E[0x6]; //0x005E
    __int8 Class; //0x0064
    char pad_0x0065[0x3]; //0x0065
    char* _item_description; //0x0068 
    char pad_0x006C[0xF4]; //0x006C
    // All those variables seems to be NSgtdData.NOS > Item.dat
};

class IconProperties
{
public:
    [[nodiscard]] explicit IconProperties() noexcept {}
    [[nodiscard]] explicit IconProperties(int16_t Vnum) noexcept
    {
        imageId = Vnum;
    }

    void setImageId(int16_t ImageId) noexcept { imageId = ImageId; }
    void setType(int8_t Type) noexcept { type = Type; }
    void setRarity(int8_t Rarity) noexcept { rarity = Rarity; }
    void setUpgrade(int8_t Upgrade) noexcept { upgrade = Upgrade; }
    void setCarveRunes(int32_t CarveRunes) noexcept { carveRunes = CarveRunes; }
    void setItemProperties(ItemDataProperties* ItemProp) noexcept { itemProp = ItemProp; }

    [[nodiscard]] int16_t getImageId() noexcept { return imageId; }
    [[nodiscard]] int8_t getType() noexcept { return type; }
    [[nodiscard]] int8_t getRarity() noexcept { return rarity; }
    [[nodiscard]] int8_t getUpgrade() noexcept { return upgrade; }
    [[nodiscard]] int32_t getCarveRunes() noexcept { return carveRunes; }
    [[nodiscard]] ItemDataProperties* getItemProperties() noexcept { return itemProp; }

private:
    int32_t unknown1; // 0x00
    int32_t unknown2; // 0x04
    ItemDataProperties* itemProp; // 0x08
    int16_t imageId; // 0x0c
    int16_t unknown3; // 0x0e Not padding, it is actually used
    int8_t type; // 0x10 Upgrade somewhere but lazy.
    char unknown8[3]; // 0x11
    int32_t unknown4; // 0x14
    int32_t unknown5; // 0x18
    int32_t _inventoryType; // 0x1C
    char unknown7[2]; // 0x20
    int8_t rarity; // 0x22
    int8_t upgrade; // 0x23
    int32_t unknown9; // 0x24
    int32_t unknown10; // 0x28
    int32_t unknown11; // 0x2C
    int32_t unknown12; // 0x30
    int32_t unknown13; // 0x34
    int32_t carveRunes; // 0x38
    int32_t unknown14; // 0x3C
    int32_t unknown15; // 0x40
    int32_t unknown16; // 0x44
};
static_assert(sizeof(IconProperties) == 0x48, "IconProperties does not have a size of 0x48.");

#pragma pack(pop)