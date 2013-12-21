#pragma once

#include <hash_map>

#include "Controls/Gamepad.h"

namespace pf
{
	enum GameAction
	{
		MOVE_UP,
		MOVE_RIGHT,
		MOVE_DOWN,
		MOVE_LEFT,
		JUMP,
		RUN
	};

	class ActionsMapping
	{
	public:
		ActionsMapping(const pf::Gamepad& gamepad);

		bool isActionPressed(unsigned int port, pf::GameAction action) const;

		const pf::Gamepad& getGamepad() const;

	protected:
		virtual void buildActionsMapping();

	private:
		const Gamepad& _gamepad;
		std::hash_map<GameAction, pf::GamepadButton> _actionsMapping;
	};
}