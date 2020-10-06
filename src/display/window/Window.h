#ifndef __WINDOW_H__
#define __WINDOW_H__

#include <string>
#include <SDL/SDL.h>
#include "../surface/Surface.h"

typedef unsigned int WindowMode;
typedef Uint8 ColorDefinition;

class Window
{
	public:
		Window(const std::string& title, Size width, Size height, WindowMode windowMode, const std::string& icon = "");
		
		void show();
		void close();
		
		void setTitle(const std::string& title);
		void setIcon(const std::string& icon);
				
		Size getWidth() const;
		void setWidth(Size width);
		
		Size getHeight() const;
		void setHeight(Size height);
		
		ColorDefinition getColorDefinition() const;
		void setColorDefinition(ColorDefinition colorDefinition);
		
		WindowMode getWindowMode() const;
		void setWindowMode(WindowMode windowMode);
		
		void setKeyRepeatDelay(unsigned short delay);
		void disableCursor(bool disable);
		
		void moveCursor(unsigned int x, unsigned int y);
		
		Surface* getScreen();

	protected:
		virtual void init() = 0;
		virtual void update() = 0;
		virtual void stop() = 0;
		
		virtual void catchEvent(const SDL_Event& event) = 0;
		
	private:
		Size width;
		Size height;
		
		ColorDefinition colorDefinition;
		WindowMode windowMode;
		
		Surface screen;
		
		bool isRunning;
		
		void loop();
};

#endif
