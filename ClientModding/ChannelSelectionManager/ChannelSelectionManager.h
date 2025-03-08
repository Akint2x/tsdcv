#pragma once
#include "../Api/Managers/Manager.h"
#include "ChannelSelectionManagerConfig.h"

class ChannelSelectionManager : public Manager<ChannelSelectionManagerConfig>
{
public:
	[[nodiscard]] explicit ChannelSelectionManager(const ChannelSelectionManagerConfig& Config = ChannelSelectionManagerConfig{}) noexcept;

private:
	[[nodiscard]] bool initialize() noexcept override;
	[[nodiscard]] bool unload() noexcept override;
	void tick() noexcept override;
};
