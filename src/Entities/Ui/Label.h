#pragma once

#include <SFML/Graphics.hpp>

#include "../../Game/GameEntity.h"
#include "../../Game/Displayable.h"

namespace pf
{
	class Label : public pf::GameEntity, public pf::Displayable
	{
	public:
		Label(const sf::String& text, sf::Font &font, int size);

		virtual ~Label();

		void setText(const sf::String& text);

		void draw(const pf::DrawContext& context);

		void update(const pf::UpdateContext& context);

	private:
		sf::Text _Text;
	};
}