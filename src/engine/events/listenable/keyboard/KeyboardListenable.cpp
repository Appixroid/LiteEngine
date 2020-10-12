#include "KeyboardListenable.h"
#include <algorithm>

void KeyboardListenable::addKeyboardListener(KeyboardListener* listener)
{
	this->listeners.push_back(listener);
}

void KeyboardListenable::removeKeyboardListener(KeyboardListener* listener)
{
	this->listeners.erase(std::find(this->listeners.begin(), this->listeners.end(), listener));
}

void KeyboardListenable::keyPressedNotifyAll(GameWindow* window, BasicState* state, KeyCode key, KeyModifier modifiers)
{
	for(KeyboardListener* listener : this->listeners)
	{
		listener->onKeyPressed(window, state, key, modifiers);
	}
}

void KeyboardListenable::keyReleasedNotifyAll(GameWindow* window, BasicState* state, KeyCode key, KeyModifier modifiers)
{
	for(KeyboardListener* listener : this->listeners)
	{
		listener->onKeyReleased(window, state, key, modifiers);
	}
}
