#pragma once
#include "TObject.h"
#include "ClassSearcher.h"
#pragma pack(push, 1)

class TPersistent : public TObject
{
public:

protected:
};
static_assert(sizeof(TPersistent) == 0x04, "TPersistent does not have a size of 0x04.");

#pragma pack(pop)
