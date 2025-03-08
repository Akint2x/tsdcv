#pragma once
#include "TNTDataList.h"
#include "../../Api/Properties/Graphical/IconProperties.h"
#pragma pack(push, 1)

// TODO: Find uknown values (probably 2 integers)

class Item
{
public:
	IconProperties* getIconProp() { return iconProperties; }
	void setRightClickWidgetType(int8_t type) { rightClickWidgetType = type; }

protected:
	IconProperties* iconProperties;		//0x00
	int8_t rightClickWidgetType;		//0x04 0-1 = invisible / 2 = big / 3 = small / 4 = medium / 5 = small / 6 = medium / 7 = big
	char unknown[3];					//0x05
	int32_t currentListIndex;			//0x08 Not sure about the size of int
	char unknown2[0x4C - 12];			//0x0C
};
static_assert(sizeof(Item) == 0x4C, "Item does not have a size of 0x4C.");

class TNTItemList : public TNTDataList<Item*>
{
public:
	
protected:
	char uknown[8];
};
static_assert(sizeof(TNTItemList) == 0x18, "TNTItemList does not have a size of 0x18.");

#pragma pack(pop)