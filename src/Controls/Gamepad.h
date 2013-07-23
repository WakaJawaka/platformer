#pragma once

#include <hash_map>
#include <SFML/Window/Joystick.hpp>

namespace pf
{
	enum GamepadButton
	{
		A,
		B,
		X,
		Y,
		DPAD_UP,
		DPAD_RIGHT,
		DPAD_DOWN,
		DPAD_LEFT,
		RIGHT_BUMPER,
		LEFT_BUMPER,
		START,
		SELECT
	};

	class Gamepad
	{
	public:
		Gamepad();

		virtual ~Gamepad();

		bool isConnected(unsigned int port) const;
		bool isButtonPressed(unsigned int port, pf::GamepadButton button) const;

	protected:
		virtual void buildButtonsMapping();

	private:
		std::hash_map<pf::GamepadButton, int> _buttonsMapping;

		int _analogThreshold;
	};
}