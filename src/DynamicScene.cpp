#include "Game/DynamicScene.h"
#include "Game/Logger.h"
#include "Platform/Platform.h"

namespace pf
{
	DynamicScene::DynamicScene()
	{

	}

	DynamicScene::~DynamicScene()
	{

	}

	void DynamicScene::load(std::string filename)
	{
		pugi::xml_document doc;

		if(!doc.load_file(filename.c_str()))
		{
			Logger::getInstance().log("Cannont load scene " + filename);
		}

		pugi::xml_node scene = doc.first_child();
		pugi::xml_node gravity = scene.child("gravity");
		pugi::xml_node entities = scene.child("entities");

		loadGravity(gravity);
		loadEntities(entities);
	}

	void DynamicScene::loadGravity(pugi::xml_node& gravity)
	{
		_gravityAcceleration = pf::strToFloat(gravity.child_value("acceleration"));
		_gravityMaxVelocity = pf::strToFloat(gravity.child_value("max-velocity"));
	}

	void DynamicScene::loadEntities(pugi::xml_node& entities)
	{
		for (pugi::xml_node node = entities.child("entity"); node; node = node.next_sibling("entity"))
		{
			GameEntity* entity = EntityFactory::getInstance().makeEntity(node);

			setEntityGravity(entity);

			addEntity(entity);
		}
	}

	void DynamicScene::setEntityGravity(pf::GameEntity* entity)
	{
		pf::Moveable* moveable = dynamic_cast<pf::Moveable*>(entity);

		if(!moveable)
		{
			return;
		}

		moveable->setGravity(_gravityAcceleration, _gravityMaxVelocity);
	}

	void DynamicScene::onEvent(const sf::Event& e)
	{

	}
}