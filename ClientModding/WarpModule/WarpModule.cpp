#include "WarpModule.h"
#include "../Api/DelphiClasses/TNTNewCharacterSkillInfoWidget.h"
#include "../Api/DelphiClasses/TLBSWidgetHandler.h"
#include "../Api/DelphiClasses/TEWCaptionBar.h"
#include "../Utils/Split.h"
#include "../Utils/ToNumber.h"
#include "../Utils/WStringConvertor.h"
#include "../Api/DelphiClasses/TNTLoginWidget.h"
#include "../Api/DelphiClasses/TNTNewServerSelectWidget2.h"

namespace
{
	TGameRootWidget* gameRoot;
	TEWCustomFormWidget* warpWindow;

	TEWGraphicButtonWidget* settingsBTN;

	TEWGraphicButtonWidget* button;

	TEWCustomFormWidget* privateListPanel;
	TEWCustomFormWidget* publicListPanel;

	TEWGraphicButtonWidget* publicWarpButtonOn;
	TEWGraphicButtonWidget* publicWarpButtonOff;
	TEWGraphicButtonWidget* privateWarpButtonOn;
	TEWGraphicButtonWidget* privateWarpButtonOff;

	TEWGraphicButtonWidget* btJoin;

	//ComboBox::IndexType filterIndex{ 0 };
	ScrollBar::IndexType scrollIndex{ 0 };
	bool isSettingsOpen = false;
	bool shouldMove = false;
	void closeOnClickFn() { warpWindow->setVisible(false); }


	std::function<void(TEWGraphicButtonWidget* button)> onClickSetting;
	void settingsOnClickFn(TEWGraphicButtonWidget* button) { onClickSetting(button); }

	std::function<void(TEWGraphicButtonWidget* button)> setPrivateVisibleClickCb;
	std::function<void(TEWGraphicButtonWidget* button)> setPublicVisibleClickCb;

	std::function<void(TEWGraphicButtonWidget* button)> joinClickCb;
	void joinOnClickFn(void* _, TEWGraphicButtonWidget* button) { joinClickCb(button); }

	std::function<void(TEWGraphicButtonWidget* button)> joinPrivateClickCb;
	void joinPrivateOnClickFn(void* _, TEWGraphicButtonWidget* button) { joinPrivateClickCb(button); }

	std::function<void(TEWGraphicButtonWidget* button)> deleteClickCb;
	void deleteOnClickFn(void* _, TEWGraphicButtonWidget* button) { deleteClickCb(button); }

	std::function<void(TEWGraphicButtonWidget* button)> createClickCb;
	void createOnClickFn(void* _, TEWGraphicButtonWidget* button) { createClickCb(button); }

	void setPrivateVisibleClickFn(void* _, TEWGraphicButtonWidget* button) { setPrivateVisibleClickCb(button); }
	void setPublicVisibleClickFn(void* _, TEWGraphicButtonWidget* button) { setPublicVisibleClickCb(button); }
	std::function<void()> motionClickCb;
	void motionClickFN(void* _, TEWGraphicButtonWidget* button) { motionClickCb(); }
}

WarpModule::WarpModule(const WarpModuleConfig& Config) noexcept
	: Manager(Config, "WarpModule")
{
}

