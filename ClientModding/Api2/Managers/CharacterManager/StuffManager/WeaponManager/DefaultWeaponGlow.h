#pragma once
#include "WeaponConfig.h"

WeaponGlow defaultNoGlow
{
	.SecondaryGlowColor = Bgra(0, 0, 0, 0),
	.SecondaryGlowSize = 0.,
	.SecondaryGlowStyle = WeaponGlowingStyle::NO_GLOWING,
	.PrimaryGlowColor = Bgra(0, 0, 0, 0),
	.PrimaryGlowSize = 0.,
	.PrimaryGlowStyle = WeaponGlowingStyle::NO_GLOWING,
};

upgradeToGlow defaultSubLegendaryWeaponGlows =
{
	{
		0, defaultNoGlow
	},
	{
		1, WeaponGlow
		{
			.SecondaryGlowColor = Bgra(0, 0, 0, 0),
			.SecondaryGlowSize = 0.,
			.SecondaryGlowStyle = WeaponGlowingStyle::NO_GLOWING,
			.PrimaryGlowColor = Bgra(0, 0, 255, 128),
			.PrimaryGlowSize = 1.,
			.PrimaryGlowStyle = WeaponGlowingStyle::SLOW_CIRCULAR,
		}
	},
	{
		2, WeaponGlow
		{
			.SecondaryGlowColor = Bgra(0, 0, 0, 0),
			.SecondaryGlowSize = 0.,
			.SecondaryGlowStyle = WeaponGlowingStyle::NO_GLOWING,
			.PrimaryGlowColor = Bgra(0, 255, 0, 80),
			.PrimaryGlowSize = 1.,
			.PrimaryGlowStyle = WeaponGlowingStyle::SLOW_CIRCULAR,
		}
	},
	{
		3, WeaponGlow
		{
			.SecondaryGlowColor = Bgra(0, 0, 0, 0),
			.SecondaryGlowSize = 0.,
			.SecondaryGlowStyle = WeaponGlowingStyle::NO_GLOWING,
			.PrimaryGlowColor = Bgra(255, 255, 255, 128),
			.PrimaryGlowSize = 1.,
			.PrimaryGlowStyle = WeaponGlowingStyle::SLOW_CIRCULAR,
		}
	},
	{
		4, WeaponGlow
		{
			.SecondaryGlowColor = Bgra(0, 0, 0, 0),
			.SecondaryGlowSize = 0.,
			.SecondaryGlowStyle = WeaponGlowingStyle::NO_GLOWING,
			.PrimaryGlowColor = Bgra(255, 255, 255, 128),
			.PrimaryGlowSize = 1.,
			.PrimaryGlowStyle = WeaponGlowingStyle::FAST_CIRCULAR,
		}
	},
	{
		5, WeaponGlow
		{
			.SecondaryGlowColor = Bgra(0, 0, 0, 0),
			.SecondaryGlowSize = 0.,
			.SecondaryGlowStyle = WeaponGlowingStyle::NO_GLOWING,
			.PrimaryGlowColor = Bgra(255, 255, 255, 128),
			.PrimaryGlowSize = 1.150,
			.PrimaryGlowStyle = WeaponGlowingStyle::PROGRESSIVE,
		}
	},
	{
		6, WeaponGlow
		{
			.SecondaryGlowColor = Bgra(0, 0, 0, 0),
			.SecondaryGlowSize = 0.,
			.SecondaryGlowStyle = WeaponGlowingStyle::NO_GLOWING,
			.PrimaryGlowColor = Bgra(0, 255, 0, 128),
			.PrimaryGlowSize = 1.150,
			.PrimaryGlowStyle = WeaponGlowingStyle::PROGRESSIVE,
		}
	},
	{
		7, WeaponGlow
		{
			.SecondaryGlowColor = Bgra(0, 0, 0, 0),
			.SecondaryGlowSize = 0.,
			.SecondaryGlowStyle = WeaponGlowingStyle::NO_GLOWING,
			.PrimaryGlowColor = Bgra(255, 255, 255, 128),
			.PrimaryGlowSize = 1.150,
			.PrimaryGlowStyle = WeaponGlowingStyle::PROGRESSIVE,
		}
	},
	{
		8, WeaponGlow
		{
			.SecondaryGlowColor = Bgra(0, 0, 0, 0),
			.SecondaryGlowSize = 0.,
			.SecondaryGlowStyle = WeaponGlowingStyle::NO_GLOWING,
			.PrimaryGlowColor = Bgra(0, 0, 255, 128),
			.PrimaryGlowSize = 1.150,
			.PrimaryGlowStyle = WeaponGlowingStyle::ALWAYS,
		}
	},
	{
		9, WeaponGlow
		{
			.SecondaryGlowColor = Bgra(0, 0, 0, 0),
			.SecondaryGlowSize = 0.,
			.SecondaryGlowStyle = WeaponGlowingStyle::NO_GLOWING,
			.PrimaryGlowColor = Bgra(0, 255, 0, 128),
			.PrimaryGlowSize = 1.150,
			.PrimaryGlowStyle = WeaponGlowingStyle::ALWAYS,
		}
	},
	{
		10, WeaponGlow
		{
			.SecondaryGlowColor = Bgra(255, 255, 255, 175),
			.SecondaryGlowSize = 0.2,
			.SecondaryGlowStyle = WeaponGlowingStyle::FAST_CIRCULAR,
			.PrimaryGlowColor = Bgra(255, 255, 255, 128),
			.PrimaryGlowSize = 1.150,
			.PrimaryGlowStyle = WeaponGlowingStyle::ALWAYS,
		}
	},
{
	11, WeaponGlow
	{
		.SecondaryGlowColor = Bgra(127, 127, 127, 200),
		.SecondaryGlowSize = 0.300,
		.SecondaryGlowStyle = WeaponGlowingStyle::SLOW_CIRCULAR,
		.PrimaryGlowColor = Bgra(0, 255, 0, 160),
		.PrimaryGlowSize = 1.250,
		.PrimaryGlowStyle = WeaponGlowingStyle::PROGRESSIVE,
	}
},
{
	12, WeaponGlow
	{
		.SecondaryGlowColor = Bgra(255, 255, 255, 200),
		.SecondaryGlowSize = 0.350,
		.SecondaryGlowStyle = WeaponGlowingStyle::NO_GLOWING,
		.PrimaryGlowColor = Bgra(255, 255, 255, 180),
		.PrimaryGlowSize = 1.300,
		.PrimaryGlowStyle = WeaponGlowingStyle::PROGRESSIVE,
	}
},
{
	13, WeaponGlow
	{
		.SecondaryGlowColor = Bgra(255, 255, 255, 225),
		.SecondaryGlowSize = 0.400,
		.SecondaryGlowStyle = WeaponGlowingStyle::FAST_CIRCULAR,
		.PrimaryGlowColor = Bgra(0, 0, 255, 200),
		.PrimaryGlowSize = 1.350,
		.PrimaryGlowStyle = WeaponGlowingStyle::ALWAYS,
	}
},
{
	14, WeaponGlow
	{
		.SecondaryGlowColor = Bgra(255, 255, 255, 240),
		.SecondaryGlowSize = 0.450,
		.SecondaryGlowStyle = WeaponGlowingStyle::FAST_CIRCULAR,
		.PrimaryGlowColor = Bgra(0, 255, 0, 220),
		.PrimaryGlowSize = 1.400,
		.PrimaryGlowStyle = WeaponGlowingStyle::ALWAYS,
	}
},
{
	15, WeaponGlow
	{
		.SecondaryGlowColor = Bgra(255, 255, 255, 255),
		.SecondaryGlowSize = 0.500,
		.SecondaryGlowStyle = WeaponGlowingStyle::PROGRESSIVE,
		.PrimaryGlowColor = Bgra(255, 255, 255, 240),
		.PrimaryGlowSize = 1.500,
		.PrimaryGlowStyle = WeaponGlowingStyle::ALWAYS,
	}
},
};

