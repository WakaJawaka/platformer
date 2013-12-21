#pragma once

#include <memory>
#include <vector>

#include "GameEntity.h"
#include "DrawContext.h"
#include "UpdateContext.h"

namespace pf
{
	typedef std::shared_ptr<GameEntity> GameEntityPtr;

	class Scene
	{
	public:
		Scene();

		virtual ~Scene();

		void setBackgroundColor(const sf::Color& color);

		void addEntity(pf::GameEntity* pEntity);

		void removeEntity(pf::GameEntity* pEntity);

		virtual void draw(const pf::DrawContext& context);

		virtual void update(const pf::UpdateContext& context);

		virtual void onEvent(const sf::Event& e) = 0;

	private:
		void getEntityCollisions(pf::GameEntity* entity, std::vector<pf::GameEntity*>& collisions);
		
		sf::String _name;
		sf::Color _backgroundColor;
		std::vector<GameEntityPtr> _entities;
	};
}