void WarpModule::ConfigurePacketManager(PacketManager& PacketMng) noexcept
{
	motionClickCb = [this, &PacketMng]
		{
			SetPublicVisible();
			warpWindow->setVisible(true);
		};

	joinClickCb = [this, &PacketMng](TEWGraphicButtonWidget* button)
		{
			if (button == nullptr)
				return;
			//warpWindow->SetResize(TEWCustomFormWidget::ResizeFlag::All);
			int32_t arg = button->getCallback().getArg();
			Logger::Log("Warp_tp clicked: %x", std::to_string(arg));
			PacketMng.Send("warp_dft_tp " + std::to_string(arg) + " 0");
		};

	joinPrivateClickCb = [this, &PacketMng](TEWGraphicButtonWidget* button)
		{
			if (button == nullptr)
				return;

			int32_t arg = button->getCallback().getArg();
			Logger::Log("Warp_tp clicked: %x", std::to_string(arg));
			PacketMng.Send("warp_pvt_tp " + std::to_string(arg) + " 0");
		};

	deleteClickCb = [this, &PacketMng](TEWGraphicButtonWidget* button)
		{
			if (button == nullptr)
				return;

			int32_t arg = button->getCallback().getArg();
			Logger::Log("Warp_tp clicked: %x", std::to_string(arg));
			PacketMng.Send("warp_pvt_del " + std::to_string(arg) + " 0");
		};

	setPrivateVisibleClickCb = [this, &PacketMng](TEWGraphicButtonWidget* button)
		{
			if (button == nullptr)
				return;

			SetPrivateVisible();
		};

	setPublicVisibleClickCb = [this, &PacketMng](TEWGraphicButtonWidget* button)
		{
			if (button == nullptr)
				return;

			SetPublicVisible();
		};

	onClickSetting = [this, &PacketMng](TEWGraphicButtonWidget* button)
		{
			if (isSettingsOpen)
			{
				isSettingsOpen = false;

				refresh(true);
				return;
			}
			isSettingsOpen = true;
			refresh(true);
		};

	createClickCb = [this, &PacketMng](TEWGraphicButtonWidget* button)
		{
			if (button == nullptr)
			{
				return;
			}
			PacketMng.Send("warp_pvt_add");
		};

	PacketMng.Subscribe(PacketType::SENT, "c_close", [this](std::string& Packet)
		{
			// warp_new [ID] [PSEUDO] [X] [Y]

			removeAll();
		});

	PacketMng.Subscribe(PacketType::RCVD, "warp_dft_load", [this](std::string& Packet)
		{
			button->setVisible(true);
			// warp_new [ID] [PSEUDO] [X] [Y]
			entitiesPanel.push_back(new EntityPanel(publicListPanel, entitiesPanel.size(), false));
			packetsFlemme.push_back(Split(Packet, " "));
			sb->SetCurrentItemsNumber(entitiesPanel.size());
			Logger::Log("packetFlemme size %x", entitiesPanel.size());
			refresh(false);
		});

	PacketMng.Subscribe(PacketType::RCVD, "warp_pvt_load", [this](std::string& Packet)
		{
			// warp_new [ID] [PSEUDO] [X] [Y]
			entitiesPrivatePanel.push_back(new EntityPanel(privateListPanel, entitiesPrivatePanel.size(), true));
			privatePacketsFlemme.push_back(Split(Packet, " "));
			Logger::Log("privatePacketsFlemme size %x", privatePacketsFlemme.size());
			Logger::Log("entitiesPrivatePanel size %x", entitiesPrivatePanel.size());
			if (isSettingsOpen)
			{
				isSettingsOpen = false;
			}
			sbPrivate->SetCurrentItemsNumber(entitiesPrivatePanel.size());
			refresh(true);
		});

	PacketMng.Subscribe(PacketType::RCVD, "warp_conf_del", [this](std::string& Packet)
		{
			// aa_lodinst_del [ID]
			auto id = ToNumberUnsafe<int32_t>(Split(Packet, " ")[1].c_str());
			for (auto i = 0; i < privatePacketsFlemme.size(); i++)
			{
				auto nb = ToNumberUnsafe<int32_t>(privatePacketsFlemme[i][1].c_str());
				if (nb == id)
				{
					Logger::Log("Rimuovoo");
					privatePacketsFlemme.erase(privatePacketsFlemme.begin() + i);
					entitiesPrivatePanel[i]->setVisible(false, true);
					entitiesPrivatePanel.erase(entitiesPrivatePanel.begin() + i);
					shouldMove = true;
					break;
				}
			}
			sbPrivate->SetCurrentItemsNumber(entitiesPrivatePanel.size());
			refresh(true);
		});

}

bool WarpModule::initialize() noexcept
{
	auto _ = Logger::PushPopModuleName("Warp manager");
	Logger::Log("Start Initialize Warp");

	/*if (!TNTNewCharacterSkillInfoWidget::addMotionSkillEvent(1000, []()
		{
			Logger::Log("Si �a se print, c'est que �a marche");
			motionClickCb();
		}))
	{
		Logger::Error("Failed adding motion skill for 1000");
		return false;
	}*/

	MakeWindow();

	return true;
}

bool WarpModule::unload() noexcept
{
	return false;
}

void WarpModule::tick() noexcept
{
	int width = gameRoot->getWidth();
	int height = gameRoot->getHeight();
	int total = width + height;
	//Logger::Log("Width %x", widthBot);
	//Logger::Log("Heigth %x", widthTop);
	switch (total)
	{
	case 1792: // 1024 x 768
		if (button->isVisible())
			button->setWidgetPosition(820, 15);
		break;
	case 2304: //1280 x 1024
		if (button->isVisible())
			button->setWidgetPosition(1076, 15);
		break;
	case 2080: // 1280 x 800
		if (button->isVisible())
			button->setWidgetPosition(1076, 15);
		break;
	case 2340: // 1440 x 900
		if (button->isVisible())
			button->setWidgetPosition(1236, 15);
		break;
	case 1724: // 1024 x 700
		if (button->isVisible())
			button->setWidgetPosition(820, 15);
		break;
	case 2730: // 1680 x 1050
		if (button->isVisible())
			button->setWidgetPosition(1476, 15);
		break;
	case 3000: // 1920 x 1080
		if (button->isVisible())
			button->setWidgetPosition(1716, 15);
		break;
	}
}

