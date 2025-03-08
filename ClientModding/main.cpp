#include "NosTale.h"
#include <windows.h>
#include <string>
#include <thread>

HMODULE hModule;

ClientModdingConfig config =
{
	.CharacterConfig =
	{
		.StuffConfig =
		{
			.WeaponConfig =
			{
				.AdditionalGlow = glowsMap
				{
					{ RarityType(9), upgradeToGlow
						{
{ 1, WeaponGlow {.SecondaryGlowColor = Bgra(72, 61, 139, 128), .SecondaryGlowSize = 0.8, .SecondaryGlowStyle = WeaponGlowingStyle::SLOW_CIRCULAR, .PrimaryGlowColor = Bgra(72, 61, 139, 128), .PrimaryGlowSize = 1.0, .PrimaryGlowStyle = WeaponGlowingStyle::ALWAYS }},
{ 2, WeaponGlow {.SecondaryGlowColor = Bgra(75, 0, 130, 144), .SecondaryGlowSize = 0.9, .SecondaryGlowStyle = WeaponGlowingStyle::SLOW_CIRCULAR, .PrimaryGlowColor = Bgra(75, 0, 130, 144), .PrimaryGlowSize = 1.1, .PrimaryGlowStyle = WeaponGlowingStyle::ALWAYS }},
{ 3, WeaponGlow {.SecondaryGlowColor = Bgra(123, 104, 238, 160), .SecondaryGlowSize = 1.0, .SecondaryGlowStyle = WeaponGlowingStyle::SLOW_CIRCULAR, .PrimaryGlowColor = Bgra(123, 104, 238, 160), .PrimaryGlowSize = 1.2, .PrimaryGlowStyle = WeaponGlowingStyle::ALWAYS }},
{ 4, WeaponGlow {.SecondaryGlowColor = Bgra(138, 43, 226, 176), .SecondaryGlowSize = 1.1, .SecondaryGlowStyle = WeaponGlowingStyle::PROGRESSIVE, .PrimaryGlowColor = Bgra(138, 43, 226, 176), .PrimaryGlowSize = 1.3, .PrimaryGlowStyle = WeaponGlowingStyle::ALWAYS }},
{ 5, WeaponGlow {.SecondaryGlowColor = Bgra(148, 0, 211, 192), .SecondaryGlowSize = 1.2, .SecondaryGlowStyle = WeaponGlowingStyle::PROGRESSIVE, .PrimaryGlowColor = Bgra(148, 0, 211, 192), .PrimaryGlowSize = 1.4, .PrimaryGlowStyle = WeaponGlowingStyle::ALWAYS }},
{ 6, WeaponGlow {.SecondaryGlowColor = Bgra(186, 85, 211, 208), .SecondaryGlowSize = 1.3, .SecondaryGlowStyle = WeaponGlowingStyle::PROGRESSIVE, .PrimaryGlowColor = Bgra(186, 85, 211, 208), .PrimaryGlowSize = 1.5, .PrimaryGlowStyle = WeaponGlowingStyle::ALWAYS }},
{ 7, WeaponGlow {.SecondaryGlowColor = Bgra(216, 191, 216, 224), .SecondaryGlowSize = 1.4, .SecondaryGlowStyle = WeaponGlowingStyle::FAST_CIRCULAR, .PrimaryGlowColor = Bgra(216, 191, 216, 224), .PrimaryGlowSize = 1.6, .PrimaryGlowStyle = WeaponGlowingStyle::ALWAYS }},
{ 8, WeaponGlow {.SecondaryGlowColor = Bgra(238, 130, 238, 240), .SecondaryGlowSize = 1.5, .SecondaryGlowStyle = WeaponGlowingStyle::FAST_CIRCULAR, .PrimaryGlowColor = Bgra(238, 130, 238, 240), .PrimaryGlowSize = 1.7, .PrimaryGlowStyle = WeaponGlowingStyle::ALWAYS }},
{ 9, WeaponGlow {.SecondaryGlowColor = Bgra(255, 105, 180, 255), .SecondaryGlowSize = 1.6, .SecondaryGlowStyle = WeaponGlowingStyle::FAST_CIRCULAR, .PrimaryGlowColor = Bgra(255, 105, 180, 255), .PrimaryGlowSize = 1.8, .PrimaryGlowStyle = WeaponGlowingStyle::ALWAYS }},
{ 10, WeaponGlow {.SecondaryGlowColor = Bgra(255, 20, 147, 255), .SecondaryGlowSize = 1.7, .SecondaryGlowStyle = WeaponGlowingStyle::PROGRESSIVE, .PrimaryGlowColor = Bgra(255, 20, 147, 255), .PrimaryGlowSize = 1.9, .PrimaryGlowStyle = WeaponGlowingStyle::ALWAYS }},
						},
					},
				},
			},
			.SpConfig =
			{
				.AuraConfig = levelToId
				{
					{ 20, 7907 },
				},
				.WingConfig =
				{
					.AdditionalWings = wingsMap
					{
						{ 25, levelToId
							{
								{ 1, 1346 },
								{ 2, 1347 },
								{ 3, 1348 },
								{ 4, 1202 },
								{ 5, 1202 },
								{ 6, 1202 },
								{ 7, 1202 },
								{ 8, 1202 },
								{ 9, 1202 },
								{ 10, 1202 },
								{ 11, 1202 },
								{ 12, 1202 },
								{ 13, 1202 },
								{ 14, 1202 },
								{ 15, 1202 },
								{ 16, 1202 },
								{ 17, 1202 },
								{ 18, 1202 },
								{ 19, 1202 },
								{ 20, 1202 },
							},
						},
					},
				},
			},
			.StuffRarityConfig =
			{
				.AdditionalRarityTextStyle = rarityToTextStyle
				{
					{ RarityType(9),	TextStyle(2, TextShadowOrientation::ShadowNone, Bgra(164, 0, 161, 255), Bgra(), TextAlignment::CenteredCentered) },
					{ RarityType(10),	TextStyle(2, TextShadowOrientation::ShadowNone, Bgra(11, 140, 240, 255), Bgra(), TextAlignment::CenteredCentered) }
				},
				.AdditionalRarityTextVnum = rarityToTextVnum
				{
					{ RarityType(9),	5000 },
					{ RarityType(10),	5001 },
					{ RarityType(11),	5002 },
					{ RarityType(12),	5003 },
					{ RarityType(13),	5004 },
					{ RarityType(14),	5005 },
					{ RarityType(15),	5006 },
				},
			},

			.ArmorConfig =
			{
				.AdditionalEffects = effectsMap
				{
					{ RarityType(9), upgradeToEffectId
						{
							{ 10, 4500 },
						},
					},
				},
			},
		},
		//.InteractionConfig =
		//{
		//    .NpcTalkRangeConfig =
		//    {
		//        .DefaultTalkRange = 3,
		//    },
		//},
	},
	.ConnectionConfig =
	{
	},
	.DiscordConfig =
	{
		.Active = true,
		.ApplicationId = 0,
	},
	.MapConfig =
	{
	},
	.GameFileConfig =
	{
		.NScliConfig = {
		},
	},
	.PacketConfig =
	{
		.EncryptFn = [](std::string Packet)
		{
		// TODO
		return Packet;
	},
	.DecryptFn = [](std::string Packet)
	{
		// TODO
		return Packet;
	},
},
//.UIConfig =
//{
//    .SpyHpMpConfig =
//    {
//        .SpyGroup =
//        {
//            .Activate = true,
//            .SpyType = SpyType::APPROXIMATION,
//        },
//    },
//},
.EventLoopDelay = 10,
};

