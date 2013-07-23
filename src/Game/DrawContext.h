#pragma once

#include <SFML/Graphics.hpp>

namespace pf
{
	class DrawContext
	{
	public:
		DrawContext(sf::RenderWindow* pRenderWindow)
		{
			this->pRenderWindow = pRenderWindow;
		}

		sf::RenderWindow* pRenderWindow;
	};
}