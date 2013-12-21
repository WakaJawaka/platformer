#pragma once

#include <vector>

#include "Controls/Gamepad.h"
#include "GameAction.h"

namespace pf
{
	class UpdateContext
	{
	public:
		UpdateContext(sf::Int64 elapsedTime, const pf::ActionsMapping& actionsMapping) :
			elapsedTime(elapsedTime),
			actionsMapping(actionsMapping)
		{

		}

		sf::Int64 elapsedTime;

		const pf::ActionsMapping& actionsMapping;
	};
}