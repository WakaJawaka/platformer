#include <cmath>

#include "Game/Moveable.h"
#include "Game/Logger.h"

namespace pf
{
	Moveable::Moveable(float acceleration, float maxVelocity, float jumpVelocity) :		 
		_acceleration(acceleration),
		_maxVelocity(maxVelocity),
		_jumpVelocity(jumpVelocity),
		_isJumping(false)
	{
		setGravity(0, 0);
	}

	pf::PhysicsInfo& Moveable::getPhysicsInfo()
	{
		return _physicsInfo;
	}

	void Moveable::applyPhysics(const UpdateContext& context, std::vector<pf::GameEntity*>& collisions)
	{
		pf::PhysicsInfo info;
		sf::Vector2f currentVelocity = _physicsInfo.getVelocity();
		sf::Vector2f currentAcceleration = _physicsInfo.getAcceleration();

		info.setVelocity(currentVelocity.x, currentVelocity.y);
		info.setAcceleration(currentAcceleration.x, currentAcceleration.y);

		applyMovement(context, &info);

		applyGravity(context, &info);

		checkCollisions(collisions, &info);

		sf::Vector2f newPosition = info.apply(getX(), getY(), context.elapsedTime);

		arrangePosition(newPosition);

		setPosition(newPosition.x, newPosition.y);

		if(_isJumping)
		{
			_jumpFrames++;
		}
	}

	void Moveable::applyMovement(const pf::UpdateContext& context, pf::PhysicsInfo* pPhysicsInfo)
	{
		_movementInfo.apply(getX(), getY(), context.elapsedTime);

		sf::Vector2f velocity = _movementInfo.getVelocity();

		pPhysicsInfo->addVelocity(velocity.x, velocity.y);
	}

	void Moveable::applyGravity(const pf::UpdateContext& context, pf::PhysicsInfo* pPhysicsInfo)
	{
		sf::Vector2f currentVelocity = _gravityInfo.getVelocity();

		_gravityInfo.apply(0, 0, context.elapsedTime);

		if(std::abs(currentVelocity.y) >= _maxGravityVelocity)
		{
			_gravityInfo.setAcceleration(0, 0);
			
			if(currentVelocity.y > 0)
			{
				_gravityInfo.setVelocityY(_maxGravityVelocity);
			}
			else
			{
				_gravityInfo.setVelocityY(-_maxGravityVelocity);
			}
		}
		else
		{
			_gravityInfo.setAcceleration(0, _gravityAcceleration);
		}

		sf::Vector2f velocity = _gravityInfo.getVelocity();

		pPhysicsInfo->addVelocity(velocity.x, velocity.y);
	}

	void Moveable::checkCollisions(std::vector<pf::GameEntity*>& collisions, pf::PhysicsInfo* pPhysicsInfo)
	{
		int size = collisions.size();

		_maxPosition.x = -1;
		_maxPosition.y = -1;
		_minPosition.x = -1;
		_minPosition.y = -1;

		for(int i = 0; i < size; i++)
		{
			pf::Positionable* collision = dynamic_cast<pf::Positionable*>(collisions.at(i));

			if(!collision)
			{
				continue;
			}

			CollisionDirection direction = getCollisionDirection(collision);
			sf::Vector2f movementVelocity = pPhysicsInfo->getVelocity();
			sf::Vector2f movementAcceleration = pPhysicsInfo->getAcceleration();

			switch(direction)
			{
			case COLLISION_TOP:
				resetGravity();

				if(_jumpFrames >= 1)
				{
					_movementInfo.setVelocityY(0);
					_movementInfo.setAccelerationY(0);

					_isJumping = false;
					_jumpFrames = 0;
				}

				if(movementVelocity.y > 0)
				{
					pPhysicsInfo->setVelocityY(0);
				}

				if(movementAcceleration.y > 0)
				{
					pPhysicsInfo->setAccelerationY(0);
				}

				_maxPosition.y = collision->getY() - getHeight();

				break;

			case COLLISION_BOTTOM:
				if(_jumpFrames >= 1)
				{
					_movementInfo.setVelocityY(0);
					_movementInfo.setAccelerationY(0);
				}

				if(movementVelocity.y < 0)
				{
					pPhysicsInfo->setVelocityY(0);
				}

				if(movementAcceleration.y < 0)
				{
					pPhysicsInfo->setAccelerationY(0);
				}

				_minPosition.y = collision->getY() + collision->getHeight();

				break;

			case COLLISION_LEFT:
				if(movementVelocity.x > 0)
				{
					pPhysicsInfo->setVelocityX(0);
				}

				if(movementAcceleration.x > 0)
				{
					pPhysicsInfo->setAccelerationX(0);
				}

				_maxPosition.x = collision->getX() - getWidth();

				break;

			case COLLISION_RIGHT:
				if(movementVelocity.x < 0)
				{
					pPhysicsInfo->setVelocityX(0);
				}

				if(movementAcceleration.x < 0)
				{
					pPhysicsInfo->setAccelerationX(0);
				}

				_minPosition.x = collision->getX() + collision->getWidth();

				break;
			}
		}
	}

