#pragma once

#include <memory>

#include "Scene.h"

#include "Xml/EntityFactory.h"
#include "Xml/pugixml.hpp"

namespace pf
{
	class DynamicScene : public pf::Scene
	{
	public:
		DynamicScene();

		~DynamicScene();

		void load(std::string filename);

		void onEvent(const sf::Event& event);

	private:
		void loadGravity(pugi::xml_node& gravity);

		void loadEntities(pugi::xml_node& entities);

		void setEntityGravity(pf::GameEntity* entity);

		float _gravityAcceleration;
		float _gravityMaxVelocity;
	};
}