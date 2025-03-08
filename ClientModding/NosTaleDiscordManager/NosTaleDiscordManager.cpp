#include "NosTaleDiscordManager.h"
#include "../Utils/Split.h"
#include "../Utils/Join.h"
#include "../Utils/ToNumber.h"

NosTaleDiscordManager::NosTaleDiscordManager(const NosTaleDiscordManagerConfig& Config) noexcept
	: Manager(Config, "NosTaleDiscordManager")
{}

void NosTaleDiscordManager::ConfigurePacketManager(PacketManager& PacketMng) noexcept
{
	PacketMng.Subscribe(PacketType::RCVD, "tit", [this](std::string& Packet) { on_PR_tit(Packet); });
	PacketMng.Subscribe(PacketType::RCVD, "lev", [this](std::string& Packet) { on_PR_lev(Packet); });
	PacketMng.Subscribe(PacketType::RCVD, "discord_status", [this](std::string& Packet) { on_PR_discord_status(Packet); });
}

void NosTaleDiscordManager::ConfigureDiscordManager(DiscordManager& DiscordMng) noexcept
{
	discordMng = &DiscordMng;
}

void NosTaleDiscordManager::ConfigureConnectionManager(ConnectionManager& ConnectionMng) noexcept
{
	connectionMng = &ConnectionMng;
}

bool NosTaleDiscordManager::initialize() noexcept
{
	if (discordMng == nullptr)
		return false;
	if (connectionMng == nullptr)
		return false;

	Logger::Success("Successfully initialized");
	return true;
}

bool NosTaleDiscordManager::unload() noexcept
{
	return false;
}

void NosTaleDiscordManager::tick() noexcept
{}

void NosTaleDiscordManager::on_PR_tit(std::string& packet) noexcept
{
	Logger::Log("Tit: %s", packet.c_str());
	auto words = Split(packet, " ");
	pseudonym = words[2];
	//discordMng.SetPseudonym(pseudo);
	//discordMng.SetChannel(connectionMng.GetServChanManager().GetChannel());
}

void NosTaleDiscordManager::on_PR_lev(std::string& packet) noexcept
{
	Logger::Log("Lev: %s", packet.c_str());
	auto words = Split(packet, " ");
	lvl = words[1];
	lvlH = words[10];
}

void NosTaleDiscordManager::on_PR_discord_status(std::string& packet) noexcept
{
	Logger::Log("discord_status: %s", packet.c_str());
	auto words = Split(packet, " ");

	std::string bigImage = words[1];
	std::string activity = Join(words, " ", 2);

	discordMng->SetBigImage(bigImage);
	discordMng->SetBigImageHover("Server " + std::to_string(connectionMng->GetServChanManager().GetServer()) +
		" Channel " + std::to_string(connectionMng->GetServChanManager().GetChannel()));

	discordMng->SetLittleImage("logo");
	discordMng->SetLittleImageHover("NosBlaze");

	discordMng->SetLine1(pseudonym + " - Lv." + lvl + "+" + lvlH);
	discordMng->SetLine2(activity);
}