void WarpModule::MakeWindow()
{
	gameRoot = TLBSWidgetHandler::getNtInstance()->getGameRootWidget();

	button = new TEWGraphicButtonWidget(
		TLBSWidgetHandler::getNtInstance()->getGameRootWidget(),
		Border(0, 0, 41, 38),
		Bgra(255, 255, 255, 255),
		ImageData(1593835575, 512, 512, new PictureDisplayer({
			PictureView(364, 1, 41, 38),
			PictureView(364, 76, 41, 38),
			PictureView(364, 152, 41, 38)
			})),
		ImagePadding(0, 0, 0, 0, 0, 0),
		Callback(motionClickFN, 0), 2, 3
	);
	gameRoot->addWidget(button);
	button->setVisible(false);

	warpWindow = new TEWCustomFormWidget(
		gameRoot,
		Border(50, 50, 310, 443),
		ImageData(1593835577, 512, 512, new PictureDisplayer(
			{
				PictureView(465, 252, 6, 2),
				PictureView(459, 220, 6, 32),
				PictureView(465, 220, 6, 32),
				PictureView(471, 220, 5, 32),
				PictureView(471, 252, 5, 2),
				PictureView(471, 254, 5, 6),
				PictureView(465, 254, 6, 6),
				PictureView(459, 254, 6, 6),
				PictureView(459, 252, 6, 2),
			})),
			ImagePadding(
				300,
				439,
				305,
				437,
				6,
				32,
				5,
				6)
	);

	gameRoot->addWidget(warpWindow); // Tells the parent to add a child
	warpWindow->setVisible(false); // Tells the renderer to actually display the form.

	TEWCaptionBar* titleBar = new TEWCaptionBar(
		warpWindow,
		Border(0, 0, warpWindow->getBorder().botRightX - warpWindow->getBorder().topLeftY, 30),
		Bgra(255, 255, 255, 255),
		TextStyle(3, TextShadowOrientation::ShadowBottomLeft, Bgra(255, 255, 255, 255), Bgra(127, 127, 127, 127), TextAlignment::TopLeft),
		TextPosition(9, 5, 0, 0, new WString(L"Warps List"), true)
	);
	warpWindow->addWidget(titleBar);
	titleBar->setVisible(true);

	btJoin = new TEWGraphicButtonWidget(
		privateListPanel,
		Border(195, 5, 48, 23),
		Bgra(255, 255, 255, 255),
		ImageData(1593835576, 512, 512, new PictureDisplayer(
			{
				PictureView(300, 437, 48, 23),
				PictureView(300, 437, 48, 23),
				PictureView(351, 437, 48, 23),
			})),
			ImagePadding(0, 0, 0, 0, 0, 0),
			Callback(createOnClickFn, -1),
			0, 3
			);

	warpWindow->addWidget(btJoin);

	settingsBTN = new TEWGraphicButtonWidget(
		warpWindow,
		Border(254, 5, 20, 21),
		Bgra(255, 255, 255, 255),
		ImageData(1593835568, 512, 512, new PictureDisplayer(
			{
				PictureView(210, 60, 30, 30),
				PictureView(210, 60, 30, 30),
				PictureView(210, 60, 30, 30),
			}
			)),
		ImagePadding(),
		Callback(settingsOnClickFn, 0),
		0, 3
	);

	settingsBTN->setVisible(true);
	warpWindow->addWidget(settingsBTN);

	TEWGraphicButtonWidget* closeButton = new TEWGraphicButtonWidget(
		warpWindow,
		Border(284, 5, 20, 21),
		Bgra(255, 255, 255, 255),
		ImageData(1593835585, 512, 512, new PictureDisplayer(
			{
				PictureView(244, 2, 20, 20),
				PictureView(264, 2, 20, 20),
				PictureView(244, 22, 20, 20),
			}
			)),
		ImagePadding(),
		Callback(closeOnClickFn, 0),
		0, 3
	);
	closeButton->setVisible(true);
	warpWindow->addWidget(closeButton);



	SetPublicWarpList();
	SetPrivateWarpList();
	SetPublicWarpOff();
	SetPublicWarpOn();
	SetPrivateWarpOff();
	SetPrivateWarpOn();
}

