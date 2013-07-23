#include "Game/SceneManager.h"
#include "Platform/Platform.h"

#include <SFML/Window/Event.hpp>

namespace pf
{
	SceneManager::SceneManager()
	{
		_pCurrentScene = 0;
	}

	SceneManager::~SceneManager()
	{

	}

	void SceneManager::setCurrentScene(pf::Scene* scene)
	{
		_pCurrentScene = scene;
	}

	void SceneManager::draw(const pf::DrawContext& context)
	{
		if(_pCurrentScene)
		{
			this->_pCurrentScene->draw(context);
		}
	}

	void SceneManager::update(const pf::UpdateContext& context)
	{
		if(_pCurrentScene)
		{
			_pCurrentScene->update(context);
		}
	}

	void SceneManager::onEvent(const sf::Event& event)
	{
		if(_pCurrentScene)
		{
			_pCurrentScene->onEvent(event);
		}
	}
}