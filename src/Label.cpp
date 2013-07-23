#include "Entities/Ui/Label.h"

namespace pf
{
	Label::Label(const sf::String& text, sf::Font& font, int size)
		:pf::GameEntity("label"), 
		 pf::Displayable(0.0f, 0.0f),

		 _Text(text, font, size)
	{

	}

	Label::~Label()
	{

	}

	void Label::setText(const sf::String& text)
	{
		_Text.setString(text);
	}

	void Label::draw(const pf::DrawContext& context)
	{
		_Text.setPosition(getX(), getY());

		context.pRenderWindow->draw(_Text);
	}

	void Label::update(const pf::UpdateContext& context)
	{

	}
}