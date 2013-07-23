#include "Entities/Player.h"
#include "Platform/Platform.h"

namespace pf
{
	Player::Player()
		:pf::GameEntity("player"), 
		 pf::Moveable(0.0f, 0.0f, 5.0f, 200.0f),

		 _pTexture(new sf::Texture())
	{
		_pTexture->loadFromFile("data/images/player.png");

		_pSprite = std::shared_ptr<sf::Sprite>(new sf::Sprite(*_pTexture));
	}

	Player::~Player()
	{

	}

	void Player::draw(const pf::DrawContext& context)
	{
		_pSprite->setPosition(getX(), getY());

		context.pRenderWindow->draw(*_pSprite);
	}

	void Player::update(const pf::UpdateContext& context)
	{
		if(context.actionsMapping.isActionPressed(0, pf::GameAction::MOVE_RIGHT))
		{
			move(pf::Direction::RIGHT);
		}
		else if(context.actionsMapping.isActionPressed(0, pf::GameAction::MOVE_LEFT))
		{
			move(pf::Direction::LEFT);
		}
		else
		{
			stopMoving();
		}

		if(context.actionsMapping.isActionPressed(0, pf::GameAction::RUN))
		{
			setMaxVelocity(400.0f);
		}
		else
		{
			setMaxVelocity(200.0f);
		}

		applyPhysics(context);
	}
}