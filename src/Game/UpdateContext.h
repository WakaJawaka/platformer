#pragma once

#include "../Controls/Gamepad.h"
#include "GameAction.h"

namespace pf
{
	class UpdateContext
	{
	public:
		UpdateContext(sf::Int64 elapsedTime, const pf::ActionsMapping& actionsMapping)
			:actionsMapping(actionsMapping)
		{
			this->elapsedTime = elapsedTime;
		}

		sf::Int64 elapsedTime;

		const pf::ActionsMapping& actionsMapping;
	};
}