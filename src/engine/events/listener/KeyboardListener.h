#ifndef __KEYBOARD_LISTENER_H__
#define __KEYBOARD_LISTENER_H__

#include "../../state/GameState.h"

class GameWindow;
class BasicState;

class KeyboardListener
{
	public:
		virtual void onKeyPressed(GameWindow* window, BasicState* state, KeyCode key, KeyModifier modifiers) = 0;
		virtual void onKeyReleased(GameWindow* window, BasicState* state, KeyCode key, KeyModifier modifiers) = 0;
};

#endif
