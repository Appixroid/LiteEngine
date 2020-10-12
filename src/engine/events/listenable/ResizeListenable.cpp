#include "ResizeListenable.h"
#include <algorithm>

void ResizeListenable::addResizeListener(ResizeListener* listener)
{
	this->listeners.push_back(listener);
}

void ResizeListenable::removeResizeListener(ResizeListener* listener)
{
	this->listeners.erase(std::find(this->listeners.begin(), this->listeners.end(), listener));
}

void ResizeListenable::resizeNotifyAll(GameWindow* window, Size newWidth, Size newHeight)
{
	for(ResizeListener* listener : this->listeners)
	{
		listener->onResize(window, newWidth, newHeight);
	}
}
