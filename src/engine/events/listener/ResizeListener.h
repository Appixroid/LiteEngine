#ifndef __RESIZE_LISTENER_H__
#define __RESIZE_LISTENER_H__

#include "../../state/GameState.h"

class GameWindow;

class ResizeListener
{
	public:
		virtual void onResize(GameWindow* window, Size newWidth, Size newHeight) = 0;
};

#endif
