#pragma once
#include "TEWStringListViewCore.h"
#pragma pack(push, 1)

class TEWStringListView : public TEWStringListViewCore
{
public:
	static constexpr std::string_view NAME = "TEWStringListView";

protected:
    
};
static_assert(sizeof(TEWStringListView) == 0xB0, "TEWStringListView does not have a size of 0xB0.");

#pragma pack(pop)