NosTale* nostale = nullptr;

void Start(HMODULE hModule)
{
	if (!nostale->IsReady())
	{
		Logger::Error("Failed initializing NosTale");
		return;
	}

	Logger::Success(" -> NosTale-Modding successfully initialized");

	nostale->Run();

	system("pause");
}

void InitLogger()
{
	Logger::Load("");
	Logger::IndentModuleName("   ");
}

extern "C" __declspec(dllexport) void __declspec(naked) ShowNostaleSplash()
{
	__asm
	{
		pushad;
		pushfd;
	}
	//InitLogger();
	nostale = new NosTale(config, hModule);
	nostale->OnShowNostaleSplash();
	__asm
	{
		popfd;
		popad;
	}
}

std::thread* th = nullptr;

DWORD WINAPI MainThread(HMODULE hModule)
{
	//InitLogger();

	while (!nostale->IsReady())
		Sleep(config.EventLoopDelay);

	// Additional sleep to ensure initialization
	Sleep(500);

	Start(hModule);

	Logger::Unload();
	FreeLibraryAndExitThread(hModule, 0);
	return 1;
}

extern "C" __declspec(dllexport) void __declspec(naked) FreeNostaleSplash() noexcept
{
	__asm
	{
		pushad;
		pushfd;
	}
	nostale->OnFreeNostaleSplash();
	th = new std::thread([]
		{
			MainThread(hModule);
		});
	th->detach();
	__asm
	{
		popfd;
		popad;

		mov eax, 0;
		ret;
	}
}

BOOL APIENTRY DllMain(HMODULE HModule, DWORD ul_reason_for_call, LPVOID lpReserved)
{
	switch (ul_reason_for_call)
	{
	case DLL_PROCESS_ATTACH:
		hModule = HModule;
		break;
	case DLL_THREAD_ATTACH:
	case DLL_THREAD_DETACH:
	case DLL_PROCESS_DETACH:
		break;
	}
	return TRUE;
}