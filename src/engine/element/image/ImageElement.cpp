#include "ImageElement.h"

ImageElement::ImageElement(double x, double y) : Element(x, y), path(), image() {}

ImageElement::ImageElement(const std::string image, double x, double y) : Element(x, y), path(image), image() {}

void ImageElement::loadImage(const std::string& image)
{
	this->image.loadImage(image);
	this->resize(this->image.getWidth(), this->image.getHeight());
	this->attach(&this->image, &Surface::UPPER_LEFT_CORNER);
	this->refresh();
}

void ImageElement::render(GameWindow* window, BasicState* state, Graphics* g)
{
	UNUSED(window);
	UNUSED(state);
	g->draw(this);
}

void ImageElement::init(GameWindow* window, BasicState* state)
{
	UNUSED(window);
	UNUSED(state);
	
	this->loadImage(this->path);
}

void ImageElement::destroy(GameWindow* window, BasicState* state) { UNUSED(window); UNUSED(state); }

void ImageElement::update(GameWindow* window, BasicState* state, unsigned int delta) { UNUSED(window); UNUSED(state); UNUSED(delta); }
