#include "Game/MainWindow.h"

namespace pf 
{
	MainWindow::MainWindow(const sf::String& title, int width, int height) : 
		sf::RenderWindow(sf::VideoMode(width, height), title)
	{
		
	}

	MainWindow::~MainWindow()
	{

	}
}