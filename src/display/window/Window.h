#ifndef __WINDOW_H__
#define __WINDOW_H__

#include <string>
#include <SDL/SDL.h>
#include "../surface/Surface.h"

typedef unsigned int WindowMode;
typedef Uint8 ColorDefinition;
typedef Uint32 Ticks;

class Window
{
	public:
		Window(const std::string& title, Size width, Size height, WindowMode windowMode, const std::string& icon = "", unsigned int targetFPS = 60);
		
		void show();
		void close();
		
		void setTitle(const std::string& title);
		void setIcon(const std::string& icon);
				
		Size getWidth() const;
		void setWidth(Size width);
		
		Size getHeight() const;
		void setHeight(Size height);
		
		void resizeWindow(Size width, Size height);
		
		ColorDefinition getColorDefinition() const;
		void setColorDefinition(ColorDefinition colorDefinition);
		
		WindowMode getWindowMode() const;
		void setWindowMode(WindowMode windowMode);
		
		void setTargetFPS(unsigned int fps);
		
		void setKeyRepeatDelay(unsigned short delay);
		void disableCursor(bool disable);
		
		void moveCursor(unsigned int x, unsigned int y);
		
		void wait(unsigned int ms);
		
		Surface* getScreen();

	protected:
		virtual void init() = 0;
		virtual void update(unsigned int delta) = 0;
		virtual void stop() = 0;
		
		virtual void catchEvent(const SDL_Event& event) = 0;
		
	private:
		const std::string title;
	
		Size width;
		Size height;
		
		ColorDefinition colorDefinition;
		WindowMode windowMode;
		const std::string icon;
		
		Surface screen;
		
		bool isRunning;
		
		Ticks ticksPerFrame;
		
		void loop();
		void manageWindowEvent(const SDL_Event& event);
};

#endif