WarpModule::EntityPanel::EntityPanel(TEWCustomFormWidget* WarpWindow, int i, bool isPrivate) noexcept
{
	if (!isPrivate)
	{
		listEntityPanel = new TEWGraphicButtonWidget(
			WarpWindow,
			Border(7, 10 + i * 57, 269, 52), // diff 28 original top 593 or here 565  285
			Bgra(255, 255, 255, 255),
			ImageData(1593835585, 512, 512, new PictureDisplayer(
				{
					PictureView(57, 129, 6, 30), // Middle
					PictureView(63, 129, 7, 30), // Right
					PictureView(50, 129, 7, 30), // Left
					PictureView(80, 129, 6, 30), // mid
					PictureView(86, 129, 7, 30), // right
					PictureView(73, 129, 7, 30), // left
					PictureView(103, 129, 6, 30), // mid
					PictureView(109, 129, 7, 30), // right
					PictureView(96, 129, 7, 30), // left

					/*PictureView(127, 18, 4, 4), // center
					PictureView(123, 14, 4, 4), // top left
					PictureView(127, 14, 4, 4), // top middle
					PictureView(131, 14, 4, 4), // top right
					PictureView(131, 18, 4, 4), // center right
					PictureView(131, 22, 4, 4), // bot right
					PictureView(127, 22, 4, 4), // bot middle
					PictureView(123, 22, 4, 4), // bot left
					PictureView(123, 18, 4, 4), // center left*/
				})),
				ImagePadding(251, 55, 255, 57, 4, 4, 4, 4),
				Callback(joinOnClickFn, -1),
				4, 3
				);

		WarpWindow->addWidget(listEntityPanel);
	}
	else
	{
		Logger::Log("Metto il pulsante");
		listEntityPanel = new TEWGraphicButtonWidget(
			WarpWindow,
			Border(7, 10 + i * 57, 269, 52), // diff 28 original top 593 or here 565  285
			Bgra(255, 255, 255, 255),
			ImageData(1593835585, 512, 512, new PictureDisplayer(
				{
					PictureView(57, 129, 6, 30), // Middle
					PictureView(63, 129, 7, 30), // Right
					PictureView(50, 129, 7, 30), // Left
					PictureView(80, 129, 6, 30), // mid
					PictureView(86, 129, 7, 30), // right
					PictureView(73, 129, 7, 30), // left
					PictureView(103, 129, 6, 30), // mid
					PictureView(109, 129, 7, 30), // right
					PictureView(96, 129, 7, 30), // left

					/*PictureView(127, 18, 4, 4), // center
					PictureView(123, 14, 4, 4), // top left
					PictureView(127, 14, 4, 4), // top middle
					PictureView(131, 14, 4, 4), // top right
					PictureView(131, 18, 4, 4), // center right
					PictureView(131, 22, 4, 4), // bot right
					PictureView(127, 22, 4, 4), // bot middle
					PictureView(123, 22, 4, 4), // bot left
					PictureView(123, 18, 4, 4), // center left*/
				})),
				ImagePadding(251, 55, 255, 57, 4, 4, 4, 4),
				Callback(joinPrivateOnClickFn, -1),
				4, 3
				);

		WarpWindow->addWidget(listEntityPanel);

		deleteEntityPanel = new TEWGraphicButtonWidget(
			WarpWindow,
			Border(15, 15 + i * 57, 48, 23), // diff 28 original top 593 or here 565  285
			Bgra(255, 255, 255, 255),
			ImageData(1593835576, 512, 512, new PictureDisplayer(
				{
					PictureView(300, 488, 48, 23), // Middle
					PictureView(300, 488, 48, 23), // Middle
					PictureView(351, 488, 48, 23), // Middle

					/*PictureView(127, 18, 4, 4), // center
					PictureView(123, 14, 4, 4), // top left
					PictureView(127, 14, 4, 4), // top middle
					PictureView(131, 14, 4, 4), // top right
					PictureView(131, 18, 4, 4), // center right
					PictureView(131, 22, 4, 4), // bot right
					PictureView(127, 22, 4, 4), // bot middle
					PictureView(123, 22, 4, 4), // bot left
					PictureView(123, 18, 4, 4), // center left*/
				})),
				ImagePadding(0, 0, 0, 0, 0, 0),
				Callback(deleteOnClickFn, -1),
				0, 3
				);
		deleteEntityPanel->setVisible(false);
		WarpWindow->addWidget(deleteEntityPanel);
	}

	listEntityPanel->setVisible(true);
	Logger::Log("panel n%d: %x", i, listEntityPanel);

	pseudonymLabel = new TEWLabel(
		WarpWindow,
		Border(115, 24 + i * 57, 120, 20),
		TextStyle(3,
			TextShadowOrientation::ShadowAll,
			Bgra(255, 255, 0, 255),
			Bgra(127, 127, 127, 128),
			TextAlignment::TopLeft
		),
		TextPosition(0, 0, 0, 0, new WString(L"Pseudonym"), true)
	);
	pseudonymLabel->setVisible(true);
	WarpWindow->addWidget(pseudonymLabel);
	Logger::Log("pseudonymLabel n%d: %x", i, pseudonymLabel);

	capacityLabel = new TEWLabel(
		WarpWindow,
		Border(15, 43 + i * 57, 250, 20),
		TextStyle(1,
			TextShadowOrientation::ShadowBottomLeft,
			Bgra(255, 255, 255, 255),
			Bgra(127, 127, 127, 128),
			TextAlignment::CenteredLeft
		),
		TextPosition(0, 0, 66, 15, new WString(L"?/?"), true)
	);
	capacityLabel->setVisible(true);
	WarpWindow->addWidget(capacityLabel);

	Logger::Log("capacityLabel n%d: %x", i, capacityLabel);


	/*btJoin = new TEWGraphicButtonWidget(
		WarpWindow,
		Border(400, 88 + i * 57, 157, 23),
		Bgra(255, 255, 255, 255),
		ImageData(1593835585, 512, 512, new PictureDisplayer(
			{
				PictureView(419, 308, 5, 24), // Middle
				PictureView(424, 308, 10, 24), // Right
				PictureView(409, 308, 10, 24), // Left
				PictureView(445, 308, 5, 24),
				PictureView(450, 308, 10, 24),
				PictureView(435, 308, 10, 24),
				PictureView(471, 308, 5, 24),
				PictureView(476, 308, 10, 24),
				PictureView(461, 308, 10, 24),
			})),
			ImagePadding(125, 20, 135, 20, 10, 0, 10, 0),
			Callback(joinOnClickFn, -1),
			4, 3
			);
	btJoin->setVisible(true);
	WarpWindow->addWidget(btJoin);

	Logger::Log("btJoin %x", btJoin);

	TEWLabel* joinLabel = new TEWLabel(
		btJoin,
		Border(0, 0, btJoin->getBorder().getWidth(), btJoin->getBorder().getHeight()),
		TextStyle(1, TextShadowOrientation::ShadowBottomRight, Bgra(220, 150, 250, 128), Bgra(150, 250, 220, 255), TextAlignment::CenteredCentered),
		TextPosition(
			btJoin->getBorder().getWidth() / 2 - 5,
			btJoin->getBorder().getHeight() / 2 - 2,
			0, 0, new WString(L"Teleport"), true
		)
	);
	joinLabel->setVisible(true);
	btJoin->addWidget(joinLabel);*/
	/*if (!isPrivate)
	{
		setVisible(true);
		return;
	}*/
	setVisible(true, false);
}

