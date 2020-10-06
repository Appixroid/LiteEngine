#ifndef __SURFACE_H__
#define __SURFACE_H__

#include <SDL/SDL.h>
#include "../Color.h"

typedef unsigned int Size;
typedef Uint8 ColorDefinition;

class Surface
{
	public:
		Surface();
		Surface(SDL_Surface* surface);
		Surface(Size width, Size height, Uint8 colorDefinition = Color::BEST_COLOR_DEFINTION);
		
		virtual ~Surface();
		
		virtual void refresh();
		virtual bool attach(Surface* surface, SDL_Rect* position);
		
		virtual void fill(const Color& color);
		virtual void resize(Size width, Size height, ColorDefinition colorDefinition = Color::BEST_COLOR_DEFINTION);

		void setSurface(SDL_Surface* surface);
		SDL_Surface* toSDL() const;
		
		SDL_PixelFormat* getColorFormat() const;
		
		virtual bool isNull() const;
		
		Size getWidth() const;
		Size getHeight() const;
		
		static SDL_Rect UPPER_LEFT_CORNER;
			
	private:
		SDL_Surface* surface;
		
		void free();
};

#endif
