#pragma once

#include <memory>

#include "../Game/GameEntity.h"
#include "../Game/Moveable.h"

namespace pf
{
	class Player: public pf::GameEntity, public pf::Moveable
	{
	public:
		Player();

		~Player();

		void draw(const pf::DrawContext& context);

		void update(const pf::UpdateContext& context);

	private:
		std::shared_ptr<sf::Sprite> _pSprite;
		std::shared_ptr<sf::Texture> _pTexture;
	};
}