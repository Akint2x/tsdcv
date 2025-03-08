#pragma once
#include <stdint.h>
#pragma pack(push, 1)

class Position
{
public:
	int16_t x;
	int16_t y;
};
static_assert(sizeof(Position) == 0x4, "Position size isn't 0x4.");
static_assert(sizeof(Position) <= 0x4, "Position size is upper than 0x4.");
static_assert(sizeof(Position) >= 0x4, "Position size is lower than 0x4.");

#pragma pack(pop) 