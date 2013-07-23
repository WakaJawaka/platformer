#pragma once

#include "Scene.h"
#include "DrawContext.h"
#include "DrawContext.h"

namespace pf
{
	class SceneManager
	{
	public:
		SceneManager();

		~SceneManager();

		void setCurrentScene(pf::Scene* scene);

		void draw(const pf::DrawContext& context);

		void update(const pf::UpdateContext& context);

		void onEvent(const sf::Event& event);

	private:
		pf::Scene* _pCurrentScene;
	};
}