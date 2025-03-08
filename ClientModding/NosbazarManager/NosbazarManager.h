#pragma once
#include "../Api/DelphiClasses/TGameRootWidget.h"
#include "../Api/DelphiClasses/TNTNewCharacterStandardInfoWidget.h"
#include "../Api/Managers/Manager.h"
#include "../Api/Managers/PacketManager/PacketManager.h"
#include "NosbazarManagerConfig.h"

class NosbazarManager : public Manager<NosbazarManagerConfig>
{
public:
	[[nodiscard]] explicit NosbazarManager(const NosbazarManagerConfig& Config = NosbazarManagerConfig{}) noexcept;

private:
	[[nodiscard]] bool initialize() noexcept override;
	[[nodiscard]] bool unload() noexcept override;
	void tick() noexcept override;
};
