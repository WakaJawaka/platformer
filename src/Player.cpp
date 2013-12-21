#include "Entities/Player.h"
#include "Platform/Platform.h"

namespace pf
{
	Player::Player() : 
		pf::GameEntity("player"), 
		pf::Moveable(800.0f, 200.0f, 350.0f),
		_jumpFlag(false),

		_pTexture(new sf::Texture())
	{
		_pTexture->loadFromFile("data/images/player.png");

		setSize(_pTexture->getSize());
	
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

	void Player::update(const pf::UpdateContext& context, std::vector<pf::GameEntity*>& collisions)
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

		if(context.actionsMapping.isActionPressed(0, pf::GameAction::JUMP))
		{
			if(!_jumpFlag)
			{
				jump();

				_jumpFlag = true;
			}
		}
		else
		{
			_jumpFlag = false;
		}

		applyPhysics(context, collisions);
	}
}