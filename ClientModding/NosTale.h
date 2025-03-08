#pragma once
#include "ClientModding.h"
#include "NosTaleDiscordManager/NosTaleDiscordManager.h"
#include "ChannelSelectionManager/ChannelSelectionManager.h"
#include "NosbazarManager/NosbazarManager.h"
#include "WarpModule/WarpModule.h"

class NosTale : public ClientModding // We need to inherit from ClientModding
{
public:
	[[nodiscard]] explicit NosTale(const ClientModdingConfig& Config, HINSTANCE hInstance) noexcept;

private:
	[[nodiscard]] bool beforeRun() noexcept override;
	void onShowNostaleSplash() noexcept override;
	void onFreeNostaleSplash() noexcept override;
	void tick() noexcept override;

	HINSTANCE hInstanceGlobal;
	NosTaleDiscordManager nostaleDiscordMng;
	ChannelSelectionManager channelSelectionMng;
	NosbazarManager nosbazarMng;
	WarpModule warpMod;

};