void WarpModule::SetPublicWarpList()
{
	publicListPanel = new TEWCustomFormWidget(
		warpWindow,
		Border(7, 34, 297, 360),
		ImageData(1593835585, 512, 512, new PictureDisplayer(
			{
				PictureView(127, 18, 4, 4),
				PictureView(123, 14, 4, 4),
				PictureView(127, 14, 4, 4),
				PictureView(131, 14, 4, 4),
				PictureView(131, 18, 4, 4),
				PictureView(131, 22, 4, 4),
				PictureView(127, 22, 4, 4),
				PictureView(123, 22, 4, 4),
				PictureView(123, 18, 4, 4),
			})),
			ImagePadding(287, 357, 290, 357, 4, 4, 4, 4)
			);
	publicListPanel->setVisible(true);
	warpWindow->addWidget(publicListPanel);

	sb = new ScrollBar(
		publicListPanel,
		Border(276, 8, 17, 346),
		[this](ScrollBar::IndexType index) { scrollIndex = index; refresh(false); },
		6
	);
	sb->SetCurrentItemsNumber(0);

}

void WarpModule::SetPrivateWarpList()
{
	privateListPanel = new TEWCustomFormWidget(
		warpWindow,
		Border(7, 34, 297, 360),
		ImageData(1593835585, 512, 512, new PictureDisplayer(
			{
				PictureView(127, 18, 4, 4),
				PictureView(123, 14, 4, 4),
				PictureView(127, 14, 4, 4),
				PictureView(131, 14, 4, 4),
				PictureView(131, 18, 4, 4),
				PictureView(131, 22, 4, 4),
				PictureView(127, 22, 4, 4),
				PictureView(123, 22, 4, 4),
				PictureView(123, 18, 4, 4),
			})),
			ImagePadding(287, 357, 290, 357, 4, 4, 4, 4)
			);
	privateListPanel->setVisible(true);
	warpWindow->addWidget(privateListPanel);

	sbPrivate = new ScrollBar(
		privateListPanel,
		Border(276, 8, 17, 346),
		[this](ScrollBar::IndexType index) { scrollIndex = index; refresh(true); },
		6
	);
	sbPrivate->SetCurrentItemsNumber(0);
}

