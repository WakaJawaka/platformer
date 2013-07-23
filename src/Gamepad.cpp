#include "Controls/Gamepad.h"

namespace pf
{
	Gamepad::Gamepad()
		: _analogThreshold(20)
	{
		buildButtonsMapping();
	}

	Gamepad::~Gamepad()
	{

	}

	void Gamepad::buildButtonsMapping()
	{
		_buttonsMapping[GamepadButton::A] = 0;
		_buttonsMapping[GamepadButton::B] = 1;
		_buttonsMapping[GamepadButton::X] = 2;
		_buttonsMapping[GamepadButton::Y] = 3;
		_buttonsMapping[GamepadButton::RIGHT_BUMPER] = 5;
		_buttonsMapping[GamepadButton::LEFT_BUMPER] = 4;
		_buttonsMapping[GamepadButton::START] = 7;
		_buttonsMapping[GamepadButton::SELECT] = 6;
	}

	bool Gamepad::isConnected(unsigned int port) const
	{
		return sf::Joystick::isConnected(port);
	}

	bool Gamepad::isButtonPressed(unsigned int port, GamepadButton button) const
	{
		int povX = int(sf::Joystick::getAxisPosition(port, sf::Joystick::Axis::PovX));
		int povY = int(sf::Joystick::getAxisPosition(port, sf::Joystick::Axis::PovY));
		int analogX = int(sf::Joystick::getAxisPosition(port, sf::Joystick::Axis::X));
		int analogY = int(sf::Joystick::getAxisPosition(port, sf::Joystick::Axis::Y));

		switch(button)
		{
		case GamepadButton::DPAD_LEFT:
			return povY < 0 || analogX < -_analogThreshold;
			break;

		case GamepadButton::DPAD_RIGHT:
			return povY > 0 || analogX > _analogThreshold;
			break;

		case GamepadButton::DPAD_UP:
			return povX > 0 || analogY < -_analogThreshold;
			break;

		case GamepadButton::DPAD_DOWN:
			return povX < 0 || analogY > _analogThreshold;
			break;
		}

		return sf::Joystick::isButtonPressed(port, _buttonsMapping.at(button));
	}
}