#pragma once

namespace pf
{
	class Displayable
	{
	public:
		Displayable(float x, float y)
		{
			setPosition(x, y);
		}

		virtual void setPosition(float x, float y)
		{
			_x = x;
			_y = y;
		}

		float getX()
		{
			return _x;
		}

		float getY()
		{
			return _y;
		}

		virtual void setX(float x)
		{
			_x = x;
		}

		virtual void setY(float y)
		{
			_y = y;
		}

	private:
		float _x;
		float _y;
	};
}