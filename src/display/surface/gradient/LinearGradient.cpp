#include "LinearGradient.h"
#include <iostream>

LinearGradient::LinearGradient(GradientDirection direction, unsigned int width, unsigned int height, Uint8 from, Uint8 to) : LinearGradient(direction, width, height, Color(from, from, from), Color(to, to, to)) {}

LinearGradient::LinearGradient(GradientDirection direction, unsigned int width, unsigned int height, const Color& from, const Color& to)
: Surface(width, height), direction(direction), from(from), to(to)
{
	unsigned int lineWidth = (direction == VERTICAL) ? width : 1;
	unsigned int lineHeight = (direction == VERTICAL) ? 1 : height;
	
	unsigned int amount = (direction == VERTICAL) ? height : width;
	
	Uint8 redBase = this->from.getRed();
	Uint8 greenBase = this->from.getGreen();
	Uint8 blueBase = this->from.getBlue();
	
	float redStep = (this->to.getRed() - this->from.getRed()) / (float) amount;
	float greenStep = (this->to.getGreen() - this->from.getGreen()) / (float) amount;
	float blueStep = (this->to.getBlue() - this->from.getBlue()) / (float) amount;
	
	for(unsigned int i = 0; i < amount; i++)
	{
		SDL_Rect pos;
		pos.x = (direction == VERTICAL) ? 0 : i;
		pos.y = (direction == VERTICAL) ? i : 0;
		
		Surface* line = new Surface(lineWidth, lineHeight);		
		line->fill(Color(redBase + (redStep * i), greenBase + (greenStep * i), blueBase + (blueStep * i)));
		line->refresh();
		this->attach(line, &pos);
		
		this->gradient.push_back(line);
	}
}

LinearGradient::~LinearGradient()
{
	for(Surface* line : this->gradient)
	{
		delete line;
	}
}