void WarpModule::SetPublicWarpOff()
{
	publicWarpButtonOff = new TEWGraphicButtonWidget(
		warpWindow,
		Border(7, 394, 100, 42), // diff 28 original top 593 or here 565  285
		Bgra(255, 255, 255, 255),
		ImageData(1593835585, 512, 512, new PictureDisplayer(
			{
				PictureView(131, 253, 129, 32), // Middlezagith
				PictureView(131, 253, 129, 32), // Middle
				PictureView(131, 253, 129, 32), // Middle
				//PictureView(63, 129, 7, 30), // Right
				//PictureView(50, 129, 7, 30), // Left
				//PictureView(231, 106, 28, 33), // mid
				//PictureView(259, 106, 26, 33), // right
				//PictureView(205, 106, 26, 33), // left
			})),
			ImagePadding(0, 0, 0, 0, 0, 0),
			Callback(setPublicVisibleClickFn, -1),
			0, 3
			);
	/*ImageData(1593835585, 512, 512, new PictureDisplayer(
		{
			PictureView(57, 129, 6, 30), // Middle
			PictureView(63, 129, 7, 30), // Right
			PictureView(50, 129, 7, 30), // Left
			PictureView(57, 129, 6, 30), // Middle
			PictureView(63, 129, 7, 30), // Right
			PictureView(50, 129, 7, 30), // Left
			PictureView(57, 129, 6, 30), // Middle
			PictureView(63, 129, 7, 30), // Right
			PictureView(50, 129, 7, 30), // Left
			PictureView(103, 129, 6, 30), // mid
			PictureView(109, 129, 7, 30), // right
			PictureView(96, 129, 7, 30), // left
		})),
		ImagePadding(68, 39, 255, 76, 4, 4, 4, 4),
		Callback(joinOnClickFn, -1),
		4, 3
		);*/

	publicWarpButtonOff->setVisible(true);
	warpWindow->addWidget(publicWarpButtonOff);

	TEWLabel* joinLabel = new TEWLabel(
		publicWarpButtonOff,
		Border(0, 0, publicWarpButtonOff->getBorder().getWidth(), publicWarpButtonOff->getBorder().getHeight()),
		TextStyle(1, TextShadowOrientation::ShadowBottomRight, Bgra(255, 255, 255, 255), Bgra(0, 0, 0, 255), TextAlignment::CenteredCentered),
		TextPosition(
			publicWarpButtonOff->getBorder().getWidth() / 2 - 5,
			publicWarpButtonOff->getBorder().getHeight() / 2 - 2,
			0, 0, new WString(L"Public Warps"), true
		)
	);
	joinLabel->setVisible(true);
	publicWarpButtonOff->addWidget(joinLabel);
}

void WarpModule::SetPublicWarpOn()
{
	publicWarpButtonOn = new TEWGraphicButtonWidget(
		warpWindow,
		Border(7, 394, 100, 42), // diff 28 original top 593 or here 565  285
		Bgra(255, 255, 255, 255),
		ImageData(1593835585, 512, 512, new PictureDisplayer(
			{
				PictureView(1, 251, 129, 34), // Middle
				PictureView(1, 251, 129, 34), // Middle
				PictureView(1, 251, 129, 34), // Middle
				//PictureView(63, 129, 7, 30), // Right
				//PictureView(50, 129, 7, 30), // Left
				//PictureView(231, 106, 28, 33), // mid
				//PictureView(259, 106, 26, 33), // right
				//PictureView(205, 106, 26, 33), // left
			})),
			ImagePadding(0, 0, 0, 0, 0, 0),
			Callback(nullptr, -1),
			0, 3
			);

	publicWarpButtonOn->setVisible(false);
	warpWindow->addWidget(publicWarpButtonOn);

	TEWLabel* joinLabel = new TEWLabel(
		publicWarpButtonOn,
		Border(0, 0, publicWarpButtonOn->getBorder().getWidth(), publicWarpButtonOn->getBorder().getHeight()),
		TextStyle(1, TextShadowOrientation::ShadowBottomRight, Bgra(255, 255, 255, 255), Bgra(0, 0, 0, 255), TextAlignment::CenteredCentered),
		TextPosition(
			publicWarpButtonOn->getBorder().getWidth() / 2 - 5,
			publicWarpButtonOn->getBorder().getHeight() / 2 - 2,
			0, 0, new WString(L"Public Warps"), true
		)
	);
	joinLabel->setVisible(true);
	publicWarpButtonOn->addWidget(joinLabel);
}

