#include <SFML/Graphics.hpp>
#include <map>
#include "Physics/Collision.h"

namespace pf
{
	sf::Vector2f getSpriteCenter (const sf::Sprite& Object)
	{
		sf::FloatRect AABB = Object.getGlobalBounds();

		return sf::Vector2f (AABB.left+AABB.width/2.f, AABB.top+AABB.height/2.f);
	}

	sf::Vector2f getSpriteSize (const sf::Sprite& Object)
	{
		sf::IntRect OriginalSize = Object.getTextureRect();
		sf::Vector2f Scale = Object.getScale();

		return sf::Vector2f (OriginalSize.width*Scale.x, OriginalSize.height*Scale.y);
	}

	bool Collision::boundingBoxTest(const sf::Sprite& object1, const sf::Sprite& object2) 
	{
		sf::Vector2f A, B, C, BL, TR;
		sf::Vector2f HalfSize1 = getSpriteSize(object1)/2.f;
		sf::Vector2f HalfSize2 = getSpriteSize(object2)/2.f;

		//Get the Angle we're working on
		const double RadToDeg = 3.14159265358979323846/180.0;
		float Angle = object1.getRotation() - object2.getRotation();
		float CosA = cos(Angle * RadToDeg);
		float SinA = sin(Angle * RadToDeg);
 
		float t, x, a, dx, ext1, ext2;
 
		//Normalise the Center of object2 so its axis aligned an represented in
		//relation to Object 1
		C = getSpriteCenter(object2) - getSpriteCenter(object1);
 
		float O2Rot = object2.getRotation() * RadToDeg;
		float temp = C.x;
		C.x = temp * cos(O2Rot) + C.y * sin(O2Rot);
		C.y = -temp * sin(O2Rot) + C.y * cos(O2Rot);
 
		//Get the Corners
		BL = TR = C;
		BL -= HalfSize2;
		TR += HalfSize2;
 
		//Calculate the vertices of the rotate Rect
		A.x = -HalfSize1.y*SinA;
		B.x = A.x;
		t = HalfSize1.x*CosA;
		A.x += t;
		B.x -= t;
 
		A.y = HalfSize1.y*CosA;
		B.y = A.y;
		t = HalfSize1.x*SinA;
		A.y += t;
		B.y -= t;
 
		t = SinA * CosA;
 
		// verify that A is vertical min/max, B is horizontal min/max
		if (t < 0) 
		{
			t = A.x;
			A.x = B.x;
			B.x = t;
			t = A.y;
			A.y = B.y;
			B.y = t;
		}
 
		// verify that B is horizontal minimum (leftest-vertex)
		if (SinA < 0) 
		{
			B.x = -B.x;
			B.y = -B.y;
		}
 
		// if rr2(ma) isn't in the horizontal range of
		// colliding with rr1(r), collision is impossible
		if (B.x > TR.x || B.x > -BL.x) return false;
 
		// if rr1(r) is axis-aligned, vertical min/max are easy to get
		if (t == 0) 
		{
			ext1 = A.y;
			ext2 = -ext1;
		}// else, find vertical min/max in the range [BL.x, TR.x]
		else 
		{
			x = BL.x - A.x;
			a = TR.x - A.x;
			ext1 = A.y;
			// if the first vertical min/max isn't in (BL.x, TR.x), then
			// find the vertical min/max on BL.x or on TR.x
			if (a * x > 0) 
			{
				dx = A.x;
				if (x < 0) 
				{
					dx -= B.x;
					ext1 -= B.y;
					x = a;
				} 
				else 
				{
					dx += B.x;
					ext1 += B.y;
				}
				ext1 *= x;
				ext1 /= dx;
				ext1 += A.y;
			}
 
			x = BL.x + A.x;
			a = TR.x + A.x;
			ext2 = -A.y;
			// if the second vertical min/max isn't in (BL.x, TR.x), then
			// find the local vertical min/max on BL.x or on TR.x
			if (a * x > 0) 
			{
				dx = -A.x;
				if (x < 0) 
				{
					dx -= B.x;
					ext2 -= B.y;
					x = a;
				} else 
				{
					dx += B.x;
					ext2 += B.y;
				}
				ext2 *= x;
				ext2 /= dx;
				ext2 -= A.y;
			}
		}
 
		// check whether rr2(ma) is in the vertical range of colliding with rr1(r)
		// (for the horizontal range of rr2)
		return !((ext1 < BL.y && ext2 < BL.y) ||
				(ext1 > TR.y && ext2 > TR.y));
	}
}