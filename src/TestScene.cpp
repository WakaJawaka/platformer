#pragma once

#include "Game/TestScene.h"
#include "Entities/Ui/Label.h"
#include "Platform/Platform.h"

namespace pf
{
	TestScene::TestScene()
		: pf::Scene("testScene", sf::Color(0, 0, 0, 255)),

		_pDebugFont(new sf::Font()),
		_pPlayer(new pf::Player())
	{
		_pDebugFont->loadFromFile("data/fonts/basic.ttf");

		_pDebugLabel = std::shared_ptr<pf::Label>(new pf::Label("", *_pDebugFont, 16));
		_pDebugLabel->setPosition(20.0f, 20.0f);
		addEntity(_pDebugLabel.get()); 

		_pPlayer->setPosition(0, 200.0f);
		addEntity(_pPlayer.get());
	}

	TestScene::~TestScene()
	{

	}

	void TestScene::update(const pf::UpdateContext& context)
	{
		_pDebugLabel->setText(pf::toString<float>(_pPlayer->getPhysicsInfo().getVelocity().x));

		Scene::update(context);
	}

	void TestScene::onEvent(const sf::Event& event)
	{
		
	}
}