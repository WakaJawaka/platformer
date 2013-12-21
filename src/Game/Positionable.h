#pragma once

#include <SFML/Graphics.hpp>

namespace pf
{
	class Positionable
	{
	public:
		Positionable()
		{
			_x = 0;
			_y = 0;
			_width = 0;
			_height = 0;
		}

		float getX()
		{
			return _x;
		}

		void setX(float x)
		{
			_x = x;
		}

		float getY()
		{
			return _y;
		}

		void setY(float y)
		{
			_y = y;
		}

		void setPosition(float x, float y)
		{
			setX(x);
			setY(y);
		}

		void setPosition(sf::Vector2u position)
		{
			setPosition((float) position.x, (float) position.y);
		}

		float getWidth()
		{
			return _width;
		}

		float getHeight()
		{
			return _height;
		}

	protected:
		void setWidth(float width)
		{
			_width = width;
		}

		void setHeight(float height)
		{
			_height = height;
		}

		void setSize(float width, float height)
		{
			setWidth(width);
			setHeight(height);
		}

		void setSize(sf::Vector2u size)
		{
			setSize((float) size.x, (float) size.y);
		}

	private:
		float _x;
		float _y;
		float _width;
		float _height;

	};
}