#pragma once

#include <memory>

#include "MainWindow.h"
#include "SceneManager.h"

namespace pf 
{
	class Game
	{
	public:
		Game();

		~Game();

		void init();

		void start();

	private:
		void frame();

		void draw();

		void update();

		std::shared_ptr<sf::Clock> _pClock;

		std::shared_ptr<pf::Gamepad> _pGamepad;

		std::shared_ptr<pf::ActionsMapping> _pActionsMapping;

		std::shared_ptr<pf::MainWindow> _pMainWindow;

		std::shared_ptr<pf::SceneManager> _pSceneManager;
	};
}