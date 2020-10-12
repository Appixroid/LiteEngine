#ifndef __MOUSE_LISTENER_H__
#define __MOUSE_LISTENER_H__

#include "../../../state/GameState.h"

class GameWindow;
class BasicState;

class MouseListener
{
	public:
		virtual void onMousePressed(GameWindow* window, BasicState* state, ButtonCode button, unsigned int x, unsigned int y) = 0;
		virtual void onMouseReleased(GameWindow* window, BasicState* state, ButtonCode button, unsigned int x, unsigned int y) = 0;
		virtual void onMouseMoved(GameWindow* window, BasicState* state, unsigned int x, unsigned int y, signed int motionX, signed int motionY) = 0;
};

#endif
