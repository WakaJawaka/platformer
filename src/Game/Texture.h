#pragma once

#include <SFML/Graphics.hpp>

namespace pf
{
	class Texture
	{
	public:
		static void fillTexture(sf::Texture& texture, int width, int height, sf::Color color);
	};
}