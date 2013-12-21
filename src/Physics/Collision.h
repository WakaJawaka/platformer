#pragma once

#include <SFML/Graphics.hpp>

namespace pf
{
	class Collision
	{
	public:
		//////
		/// Test for bounding box collision using Oriented Bounding Box
		/// Supports scaling and rotation
		/// Code is from Rotated Rectangles Collision Detection, Oren Becker, 2001
		/// http://www.ragestorm.net/tutorial?id=22
		//////
		static bool boundingBoxTest(const sf::Sprite& Object1, const sf::Sprite& Object2);
	};
}