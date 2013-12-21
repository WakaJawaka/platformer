#pragma once

#include <SFML/Graphics.hpp>
#include <vector>

#include "DrawContext.h"
#include "UpdateContext.h"

namespace pf
{
	class GameEntity
	{
	public:
		GameEntity(const sf::String& name)
		{
			this->_Name = name;
		}

		virtual ~GameEntity()
		{

		}

		virtual void draw(const pf::DrawContext& context) = 0;

		virtual void update(const pf::UpdateContext& context, std::vector<pf::GameEntity*>& collisions) = 0;

		virtual sf::Sprite* getSprite() = 0;

	private:
		sf::String _Name;
	};
}