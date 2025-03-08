#pragma once
#include "../Api/DelphiClasses/Helpers/ScrollBar.h"
#include "../Api/DelphiClasses/Helpers/ComboBox.h"
#include "../Api/DelphiClasses/TGameRootWidget.h"
#include "../Api/DelphiClasses/TNTNewCharacterStandardInfoWidget.h"
#include "../Api/DelphiClasses/TPetSelectIcon.h"
#include "../Api/DelphiClasses/TEWCustomFormWidget.h"
#include "../Api/Managers/PacketManager/PacketManager.h"
#include "WarpModuleConfig.h"

class WarpModule : public Manager<WarpModuleConfig>
{
public:
	[[nodiscard]] explicit WarpModule(const WarpModuleConfig& Config = WarpModuleConfig{}) noexcept;

	void ConfigurePacketManager(PacketManager& PacketMng) noexcept;

private:
	[[nodiscard]] bool initialize() noexcept override;
	[[nodiscard]] bool unload() noexcept override;
	void tick() noexcept override;

	void MakeWindow();
	void SetPublicWarpList();
	void SetPrivateWarpList();

	void SetPublicWarpOff();
	void SetPublicWarpOn();

	void SetPrivateWarpOff();
	void SetPrivateWarpOn();

	void SetPublicVisible() noexcept;
	void SetPrivateVisible() noexcept;

	void refresh(bool isPrivate) noexcept;

	void removeAll() noexcept;

	class EntityPanel
	{
	public:
		[[nodiscard]] explicit EntityPanel(TEWCustomFormWidget* LodRaidWindow, int i, bool isPrivate) noexcept;
		void setVisible(bool Value, bool forced) noexcept;
		void move(int16_t index, int16_t value);
		void handleData(const std::vector<std::string>& Packet, bool isPrivate) noexcept;

	private:
		void setInstanceId(int32_t Value) noexcept;
		void setDeleteInstanceId(int32_t Value) noexcept;
		void setPseudonym(const std::string& Pseudonym) noexcept;
		void setCordinates(int16_t PosX, int16_t PosY, bool isPrivate) noexcept;
		void setCapacity(int16_t CurrentCapacity, int16_t MaxCapacity) noexcept;

		TEWGraphicButtonWidget* listEntityPanel{ nullptr };
		TEWGraphicButtonWidget* deleteEntityPanel{ nullptr };
		TEWLabel* pseudonymLabel{ nullptr };
		TEWLabel* capacityLabel{ nullptr };
		TEWGraphicButtonWidget* btJoin{ nullptr };
	};

	ScrollBar* sb{ nullptr };
	ScrollBar* sbPrivate{ nullptr };


	std::vector<EntityPanel*> entitiesPanel;
	std::vector<EntityPanel*> entitiesPrivatePanel;
	std::vector<std::vector<std::string>> packetsFlemme;
	std::vector<std::vector<std::string>> privatePacketsFlemme;

};
