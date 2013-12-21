#pragma once

#include <memory>

#include "Game/GameEntity.h"
#include "Game/Moveable.h"

namespace pf
{
	class Platform: public pf::GameEntity, public pf::Positionable
	{
	public:
		Platform(int width, int height, sf::Color color);

		~Platform();

		void draw(const pf::DrawContext& context);

		void update(const pf::UpdateContext& context, std::vector<pf::GameEntity*>& collisions);

		sf::Sprite* getSprite()
		{
			return _pSprite.get();
		}

	private:
		std::shared_ptr<sf::Sprite> _pSprite;
		std::shared_ptr<sf::Texture> _pTexture;
	};
}