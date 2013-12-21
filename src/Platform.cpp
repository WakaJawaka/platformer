#include "Entities/Platform.h"
#include "Game/Texture.h"

namespace pf
{
	Platform::Platform(int width, int height, sf::Color color) :
		GameEntity("platform"),

		_pTexture(new sf::Texture())
	{
		setSize((float) width, (float) height);

		pf::Texture::fillTexture(*_pTexture, width, height, color);

		_pSprite = std::shared_ptr<sf::Sprite>(new sf::Sprite(*_pTexture));

		setSize(_pTexture->getSize());
	}

	Platform::~Platform()
	{

	}

	void Platform::draw(const pf::DrawContext& context)
	{
		_pSprite->setPosition(getX(), getY());

		context.pRenderWindow->draw(*_pSprite);
	}

	void Platform::update(const pf::UpdateContext& context, std::vector<pf::GameEntity*>& collisions)
	{

	}
}