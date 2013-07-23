#pragma once

#include "Displayable.h"
#include "../Physics/PhysicsInfo.h"
#include "UpdateContext.h"

namespace pf
{
	enum Direction
	{
		UP,
		RIGHT,
		DOWN,
		LEFT
	};

	class Moveable : public pf::Displayable
	{
	public:
		Moveable(float x, float y, float acceleration, float maxVelocity);

		pf::PhysicsInfo& getPhysicsInfo();

		void applyPhysics(const pf::UpdateContext& context);

		void move(pf::Direction direction);

		void stopMoving();

		void setAcceleration(float acceleration);

		void setMaxVelocity(float maxVelocity);

	private:
		pf::PhysicsInfo _physicsInfo;

		pf::PhysicsInfo _movementInfo;

		float _acceleration;

		float _maxVelocity;
	};
}