upgradeToGlow defaultAboveLegendaryWeaponGlows =
{
	{
		0, defaultNoGlow
	},
	{
		1, WeaponGlow
		{
			.SecondaryGlowColor = Bgra(0, 0, 0, 0),
			.SecondaryGlowSize = 0.,
			.SecondaryGlowStyle = WeaponGlowingStyle::NO_GLOWING,
			.PrimaryGlowColor = Bgra(0, 0, 255, 128),
			.PrimaryGlowSize = 1.,
			.PrimaryGlowStyle = WeaponGlowingStyle::FAST_CIRCULAR,
		}
	},
	{
		2, WeaponGlow
		{
			.SecondaryGlowColor = Bgra(0, 0, 0, 0),
			.SecondaryGlowSize = 0.,
			.SecondaryGlowStyle = WeaponGlowingStyle::NO_GLOWING,
			.PrimaryGlowColor = Bgra(0, 255, 0, 80),
			.PrimaryGlowSize = 1.,
			.PrimaryGlowStyle = WeaponGlowingStyle::FAST_CIRCULAR,
		}
	},
	{
		3, WeaponGlow
		{
			.SecondaryGlowColor = Bgra(0, 0, 0, 0),
			.SecondaryGlowSize = 0.,
			.SecondaryGlowStyle = WeaponGlowingStyle::NO_GLOWING,
			.PrimaryGlowColor = Bgra(255, 255, 255, 128),
			.PrimaryGlowSize = 1.,
			.PrimaryGlowStyle = WeaponGlowingStyle::FAST_CIRCULAR,
		}
	},
	{
		4, WeaponGlow
		{
			.SecondaryGlowColor = Bgra(127, 127, 127, 127),
			.SecondaryGlowSize = 0.150,
			.SecondaryGlowStyle = WeaponGlowingStyle::SLOW_CIRCULAR,
			.PrimaryGlowColor = Bgra(255, 255, 255, 128),
			.PrimaryGlowSize = 1.,
			.PrimaryGlowStyle = WeaponGlowingStyle::FAST_CIRCULAR,
		}
	},
	{
		5, WeaponGlow
		{
			.SecondaryGlowColor = Bgra(127, 127, 127, 127),
			.SecondaryGlowSize = 0.150,
			.SecondaryGlowStyle = WeaponGlowingStyle::SLOW_CIRCULAR,
			.PrimaryGlowColor = Bgra(255, 255, 255, 128),
			.PrimaryGlowSize = 1.150,
			.PrimaryGlowStyle = WeaponGlowingStyle::PROGRESSIVE,
		}
	},
	{
		6, WeaponGlow
		{
			.SecondaryGlowColor = Bgra(127, 127, 127, 127),
			.SecondaryGlowSize = 0.150,
			.SecondaryGlowStyle = WeaponGlowingStyle::SLOW_CIRCULAR,
			.PrimaryGlowColor = Bgra(0, 255, 0, 128),
			.PrimaryGlowSize = 1.150,
			.PrimaryGlowStyle = WeaponGlowingStyle::PROGRESSIVE,
		}
	},
	{
		7, WeaponGlow
		{
			.SecondaryGlowColor = Bgra(127, 127, 127, 127),
			.SecondaryGlowSize = 0.150,
			.SecondaryGlowStyle = WeaponGlowingStyle::NO_GLOWING,
			.PrimaryGlowColor = Bgra(255, 255, 255, 128),
			.PrimaryGlowSize = 1.150,
			.PrimaryGlowStyle = WeaponGlowingStyle::PROGRESSIVE,
		}
	},
	{
		8, WeaponGlow
		{
			.SecondaryGlowColor = Bgra(255, 255, 255, 175),
			.SecondaryGlowSize = 0.200,
			.SecondaryGlowStyle = WeaponGlowingStyle::FAST_CIRCULAR,
			.PrimaryGlowColor = Bgra(0, 0, 255, 128),
			.PrimaryGlowSize = 1.150,
			.PrimaryGlowStyle = WeaponGlowingStyle::ALWAYS,
		}
	},
	{
		9, WeaponGlow
		{
			.SecondaryGlowColor = Bgra(255, 255, 255, 175),
			.SecondaryGlowSize = 0.200,
			.SecondaryGlowStyle = WeaponGlowingStyle::FAST_CIRCULAR,
			.PrimaryGlowColor = Bgra(0, 255, 0, 128),
			.PrimaryGlowSize = 1.150,
			.PrimaryGlowStyle = WeaponGlowingStyle::ALWAYS,
		}
	},
	{
		10, WeaponGlow
		{
			.SecondaryGlowColor = Bgra(255, 255, 255, 255),
			.SecondaryGlowSize = 0.7,
			.SecondaryGlowStyle = WeaponGlowingStyle::PROGRESSIVE,
			.PrimaryGlowColor = Bgra(255, 255, 255, 128),
			.PrimaryGlowSize = 1.150,
			.PrimaryGlowStyle = WeaponGlowingStyle::ALWAYS,
		}
	},
{
	11, WeaponGlow
	{
		.SecondaryGlowColor = Bgra(127, 127, 127, 200),
		.SecondaryGlowSize = 0.300,
		.SecondaryGlowStyle = WeaponGlowingStyle::SLOW_CIRCULAR,
		.PrimaryGlowColor = Bgra(0, 255, 0, 160),
		.PrimaryGlowSize = 1.250,
		.PrimaryGlowStyle = WeaponGlowingStyle::PROGRESSIVE,
	}
},
{
	12, WeaponGlow
	{
		.SecondaryGlowColor = Bgra(255, 255, 255, 200),
		.SecondaryGlowSize = 0.350,
		.SecondaryGlowStyle = WeaponGlowingStyle::NO_GLOWING,
		.PrimaryGlowColor = Bgra(255, 255, 255, 180),
		.PrimaryGlowSize = 1.300,
		.PrimaryGlowStyle = WeaponGlowingStyle::PROGRESSIVE,
	}
},
{
	13, WeaponGlow
	{
		.SecondaryGlowColor = Bgra(255, 255, 255, 225),
		.SecondaryGlowSize = 0.400,
		.SecondaryGlowStyle = WeaponGlowingStyle::FAST_CIRCULAR,
		.PrimaryGlowColor = Bgra(0, 0, 255, 200),
		.PrimaryGlowSize = 1.350,
		.PrimaryGlowStyle = WeaponGlowingStyle::ALWAYS,
	}
},
{
	14, WeaponGlow
	{
		.SecondaryGlowColor = Bgra(255, 255, 255, 240),
		.SecondaryGlowSize = 0.450,
		.SecondaryGlowStyle = WeaponGlowingStyle::FAST_CIRCULAR,
		.PrimaryGlowColor = Bgra(0, 255, 0, 220),
		.PrimaryGlowSize = 1.400,
		.PrimaryGlowStyle = WeaponGlowingStyle::ALWAYS,
	}
},
{
	15, WeaponGlow
	{
		.SecondaryGlowColor = Bgra(255, 255, 255, 255),
		.SecondaryGlowSize = 0.500,
		.SecondaryGlowStyle = WeaponGlowingStyle::PROGRESSIVE,
		.PrimaryGlowColor = Bgra(255, 255, 255, 240),
		.PrimaryGlowSize = 1.500,
		.PrimaryGlowStyle = WeaponGlowingStyle::ALWAYS,
	}
},
};

glowsMap defaultWeaponGlows =
{
	{ RarityType::DAMAGED,		defaultSubLegendaryWeaponGlows },
	{ RarityType::LOW_LEVEL,	defaultSubLegendaryWeaponGlows },
	{ RarityType::_,			defaultSubLegendaryWeaponGlows },
	{ RarityType::USEFUL,		defaultSubLegendaryWeaponGlows },
	{ RarityType::GOOD,			defaultSubLegendaryWeaponGlows },
	{ RarityType::HIGH_QUALITY,	defaultSubLegendaryWeaponGlows },
	{ RarityType::EXCELLENT,	defaultSubLegendaryWeaponGlows },
	{ RarityType::ANCIENT,		defaultSubLegendaryWeaponGlows },
	{ RarityType::MYSTERIOUS,	defaultSubLegendaryWeaponGlows },
	{ RarityType::LEGENDARY,	defaultAboveLegendaryWeaponGlows },
	{ RarityType::PHENOMENAL,	defaultAboveLegendaryWeaponGlows },
};
