#include "Game/Game.h"
#include "Platform/Platform.h"
#include "Game/TestScene.h"
#include "Game/Logger.h"

namespace pf 
{
	Game::Game() :
		_pMainWindow(new pf::MainWindow("Platformer", 800, 600)),
		_pSceneManager(new pf::SceneManager()),
		_pScene(new pf::DynamicScene()),
		_pGamepad(new pf::Gamepad()),
		_pActionsMapping(new pf::ActionsMapping(*_pGamepad)),
		_pClock(new sf::Clock())
	{
		_pMainWindow->setFramerateLimit(60);
	}

	Game::~Game()
	{

	}

	void Game::init()
	{
		Logger::getInstance().log("Initializing game");

		_pScene->load("data/scenes/test-scene.xml");

		_pSceneManager->setCurrentScene(_pScene.get());
	}

	void Game::start()
	{
		init();

		while(_pMainWindow->isOpen())
		{
			sf::Event event;

			while(_pMainWindow->pollEvent(event))
			{
				_pSceneManager->onEvent(event);

				if(event.type == sf::Event::Closed)
				{
					_pMainWindow->close();
				}
			}

			frame();
		}
	}

	void Game::frame()
	{
		draw();

		update();
	}

	void Game::draw()
	{
		_pSceneManager->draw(pf::DrawContext(_pMainWindow.get()));

		_pMainWindow->display();
	}

	void Game::update()
	{
		_pSceneManager->update(pf::UpdateContext(_pClock->restart().asMicroseconds(), *_pActionsMapping));
	}
}