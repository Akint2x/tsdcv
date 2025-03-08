#pragma once
#include "TNTNonMemIntHeadList.h"
#include "../../MemoryHelper/PatternScan.h"
#include "../Properties/Graphical/IconProperties.h"
#pragma pack(push, 1)

class TNTCItemDataList : public TNTNonMemIntHeadList<ItemDataProperties>
{
public:
	TNTCItemDataList() : TNTNonMemIntHeadList<ItemDataProperties>() {}
	TNTCItemDataList(uint32_t Capacity) : TNTNonMemIntHeadList<ItemDataProperties>(Capacity) {}

	static TNTCItemDataList* getNtInstance() noexcept
	{
		static void* patternAddr = nullptr;

		if (patternAddr == nullptr)
		{
			auto _ = Logger::PushPopModuleName("TNTCItemDataList");

			patternAddr = PatternScan(
				"\xe8\x00\x00\x00\x00\x8b\x55\xa0\x58\xe8\x00\x00\x00\x00\x75\x00\xa1\x00\x00\x00\x00\x8b\x10\xff\x52\x08\x8b\xd7\xa1\x00\x00\x00\x00\xe8\x00\x00\x00\x00",
				"x????xxxxx????x?x????xxxxxxxx????x????", 17
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
		return **(TNTCItemDataList***)patternAddr;
	}

    [[nodiscard]] static IconProperties* createItemFromImageId(int ImageId, int8_t offset = 0)
    {
        static void* fnCreateItem = nullptr;

        if (fnCreateItem == nullptr)
        {
            auto _ = Logger::PushPopModuleName("TNTCItemDataList");

            fnCreateItem = PatternScan(
                "\x55\x8B\xEC\x53\x56\x57\x8B\xF9\x8B\xDA\x83\x3B\x00",
                "xxxxxxxxxxxxx"
            );
            if (fnCreateItem == nullptr)
            {
                Logger::Error("Failed scanning pattern");
                return nullptr;
            }
            Logger::Log("fnCreateItem = %x", fnCreateItem);

            Logger::Success("Successfully initialized");
        }

        IntListElement<ItemDataProperties>* item = TNTCItemDataList::getNtInstance()->findItemByImageId(ImageId, offset);

        ItemDataProperties* itemDataProps = new ItemDataProperties();
        IconProperties* iconProp = new IconProperties(ImageId);

       // iconProp->setItemProperties(reinterpret_cast<ItemDataProperties*>(item));

        //idk. it should work
        /*IconProperties* iconProp = new IconProperties();
        IntListElement<ItemDataProperties>* item = TNTCItemDataList::getNtInstance()->findItemByImageId(ImageId, offset);
        if (item)
        {
            ItemDataProperties* itemDataProps = new ItemDataProperties(item->getValue());
            iconProp->setImageId(static_cast<int16_t>(ImageId));
            iconProp->setItemProperties(itemDataProps);
        }
        else
        {
            ItemDataProperties* itemDataProps = new ItemDataProperties();
        }*/



        // Log the found item's data
        /*Logger::Log("Found item with ImageId %d:", ImageId);
        Logger::Log("  Name: %s", item->getValue().getName());
        Logger::Log("  Level: %d", item->getValue().getLevel());
        Logger::Log("  ImageId: %d", item->getValue().getImageId());
        Logger::Log("  Description: %s", item->getValue().getDescription());*/

        /*ItemDataProperties* itemDataProps = new ItemDataProperties(item->getValue());
        IconProperties* iconProp = new IconProperties();
        iconProp->setImageId(static_cast<int16_t>(ImageId));
        iconProp->setItemProperties(itemDataProps);*/

        // Verify the data was set correctly
        //Logger::Log("Verifying IconProperties data:");
        //Logger::Log("  ImageId: %d", iconProp->getImageId());
        //if (iconProp->getItemProperties() != nullptr)
        //{
        //    Logger::Log("  Item Properties:");
        //    Logger::Log("    Name: %s", iconProp->getItemProperties()->getName());
        //    Logger::Log("    Level: %d", iconProp->getItemProperties()->getLevel());
        //    Logger::Log("    ImageId: %d", iconProp->getItemProperties()->getImageId());
        //    Logger::Log("    Description: %s", iconProp->getItemProperties()->getDescription());
        //}
        //else
        //{
        //    Logger::Error("  Item Properties is null!");
        //}


        uintptr_t vtable = ClassSearcher::GetClassInfoFromName("TNTItemList").GetVTable(); // TNTItemList, not TNTCItemDataList

        __asm
        {
            pushad;
            pushfd;

            push ImageId;
            mov edx, iconProp;
            mov ecx, item;
            mov eax, vtable;

            call fnCreateItem;

            popfd;
            popad;
        }

        return iconProp;
    }

    [[nodiscard]] static IconProperties* createItemFromVnum(int Vnum, int8_t offset = 0)
    {
        int imgId = TNTCItemDataList::getNtInstance()->getImageIdFromVnum(Vnum);

        return TNTCItemDataList::getNtInstance()->createItemFromImageId(imgId, offset);
    }

    [[nodiscard]] IntListElement<ItemDataProperties>* findItemByImageId(int ImageId, int8_t offset = 0)
    {
        for (auto i = 0; i < length; i++)
        {
            if (items[i]->getValue().getImageId() == ImageId)
            {
                if (offset == 0)
                    return items[i];
                offset--;
            }
        }
        return nullptr;
    }

    [[nodiscard]] ItemDataProperties* findItemPtr(int imageId)
    {
        for (auto i = 0; i < length; i++)
        {
            if (items[i]->getValue().getVnumOffset_0x4() == imageId)
            {
                ItemDataProperties* item = new ItemDataProperties(items[i]->getValue());
                return item;
            }
        }
        return nullptr;
    }

    [[nodiscard]] int getImageIdFromVnum(int Vnum)
    {
        for (auto i = 0; i < length; i++)
        {
            if (items[i]->getValue().getVnumOffset_0x4() == Vnum)
                return items[i]->getValue().getImageId();
        }
        return -1;
    }
};
static_assert(sizeof(TNTCItemDataList) == 0x10, "TNTCItemDataList does not have a size of 0x10.");

#pragma pack(pop)
