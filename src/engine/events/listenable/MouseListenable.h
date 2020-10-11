#ifndef __MOUSE_LISTENABLE_H__
#define __MOUSE_LISTENABLE_H__

#include <vector>
#include "../listener/MouseListener.h"

class MouseListenable
{
	public:
		virtual void addMouseListener(MouseListener* listener);
		virtual void removeMouseListener(MouseListener* listener);
		
		virtual void mousePressedNotifyAll(GameWindow* window, BasicState* state, ButtonCode button, unsigned int x, unsigned int y);
		virtual void mouseReleasedNotifyAll(GameWindow* window, BasicState* state, ButtonCode button, unsigned int x, unsigned int y);
		virtual void mouseMovedNotifyAll(GameWindow* window, BasicState* state, unsigned int x, unsigned int y, signed int motionX, signed int motionY);
		
	private:
		std::vector<MouseListener*> listeners;

};

#endif
