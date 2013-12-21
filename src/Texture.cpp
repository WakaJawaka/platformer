#include "Game/Texture.h"

namespace pf
{
	void Texture::fillTexture(sf::Texture& texture, int width, int height, sf::Color color)
	{
		texture.create(width, height);

		int length = width * height * 4;
		sf::Uint8* buffer = new sf::Uint8[length];

		for(int i = 0; i < length; i += 4)
		{
			buffer[i] = color.r;
			buffer[i + 1] = color.g;
			buffer[i + 2] = color.b;
			buffer[i + 3] = color.a;
		}

		texture.update(buffer);

		delete buffer;
	}
}