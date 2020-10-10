#include "Window.h"
#include <stdexcept>
#include "../Color.h"
#include <chrono>
#include <iostream>

#define MAX(left, right) (left > right ? left : right)
#define MILLIS_PER_SECONDS 1000

Window::Window(const std::string& title, Size width, Size height, WindowMode windowMode, const std::string& icon, unsigned int targetFPS)
: width(width), height(height), colorDefinition(Color::BEST_COLOR_DEFINTION), windowMode(windowMode)
{
	this->setTitle(title);
	this->setIcon(icon);
	this->setTargetFPS(targetFPS);
}

void Window::show()
{
	this->screen.setSurface(SDL_SetVideoMode(this->width, this->height, this->colorDefinition, SDL_HWSURFACE | SDL_DOUBLEBUF | this->windowMode));
	
	if(this->screen.isNull())
	{
		throw std::runtime_error(SDL_GetError());
	}
	
	this->init();
	this->isRunning = true;
	this->loop();
}

void Window::close()
{
	this->stop();
	this->isRunning = false;
}

void Window::setTitle(const std::string& title)
{
	SDL_WM_SetCaption(title.c_str(), NULL);
}

void Window::setIcon(const std::string& icon)
{
	if(icon.size() > 0)
	{
		SDL_WM_SetIcon(SDL_LoadBMP(icon.c_str()), nullptr);
	}
}
	
Size Window::getWidth() const
{
	return this->width;
}

void Window::setWidth(Size width)
{
	this->width = width;
}
		
Size Window::getHeight() const
{
	return this->height;
}

void Window::setHeight(Size height)
{
	this->height = height;
}

void Window::resizeWindow(Size width, Size height)
{
	this->setWidth(width);
	this->setHeight(height);
	this->screen.setSurface(SDL_SetVideoMode(this->width, this->height, this->colorDefinition, SDL_HWSURFACE | SDL_DOUBLEBUF | this->windowMode));
}
		
Uint8 Window::getColorDefinition() const
{
	return this->colorDefinition;
}

void Window::setColorDefinition(Uint8 colorDefinition)
{
	this->colorDefinition = colorDefinition;
}
		
WindowMode Window::getWindowMode() const
{
	return this->windowMode;
}

void Window::setWindowMode(WindowMode windowMode)
{
	this->windowMode = windowMode;
}

void Window::setTargetFPS(unsigned int fps)
{
	this->ticksPerFrame = MILLIS_PER_SECONDS / fps;
}

void Window::setKeyRepeatDelay(unsigned short delay)
{
	SDL_EnableKeyRepeat(delay, delay);
}

void Window::disableCursor(bool disable)
{
	SDL_ShowCursor(disable ? SDL_DISABLE : SDL_ENABLE);
}

void Window::moveCursor(unsigned int x, unsigned int y)
{
	SDL_WarpMouse(x, y);
}

void Window::wait(unsigned int ms)
{
	SDL_Delay(ms);
}

Surface* Window::getScreen()
{
	return &(this->screen);
}

void Window::loop()
{
	Ticks lastTicks = 0;
    SDL_Event event;
 	
    while(this->isRunning)
    {
    	if(SDL_PollEvent(&event))
        {
        	this->manageWindowEvent(event);
        	this->catchEvent(event);
        }
        
    	Ticks newTicks = SDL_GetTicks();
		Ticks ticksPassed = newTicks - lastTicks;
		
		if(ticksPassed > this->ticksPerFrame)
		{
			unsigned int delta = ticksPassed / this->ticksPerFrame;
			
    		this->update(delta);
    		lastTicks = newTicks;
    	}
    	else
    	{
    		this->wait(this->ticksPerFrame - ticksPassed);
    	}
    	
    }
}

void Window::manageWindowEvent(const SDL_Event& event)
{
	if(event.type == SDL_VIDEORESIZE)
	{
		this->resizeWindow(event.resize.w, event.resize.h);
	}
	else if(event.type == SDL_QUIT)
	{
    	this->close();
    }
}
