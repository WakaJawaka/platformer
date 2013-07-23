#pragma once

#include <SFML/Graphics.hpp>

#include <iostream>

namespace pf
{
	class PhysicsInfo
	{
	public:
		PhysicsInfo()
		{
			setAcceleration(0, 0);
			setVelocity(0, 0);
		}

		~PhysicsInfo()
		{

		}

		sf::Vector2f apply(float x, float y, sf::Int64 microsecondsElapsed)
		{
			float seconds = ((float)microsecondsElapsed) / 1000000;

			_velocity.x += (seconds * _acceleration.x);
			_velocity.y += (seconds * _acceleration.y);

			float toAddX = _velocity.x * seconds;
			float toAddY = _velocity.y * seconds;

			return sf::Vector2f(x + toAddX, y + toAddY);
		}

		void setAcceleration(float x, float y)
		{
			_acceleration.x = x;
			_acceleration.y = y;
		}

		void setAccelerationX(float x)
		{
			_acceleration.x = x;
		}

		void setAccelerationY(float y)
		{
			_acceleration.y = y;
		}

		void addAcceleration(float x, float y)
		{
			_acceleration.x += x;
			_acceleration.y += y;
		}

		void setVelocity(float x, float y)
		{
			_velocity.x = x;
			_velocity.y = y;
		}
		
		void setVelocityX(float x)
		{
			_velocity.x = x;
		}

		void setVelocityY(float y)
		{
			_velocity.y = y;
		}

		void addVelocity(float x, float y)
		{
			_velocity.x += x;
			_velocity.y += y;
		}

		sf::Vector2f getAcceleration()
		{
			return _acceleration;
		}

		sf::Vector2f getVelocity()
		{
			return _velocity;
		}

	private:
		sf::Vector2f _acceleration;
		sf::Vector2f _velocity;
	};
}