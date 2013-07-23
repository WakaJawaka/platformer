#pragma once

#include <vector>

#include "GameEntity.h"
#include "DrawContext.h"
#include "UpdateContext.h"

namespace pf
{
	class Scene
	{
	public:
		Scene(const sf::String& name, const sf::Color& backgroundColor);

		virtual ~Scene();

		void setBackgroundColor(const sf::Color& color);

		void addEntity(pf::GameEntity* pEntity);

		void removeEntity(pf::GameEntity* pEntity);

		virtual void draw(const pf::DrawContext& context);

		virtual void update(const pf::UpdateContext& context);

		virtual void onEvent(const sf::Event& e) = 0;

	private:
		sf::String _Name;
		sf::Color _BackgroundColor;
		std::vector<pf::GameEntity*> _Entities;
	};
}