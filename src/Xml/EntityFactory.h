#pragma once

#include <hash_map>
#include <functional>

#include "Game/GameEntity.h"
#include "pugixml.hpp"
#include "Entities/Player.h"
#include "Entities/Platform.h"

namespace pf
{
	typedef std::function<GameEntity*(pugi::xml_node& node)> EntityMaker;

	static sf::Color makeColor(pugi::xml_node& node)
	{
		sf::Color ret;

		ret.r = node.attribute("r").as_int();
		ret.g = node.attribute("g").as_int();
		ret.b = node.attribute("b").as_int();
		ret.a = node.attribute("a").as_int();

		return ret;
	}

	static pf::Player* makePlayer(pugi::xml_node& node)
	{
		pf::Player* ret = new pf::Player();

		ret->setPosition(node.attribute("x").as_float(), node.attribute("y").as_float());

		return ret;
	}

	static pf::Platform* makePlatform(pugi::xml_node& node)
	{
		pf::Platform* ret = new pf::Platform(node.attribute("width").as_int(), node.attribute("height").as_int(), makeColor(node.child("color")));

		ret->setPosition(node.attribute("x").as_float(), node.attribute("y").as_float());

		return ret;
	}

	class EntityFactory
	{
	public:
		static EntityFactory& getInstance()
		{
			static EntityFactory instance;

			return instance;
		}

		pf::GameEntity* makeEntity(pugi::xml_node& node)
		{
			return _mapping[node.attribute("type").value()](node);
		}

	private:
		EntityFactory()
		{
			buildMapping();
		}

		void buildMapping()
		{
			_mapping["player"] = EntityMaker(makePlayer);
			_mapping["platform"] = EntityMaker(makePlatform);
		}

		EntityFactory(const EntityFactory&);

		EntityFactory& operator=(const EntityFactory&);

		std::hash_map<std::string, EntityMaker> _mapping;
	};
}