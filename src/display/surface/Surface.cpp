#include "Surface.h"

SDL_Rect Surface::UPPER_LEFT_CORNER = {0, 0, 0, 0};

Surface::Surface() : surface(nullptr) {}

Surface::Surface(SDL_Surface* surface) : Surface()
{
	this->setSurface(surface);
}

Surface::Surface(Size width, Size height, Uint8 colorDefinition) : Surface()
{
	this->resize(width, height, colorDefinition);
}

Surface::~Surface()
{
	this->free();
}

void Surface::refresh()
{
	SDL_Flip(this->toSDL());
}

bool Surface::attach(Surface* surface, SDL_Rect* position)
{
	return SDL_BlitSurface(surface->toSDL(), NULL, this->toSDL(), position) == 0;
}

void Surface::fill(const Color& color)
{
	SDL_FillRect(this->toSDL(), NULL, color.toInt(this->getColorFormat()));
}

void Surface::resize(Size width, Size height, Uint8 colorDefinition)
{
	this->setSurface(SDL_CreateRGBSurface(SDL_HWSURFACE, width, height, colorDefinition, 0, 0, 0, 0));
}

void Surface::setTransparency(Uint8 level)
{
	SDL_SetAlpha(this->toSDL(), SDL_SRCALPHA, level);
}

void Surface::setColorToAlpha(const Color& color)
{
	SDL_SetColorKey(this->toSDL(), SDL_SRCCOLORKEY, color.toInt(this->getColorFormat()));
}

void Surface::setSurface(SDL_Surface* surface)
{
	this->free();
	this->surface = surface;
}

SDL_Surface* Surface::toSDL() const
{
	return this->surface;
}

SDL_PixelFormat* Surface::getColorFormat() const
{
	return this->toSDL()->format;
}

bool Surface::isNull() const
{
	return this->toSDL() == nullptr;
}

Size Surface::getWidth() const
{
	return this->toSDL()->w;
}

Size Surface::getHeight() const
{
	return this->toSDL()->h;
}

void Surface::free()
{
	if(!this->isNull())
	{
		SDL_FreeSurface(this->toSDL());
	}
}
