#pragma once
#include <stdint.h>

enum class RarityType : int8_t
{
	DAMAGED = -2,
	LOW_LEVEL = -1,
	_ = 0,
	USEFUL = 1,
	GOOD = 2,
	HIGH_QUALITY = 3,
	EXCELLENT = 4,
	ANCIENT = 5,
	MYSTERIOUS = 6,
	LEGENDARY = 7,
	PHENOMENAL = 8,
	MYTHIC = 9,
	DIVINE = 10,
	ARCANE = 11,
	ENCHANTED = 12,
	CELESTIAL = 13,
	ETERNAL = 14,
	PRIMORDIAL = 15

};
