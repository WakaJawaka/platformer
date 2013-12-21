#include "Entities/Ui/Label.h"

namespace pf
{
	Label::Label(const sf::String& text, sf::Font& font, int size) : 
		pf::GameEntity("label"),

		_Text(text, font, size)
	{

	}

	Label::~Label()
	{

	}

	void Label::setText(const sf::String& text)
	{
		_Text.setString(text);

		sf::FloatRect rect = _Text.getGlobalBounds();

		setSize(rect.width, rect.height);
	}

	void Label::draw(const pf::DrawContext& context)
	{
		_Text.setPosition(getX(), getY());

		context.pRenderWindow->draw(_Text);
	}

	void Label::update(const pf::UpdateContext& context, std::vector<pf::GameEntity*>& collisions)
	{

	}
}