void WarpModule::SetPrivateWarpOff()
{
	privateWarpButtonOff = new TEWGraphicButtonWidget(
		warpWindow,
		Border(107, 394, 100, 42), // diff 28 original top 593 or here 565  285
		Bgra(255, 255, 255, 255),
		ImageData(1593835585, 512, 512, new PictureDisplayer(
			{
				PictureView(131, 253, 129, 32), // Middlezagith
				PictureView(131, 253, 129, 32), // Middle
				PictureView(131, 253, 129, 32), // Middle
				//PictureView(63, 129, 7, 30), // Right
				//PictureView(50, 129, 7, 30), // Left
				//PictureView(231, 106, 28, 33), // mid
				//PictureView(259, 106, 26, 33), // right
				//PictureView(205, 106, 26, 33), // left
			})),
			ImagePadding(0, 0, 0, 0, 0, 0),
			Callback(setPrivateVisibleClickFn, -1),
			0, 3
			);
	/*ImageData(1593835585, 512, 512, new PictureDisplayer(
		{
			PictureView(57, 129, 6, 30), // Middle
			PictureView(63, 129, 7, 30), // Right
			PictureView(50, 129, 7, 30), // Left
			PictureView(57, 129, 6, 30), // Middle
			PictureView(63, 129, 7, 30), // Right
			PictureView(50, 129, 7, 30), // Left
			PictureView(57, 129, 6, 30), // Middle
			PictureView(63, 129, 7, 30), // Right
			PictureView(50, 129, 7, 30), // Left
			PictureView(103, 129, 6, 30), // mid
			PictureView(109, 129, 7, 30), // right
			PictureView(96, 129, 7, 30), // left
		})),
		ImagePadding(68, 39, 255, 76, 4, 4, 4, 4),
		Callback(joinOnClickFn, -1),
		4, 3
		);*/

	privateWarpButtonOff->setVisible(true);
	warpWindow->addWidget(privateWarpButtonOff);

	TEWLabel* joinLabel = new TEWLabel(
		privateWarpButtonOff,
		Border(0, 0, privateWarpButtonOff->getBorder().getWidth(), privateWarpButtonOff->getBorder().getHeight()),
		TextStyle(1, TextShadowOrientation::ShadowBottomRight, Bgra(255, 255, 255, 255), Bgra(0, 0, 0, 255), TextAlignment::CenteredCentered),
		TextPosition(
			privateWarpButtonOff->getBorder().getWidth() / 2 - 5,
			privateWarpButtonOff->getBorder().getHeight() / 2 - 2,
			0, 0, new WString(L"Private Warps"), true
		)
	);
	joinLabel->setVisible(true);
	privateWarpButtonOff->addWidget(joinLabel);
}

void WarpModule::SetPrivateWarpOn()
{
	privateWarpButtonOn = new TEWGraphicButtonWidget(
		warpWindow,
		Border(107, 394, 100, 42), // diff 28 original top 593 or here 565  285
		Bgra(255, 255, 255, 255),
		ImageData(1593835585, 512, 512, new PictureDisplayer(
			{
				PictureView(1, 251, 129, 34), // Middle
				PictureView(1, 251, 129, 34), // Middle
				PictureView(1, 251, 129, 34), // Middle
				//PictureView(63, 129, 7, 30), // Right
				//PictureView(50, 129, 7, 30), // Left
				//PictureView(231, 106, 28, 33), // mid
				//PictureView(259, 106, 26, 33), // right
				//PictureView(205, 106, 26, 33), // left
			})),
			ImagePadding(0, 0, 0, 0, 0, 0),
			Callback(nullptr, -1),
			0, 3
			);

	privateWarpButtonOn->setVisible(false);
	warpWindow->addWidget(privateWarpButtonOn);

	TEWLabel* joinLabel = new TEWLabel(
		privateWarpButtonOn,
		Border(0, 0, privateWarpButtonOn->getBorder().getWidth(), privateWarpButtonOn->getBorder().getHeight()),
		TextStyle(1, TextShadowOrientation::ShadowBottomRight, Bgra(255, 255, 255, 255), Bgra(0, 0, 0, 255), TextAlignment::CenteredCentered),
		TextPosition(
			privateWarpButtonOn->getBorder().getWidth() / 2 - 5,
			privateWarpButtonOn->getBorder().getHeight() / 2 - 2,
			0, 0, new WString(L"Private Warps"), true
		)
	);
	joinLabel->setVisible(true);
	privateWarpButtonOn->addWidget(joinLabel);
}

void WarpModule::SetPrivateVisible() noexcept
{
	privateWarpButtonOff->setVisible(false);
	privateWarpButtonOn->setVisible(true);
	publicWarpButtonOff->setVisible(true);
	publicWarpButtonOn->setVisible(false);
	publicListPanel->setVisible(false);
	settingsBTN->setVisible(true);
	btJoin->setVisible(true);
	privateListPanel->setVisible(true);
}

void WarpModule::SetPublicVisible() noexcept
{
	privateWarpButtonOff->setVisible(true);
	privateWarpButtonOn->setVisible(false);
	publicWarpButtonOff->setVisible(false);
	publicWarpButtonOn->setVisible(true);
	publicListPanel->setVisible(true);
	settingsBTN->setVisible(false);
	btJoin->setVisible(false);
	privateListPanel->setVisible(false);
}

void WarpModule::EntityPanel::setVisible(bool Value, bool forced) noexcept
{
	listEntityPanel->setVisible(Value);
	pseudonymLabel->setVisible(Value);
	capacityLabel->setVisible(Value);
	if (deleteEntityPanel != nullptr)
	{
		if (forced)
			deleteEntityPanel->setVisible(Value);
		else
			deleteEntityPanel->setVisible(isSettingsOpen);
	}
	//btJoin->setVisible(Value);
}

