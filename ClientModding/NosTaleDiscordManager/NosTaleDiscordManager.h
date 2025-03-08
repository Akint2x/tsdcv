#pragma once
#include "../Api/DelphiClasses/TGameRootWidget.h"
#include "../Api/DelphiClasses/TNTNewCharacterStandardInfoWidget.h"
#include "../Api/Managers/Manager.h"
#include "../Api/Managers/PacketManager/PacketManager.h"
#include "../Api/Managers/DiscordManager/DiscordManager.h"
#include "../Api/Managers/ConnectionManager/ConnectionManager.h"
#include "NosTaleDiscordManagerConfig.h"

class NosTaleDiscordManager : public Manager<NosTaleDiscordManagerConfig>
{
public:
	[[nodiscard]] explicit NosTaleDiscordManager(const NosTaleDiscordManagerConfig& Config = NosTaleDiscordManagerConfig{}) noexcept;

	void ConfigurePacketManager(PacketManager& PacketMng) noexcept;
	void ConfigureDiscordManager(DiscordManager& DiscordMng) noexcept;
	void ConfigureConnectionManager(ConnectionManager& ConnectionMng) noexcept;

private:
	[[nodiscard]] bool initialize() noexcept override;
	[[nodiscard]] bool unload() noexcept override;
	void tick() noexcept override;

	void on_PR_tit(std::string& packet) noexcept;
	void on_PR_lev(std::string& packet) noexcept;
	void on_PR_discord_status(std::string& packet) noexcept;

	DiscordManager* discordMng{ nullptr };
	ConnectionManager* connectionMng{ nullptr };

	std::string pseudonym;
	std::string lvl, lvlH;
};