	CollisionDirection Moveable::getCollisionDirection(pf::Positionable* collision)
	{
		float distances[4];

		distances[0] = ::abs((getY() + getHeight()) - collision->getY());
		distances[1] = ::abs((collision->getX() + collision->getWidth()) - getX());
		distances[2] = ::abs((collision->getY() + collision->getHeight()) - getY());
		distances[3] = ::abs((getX() + getWidth()) - collision->getX());

		int min = 0;

		for(int i = 0; i <= 3; i++)
		{
			if(distances[i] < distances[min])
			{
				min = i;
			}
		}

		switch(min)
		{
		case 0:
			return CollisionDirection::COLLISION_TOP;

		case 1:
			return CollisionDirection::COLLISION_RIGHT;

		case 2:
			return CollisionDirection::COLLISION_BOTTOM;

		default:
			return CollisionDirection::COLLISION_LEFT;
		}
	}

	void Moveable::arrangePosition(sf::Vector2f& position)
	{
		if(_maxPosition.x >= 0 && position.x > _maxPosition.x)
		{
			position.x = _maxPosition.x;
		}

		if(_maxPosition.y >= 0 && position.y > _maxPosition.y)
		{
			position.y = _maxPosition.y;
		}

		if(_minPosition.x >= 0 && position.x < _minPosition.x)
		{
			position.x = _minPosition.x;
		}

		if(_minPosition.y >= 0 && position.y < _minPosition.y)
		{
			position.y = _minPosition.y;
		}
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
				_movementInfo.setAccelerationX(-_acceleration);
			}
			else if(direction == Direction::RIGHT)
			{
				_movementInfo.setAccelerationX(_acceleration);
			}
		}
	}

	void Moveable::stopMoving()
	{
		_movementInfo.setAccelerationX(0);
		_movementInfo.setVelocityX(0);
	}

	void Moveable::jump()
	{
		if(!_isJumping)
		{
			Logger::getInstance().log("Jump!");
	
			_movementInfo.addAcceleration(0, -50.0f);
			_movementInfo.addVelocity(0, -_jumpVelocity);

			_isJumping = true;
			
			_jumpFrames = 0;
		}
	}

	void Moveable::setGravity(float acceleration, float maxVelocity)
	{
		_gravityAcceleration = acceleration;
		_maxGravityVelocity = maxVelocity;
	}

	void Moveable::resetGravity()
	{
		_gravityInfo.setAcceleration(0, _maxGravityVelocity);
		_gravityInfo.setVelocity(0, 0);
	}

	void Moveable::setAcceleration(float acceleration)
	{
		_acceleration = acceleration;
	}

	void Moveable::setMaxVelocity(float maxVelocity)
	{
		_maxVelocity = maxVelocity;
	}

	sf::Vector2f Moveable::getTotalVelocity()
	{
		return _movementInfo.getVelocity() + _gravityInfo.getVelocity() + _physicsInfo.getVelocity();
	}

	sf::Vector2f Moveable::getTotalAcceleration()
	{
		return _movementInfo.getAcceleration() + _gravityInfo.getAcceleration() + _physicsInfo.getAcceleration();
	}
}