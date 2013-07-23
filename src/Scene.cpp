#include "Game/Scene.h"
#include "Platform/Platform.h"

namespace pf
{
	Scene::Scene(const sf::String& name, const sf::Color& backgroundColor)
	{
		_Name = name;

		_BackgroundColor = backgroundColor;
	}

	Scene::~Scene()
	{

	}

	void Scene::addEntity(GameEntity* pEntity)
	{
		_Entities.push_back(pEntity);
	}

	void Scene::removeEntity(GameEntity* pEntity)
	{
		_Entities.erase(std::remove(_Entities.begin(), _Entities.begin(), pEntity), _Entities.end());
	}

	void Scene::setBackgroundColor(const sf::Color& color)
	{
		_BackgroundColor = color;
	}

	void Scene::draw(const pf::DrawContext& context)
	{
		context.pRenderWindow->clear(_BackgroundColor);

		for(unsigned int i = 0; i < _Entities.size(); i++)
		{
			_Entities.at(i)->draw(context);
		}
	}

	void Scene::update(const pf::UpdateContext& context)
	{
		for(unsigned int i = 0; i < _Entities.size(); i++)
		{
			_Entities.at(i)->update(context);
		}
	}
}