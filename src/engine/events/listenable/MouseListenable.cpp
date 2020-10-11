#include "MouseListenable.h"
#include <algorithm>

void MouseListenable::addMouseListener(MouseListener* listener)
{
	this->listeners.push_back(listener);
}

void MouseListenable::removeMouseListener(MouseListener* listener)
{
	this->listeners.erase(std::find(this->listeners.begin(), this->listeners.end(), listener));
}

void MouseListenable::mousePressedNotifyAll(GameWindow* window, BasicState* state, ButtonCode button, unsigned int x, unsigned int y)
{
	for(MouseListener* listener : this->listeners)
	{
		listener->onMousePressed(window, state, button, x, y);
	}
}

void MouseListenable::mouseReleasedNotifyAll(GameWindow* window, BasicState* state, ButtonCode button, unsigned int x, unsigned int y)
{
	for(MouseListener* listener : this->listeners)
	{
		listener->onMouseReleased(window, state, button, x, y);
	}
}

void MouseListenable::mouseMovedNotifyAll(GameWindow* window, BasicState* state, unsigned int x, unsigned int y, signed int motionX, signed int motionY)
{
	for(MouseListener* listener : this->listeners)
	{
		listener->onMouseMoved(window, state, x, y, motionX, motionY);
	}
}
