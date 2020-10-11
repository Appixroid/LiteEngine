#include "Image.h"

#define UNUSED(expr) (void)(expr)

Image::Image() : Surface() {}

Image::Image(const std::string& file) : Surface() 
{
	this->loadImage(file);
}

void Image::loadImage(const std::string& file)
{
	SDL_Surface* image = SDL_LoadBMP(file.c_str());
	
	if(image != nullptr)
	{ 
		this->setSurface(image);
	} 
	else
	{
		throw std::invalid_argument(std::string("Cannot load image file(") + file + std::string(") : ") + std::string(SDL_GetError()));
	}
}

void Image::fill(const Color& color)
{
	UNUSED(color);
	throw std::logic_error("Cannot fill image with color");
}

void Image::resize(unsigned int width, unsigned int height, Uint8 colorDefinition)
{
	UNUSED(width);
	UNUSED(height);
	UNUSED(colorDefinition);
	throw std::logic_error("Cannot resize image");
}
