#pragma once
#include "TObject.h"
#pragma pack(push, 1)

template<class T>
class TBaseList : public TObject
{
public:

protected:
	char unknown1[0x1C]; // 0x04
};
static_assert(sizeof(TBaseList<void*>) == 0x20, "TBaseList does not have a size of 0x20.");

#pragma pack(pop)
