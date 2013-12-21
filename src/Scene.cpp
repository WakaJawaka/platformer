#include "Game/Scene.h"
#include "Physics/Collision.h"

namespace pf
{
	Scene::Scene()		
	{

	}

	Scene::~Scene()
	{

	}

	void Scene::addEntity(GameEntity* pEntity)
	{
		_entities.push_back(GameEntityPtr(pEntity));
	}

	void Scene::removeEntity(GameEntity* pEntity)
	{
		
	}

	void Scene::setBackgroundColor(const sf::Color& color)
	{
		_backgroundColor = color;
	}

	void Scene::draw(const pf::DrawContext& context)
	{
		context.pRenderWindow->clear(_backgroundColor);

		for(unsigned int i = 0; i < _entities.size(); i++)
		{
			_entities.at(i)->draw(context);
		}
	}

	void Scene::update(const pf::UpdateContext& context)
	{
		for(unsigned int i = 0; i < _entities.size(); i++)
		{
			pf::GameEntity* it = _entities.at(i).get();
			std::vector<pf::GameEntity*> collisions;

			getEntityCollisions(it, collisions);

			it->update(context, collisions);
		}
	}

	void Scene::getEntityCollisions(pf::GameEntity* entity, std::vector<pf::GameEntity*>& collisions)
	{
		if(!entity->getSprite())
		{
			return;
		}

		for(unsigned int i = 0; i < _entities.size(); i++)
		{
			pf::GameEntity* it = _entities.at(i).get();

			if(it == entity || !it->getSprite())
			{
				continue;
			}

			if(pf::Collision::boundingBoxTest(*entity->getSprite(), *it->getSprite()))
			{
				collisions.push_back(it);
			}
		}
	}
}