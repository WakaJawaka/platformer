#pragma once

#include <SFML/Graphics.hpp>
#include <vector>

#include "Game/GameEntity.h"
#include "Game/Positionable.h"

namespace pf
{
	class Label : public pf::GameEntity, public pf::Positionable
	{
	public:
		Label(const sf::String& text, sf::Font &font, int size);

		virtual ~Label();

		void setText(const sf::String& text);

		void draw(const pf::DrawContext& context);

		void update(const pf::UpdateContext& context, std::vector<pf::GameEntity*>& collisions);

		sf::Sprite* getSprite()
		{
			return 0;
		}

	private:
		sf::Text _Text;
	};
}