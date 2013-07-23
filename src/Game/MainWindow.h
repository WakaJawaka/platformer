#pragma once

#include <SFML/Graphics.hpp>

namespace pf
{
	class MainWindow : public sf::RenderWindow
	{
	public:
		MainWindow(const sf::String& title, int width, int height);

		~MainWindow();
	};
}