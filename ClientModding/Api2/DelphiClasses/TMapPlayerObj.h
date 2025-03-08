#pragma once
#include "TMapMoveObjBase.h"
#include "../Properties/Graphical/WeaponGlowingStyle.h"
#include "../Enums/RarityType.h"
#pragma pack(push, 1)

class TMapPlayerObj : public TMapMoveObjBase
{
public:
	int8_t getAuthority() { return authority; }
	int16_t getCompliment() { return compliment; }
	char* getPseudonym() { return pseudonym; }

	void setPseudonym(char* Pseudonym) { pseudonym = Pseudonym; }
	void setWeaponGlow(WeaponGlow WeaponGlow) { weaponGlow = WeaponGlow; }
	void setWeaponRarity(RarityType WeaponRarity) { weaponRarity = WeaponRarity; }
	void setWeaponUpgrade(Upgrade WeaponUpgrade) { weaponUpgrade = WeaponUpgrade; }

private:
	int16_t spSkinId;					// 0x1B0 more complicated in reality - gender and sp id are a single data with the most left bit being gender. gender=0x80 = male gender=0 = female
	bool unknown84;						// 0x1B2 adds a TNTCapFx to the list of effect (fairy, wings..) when removing the SP - what is this
	char unknown85;						// 0x1B3 probably padding
	bool isUsingLocomotion;				// 0x1B4
	char unknown86[3];					// 0x1B5 probably padding
	void* pointertoBelow;				// 0x1B4 Wtf are they doing. This pointer is pointing to the variable below
	Bgra hairBgra;						// 0x1B8
	Bgra hatBgra;						// 0x1BC
	Bgra maskBgra;						// 0x1C0
	WeaponGlow weaponGlow;				// 0x1C4
	void* fnHandleStuffUpgradeEffect;	// 0x1D6
	RarityType armorRarity;				// 0x1DA
	Upgrade armorUpgrade;				// 0x1DB
	int32_t timestampLastArmorEffect;	// 0x1DC
	int32_t timestampUnknown;			// 0x1E0 seems related to the sparking but could not find anything on display
	int8_t charClass;					// 0x1E4
	bool isInvisible;					// 0x1E5
	int8_t costumeSkinId;				// 0x1E6
	int8_t hairStyle;					// 0x1E7
	int8_t hatSkinId;					// 0x1E8
	int8_t maskSkinId;					// 0x1E9
	char unknown87;						// 0x1EA
	int8_t weaponSkinId;				// 0x1EB
	char* pseudonym;					// 0x1EC delphi ref counted string
	char* title;						// 0x1F0 delphi ref counted string
	char* familyName;					// 0x1F4 delphi ref counted string
	void* tntfairy;						// 0x1F8
	void* unknown94;					// TNTMiniPet
	int8_t authority;					// 0x1FC
	char unknown88[3];					// 0x1FD probably padding
	int32_t reputationId;				// 0x200
	char unknown89[2];					// 0x204
	char unknown90;						// 0x206 on -15 it will affect the weapon glow when moving... wtf?
	RarityType weaponRarity;			// 0x207
	Upgrade weaponUpgrade;				// 0x208
	char unknown91;						// 0x209
	int16_t compliment;					// 0x20A
	int8_t familyIconLeft;				// 0x20C
	int8_t familyIconMiddle;			// 0x20D
	int8_t familyIconRight;				// 0x20E
	char unknown92;						// 0x20F probably padding
};
static_assert(sizeof(TMapPlayerObj) == 0x218, "TMapPlayerObj does not have a size of 0x218.");

#pragma pack(pop)
