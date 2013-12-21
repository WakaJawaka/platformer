#pragma once

#include "Positionable.h"
#include "Physics/PhysicsInfo.h"
#include "UpdateContext.h"
#include "Game/GameEntity.h"

namespace pf
{
	enum Direction
	{
		UP,
		RIGHT,
		DOWN,
		LEFT
	};

	enum CollisionDirection
	{
		COLLISION_TOP = 0,
		COLLISION_RIGHT = 1,
		COLLISION_BOTTOM = 2,
		COLLISION_LEFT = 3
	};

	class Moveable : public pf::Positionable
	{
	public:
		Moveable(float acceleration, float maxVelocity, float jumpVelocity);

		pf::PhysicsInfo& getPhysicsInfo();

		void applyPhysics(const pf::UpdateContext& context, std::vector<pf::GameEntity*>& collisions);

		void move(pf::Direction direction);
		
		void stopMoving();

		void jump();

		void setGravity(float acceleration, float maxVelocity);

		void resetGravity();

		void setAcceleration(float acceleration);

		void setMaxVelocity(float maxVelocity);

		sf::Vector2f getTotalVelocity();

		sf::Vector2f getTotalAcceleration();

	private:
		void applyMovement(const pf::UpdateContext& context, pf::PhysicsInfo* pPhysicsInfo);

		void applyGravity(const pf::UpdateContext& context, pf::PhysicsInfo* pPhysicsInfo);

		void checkCollisions(std::vector<pf::GameEntity*>& collisions, pf::PhysicsInfo* pPhysicsInfo);

		CollisionDirection getCollisionDirection(pf::Positionable* collision);

		void arrangePosition(sf::Vector2f& position);

		pf::PhysicsInfo _physicsInfo;

		pf::PhysicsInfo _movementInfo;

		pf::PhysicsInfo _gravityInfo;

		bool _isJumping;

		int _jumpFrames;

		float _acceleration;

		float _gravityAcceleration;

		float _maxGravityVelocity;

		float _maxVelocity;

		float _jumpVelocity;

		sf::Vector2f _maxPosition;

		sf::Vector2f _minPosition;
	};
}