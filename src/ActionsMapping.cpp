#include "Game/GameAction.h"

namespace pf
{
	ActionsMapping::ActionsMapping(const Gamepad& gamepad) :
		_gamepad(gamepad)
	{
		buildActionsMapping();
	}

	void ActionsMapping::buildActionsMapping()
	{
		_actionsMapping[GameAction::MOVE_UP] = pf::GamepadButton::DPAD_UP;
		_actionsMapping[GameAction::MOVE_RIGHT] = pf::GamepadButton::DPAD_RIGHT;
		_actionsMapping[GameAction::MOVE_DOWN] = pf::GamepadButton::DPAD_DOWN;
		_actionsMapping[GameAction::MOVE_LEFT] = pf::GamepadButton::DPAD_LEFT;
		_actionsMapping[GameAction::JUMP] = pf::GamepadButton::A;
		_actionsMapping[GameAction::RUN] = pf::GamepadButton::X;
	}

	bool ActionsMapping::isActionPressed(unsigned int port, GameAction action) const
	{
		try
		{
			pf::GamepadButton button = _actionsMapping.at(action);

			return _gamepad.isButtonPressed(port, button);
		}
		catch(const std::out_of_range& e)
		{
			return false;
		}
	}

	const pf::Gamepad& ActionsMapping::getGamepad() const
	{
		return _gamepad;
	}
}