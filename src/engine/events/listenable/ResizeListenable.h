#ifndef __RESIZE_LISTENABLE_H__
#define __RESIZE_LISTENABLE_H__

#include <vector>
#include "../listener/ResizeListener.h"

class ResizeListenable
{
	public:
		virtual void addResizeListener(ResizeListener* listener);
		virtual void removeResizeListener(ResizeListener* listener);
		
		virtual void resizeNotifyAll(GameWindow* window, Size newWidth, Size newHeight);
		
	private:
		std::vector<ResizeListener*> listeners;

};

#endif
