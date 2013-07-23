#include <cmath>

#include "Game/Moveable.h"

namespace pf
{
	Moveable::Moveable(float x, float y, float acceleration, float maxVelocity)
		: pf::Displayable(x, y),
		 
		_acceleration(acceleration),
		_maxVelocity(maxVelocity)
	{
		_physicsInfo.setAcceleration(0, 0);
		_physicsInfo.setVelocity(0, 0);

		_movementInfo.setAcceleration(0, 0);
		_movementInfo.setVelocity(0, 0);
	}

	pf::PhysicsInfo& Moveable::getPhysicsInfo()
	{
		return _physicsInfo;
	}

	void Moveable::applyPhysics(const UpdateContext& context)
	{
		_movementInfo.apply(getX(), getY(), context.elapsedTime);

		sf::Vector2f movementVelocity = _movementInfo.getVelocity();

		_physicsInfo.setVelocity(movementVelocity.x, movementVelocity.y);

		sf::Vector2f newPosition = _physicsInfo.apply(getX(), getY(), context.elapsedTime);

		setPosition(newPosition.x, newPosition.y);
	}

	void Moveable::move(Direction direction)
	{
		sf::Vector2f velocity = _movementInfo.getVelocity();

		if(std::abs(velocity.x) >= _maxVelocity)
		{
			_movementInfo.setAccelerationX(0);
			
			if(velocity.x > 0)
			{
				_movementInfo.setVelocityX(_maxVelocity);
			}
			else
			{
				_movementInfo.setVelocityX(-_maxVelocity);
			}
		}
		else
		{
			if(direction == Direction::LEFT)
			{
				_movementInfo.addAcceleration(-_acceleration, 0);
			}
			else if(direction == Direction::RIGHT)
			{
				_movementInfo.addAcceleration(_acceleration, 0);
			}
		}
	}

	void Moveable::stopMoving()
	{
		_movementInfo.setAcceleration(0, 0);
		_movementInfo.setVelocity(0, 0);
	}

	void Moveable::setAcceleration(float acceleration)
	{
		_acceleration = acceleration;
	}

	void Moveable::setMaxVelocity(float maxVelocity)
	{
		_maxVelocity = maxVelocity;
	}
}