void WarpModule::refresh(bool isPrivate) noexcept
{
	if (!isPrivate)
	{
		for (auto& inst : entitiesPanel)
			inst->setVisible(false, false);

		for (auto i = scrollIndex; i < scrollIndex + 6 && i < packetsFlemme.size(); i++)
		{
			entitiesPanel[i - scrollIndex]->handleData(packetsFlemme[i], false);
			entitiesPanel[i - scrollIndex]->setVisible(true, false);
		}
		return;
	}

	for (auto i = 0; i < entitiesPrivatePanel.size(); i++)
	{
		entitiesPrivatePanel[i]->setVisible(false, false);
		if (shouldMove)
		{
			entitiesPrivatePanel[i]->move(1, 10 + i * 57); // panel
			entitiesPrivatePanel[i]->move(2, 24 + i * 57);// capacity
			entitiesPrivatePanel[i]->move(3, 43 + i * 57);// capacity
			entitiesPrivatePanel[i]->move(4, 15 + i * 57);// delete
		}
	}
	shouldMove = false;
	for (auto i = scrollIndex; i < scrollIndex + 6 && i < privatePacketsFlemme.size(); i++)
	{
		entitiesPrivatePanel[i - scrollIndex]->handleData(privatePacketsFlemme[i], true);
		entitiesPrivatePanel[i - scrollIndex]->setVisible(true, false);
	}
}

void WarpModule::removeAll() noexcept
{
	for (auto i = 0; i < privatePacketsFlemme.size(); i++)
	{
		auto nb = ToNumberUnsafe<int32_t>(privatePacketsFlemme[i][1].c_str());
		Logger::Log("Rimuovoo");
		entitiesPrivatePanel[i]->setVisible(false, true);
	}
	privatePacketsFlemme.clear();
	entitiesPrivatePanel.clear();
	for (auto i = 0; i < packetsFlemme.size(); i++)
	{
		auto nb = ToNumberUnsafe<int32_t>(packetsFlemme[i][1].c_str());
		Logger::Log("Rimuovoo");
		entitiesPanel[i]->setVisible(false, false);
	}
	packetsFlemme.clear();
	entitiesPanel.clear();

	if (button != nullptr)
	{
		button->setVisible(false);
	}

	if (warpWindow != nullptr)
		warpWindow->setVisible(false);

}

void WarpModule::EntityPanel::move(int16_t index, int16_t value)
{
	switch (index)
	{
	case 1:
		listEntityPanel->setWidgetPosition(7, value);
		break;
	case 2:
		pseudonymLabel->setWidgetPosition(115, value);
		break;
	case 3:
		capacityLabel->setWidgetPosition(15, value);
		break;
	case 4:
		deleteEntityPanel->setWidgetPosition(15, value);
		break;
	}
}
void WarpModule::EntityPanel::handleData(const std::vector<std::string>& Packet, bool isPrivate) noexcept
{
	// aa_lodinst_new [ID] [img_id] [PSEUDO] [LVL] [LVL_HERO] [CAPACITY] [MAX_CAPACITY]
	setInstanceId(ToNumberUnsafe<int32_t>(Packet[1].c_str()));
	setPseudonym(Packet[3]);
	setCordinates(ToNumberUnsafe<int16_t>(Packet[4].c_str()), ToNumberUnsafe<int16_t>(Packet[5].c_str()), isPrivate);

	if (isPrivate)
	{
		setDeleteInstanceId(ToNumberUnsafe<int32_t>(Packet[1].c_str()));
	}
}

void WarpModule::EntityPanel::setInstanceId(int32_t Value) noexcept
{
	listEntityPanel->setCallback(Callback(listEntityPanel->getCallback().getFunc(), Value));
}

void WarpModule::EntityPanel::setDeleteInstanceId(int32_t Value) noexcept
{
	Logger::Log("isSettingsOpen enabled: %x", isSettingsOpen);
	deleteEntityPanel->setCallback(Callback(deleteEntityPanel->getCallback().getFunc(), Value));
	//deleteEntityPanel->setVisible(isSettingsOpen);
}

void WarpModule::EntityPanel::setPseudonym(const std::string& Pseudonym) noexcept
{
	pseudonymLabel->getTextPosition().setText((new WString(StringToW(Pseudonym).data()))->get());
}

void WarpModule::EntityPanel::setCordinates(int16_t PosX, int16_t PosY, bool isPrivate) noexcept
{
	if (!isPrivate)
	{
		std::wstring capacity = +L"X:" + std::to_wstring(PosX) + L" Y: " + std::to_wstring(PosY) + L" Price: 1000";
		capacityLabel->getTextPosition().setText((new WString(capacity.data()))->get());
		return;
	}
	std::wstring capacity = +L"X:" + std::to_wstring(PosX) + L" Y: " + std::to_wstring(PosY);
	capacityLabel->getTextPosition().setText((new WString(capacity.data()))->get());
}