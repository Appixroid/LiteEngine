#ifndef __KEYBOARD_LISTENABLE_H__
#define __KEYBOARD_LISTENABLE_H__

#include <vector>
#include "../../listener/keyboard/KeyboardListener.h"

class KeyboardListenable
{
	public:
		virtual void addKeyboardListener(KeyboardListener* listener);
		virtual void removeKeyboardListener(KeyboardListener* listener);
		
		virtual void keyPressedNotifyAll(GameWindow* window, BasicState* state, KeyCode key, KeyModifier modifiers);
		virtual void keyReleasedNotifyAll(GameWindow* window, BasicState* state, KeyCode key, KeyModifier modifiers);
		
	private:
		std::vector<KeyboardListener*> listeners;

};

#endif
