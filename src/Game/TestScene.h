#pragma once

#include <memory>

#include "Scene.h"
#include "Entities/Ui/Label.h"
#include "Entities/Player.h"
#include "Entities/Platform.h"

namespace pf
{
	class TestScene : public pf::Scene
	{
	public:
		TestScene();

		~TestScene();

		void update(const pf::UpdateContext& context);

		void onEvent(const sf::Event& event);

	private:
		std::shared_ptr<sf::Font> _pDebugFont;

		std::shared_ptr<pf::Label> _pDebugLabel;

		std::shared_ptr<pf::Player> _pPlayer;

		std::shared_ptr<pf::Platform> _pPlatform;
	};
}