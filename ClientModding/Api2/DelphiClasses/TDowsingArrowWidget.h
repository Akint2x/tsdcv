#pragma once
#include "TEWControlWidget.h"
#pragma pack(push, 1)

template<typename T> class TNTIntHeadList;

class TDowsingArrowWidget : public TEWControlWidget
{
public:

protected:
	TNTIntHeadList<void*>* list; // It is not void* but something that stores int16_t posX, int16_t posY, int32_t mapId and maybe some other data - can it be used to exploit hidden TS research?
};
static_assert(sizeof(TDowsingArrowWidget) == 0x6C, "TDowsingArrowWidget does not have a size of 0x6C.");

#pragma pack(pop)
