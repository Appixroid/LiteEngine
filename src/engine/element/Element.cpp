#include "Element.h"

Element::Element(double x, double y) : Surface(), position(x, y) {}

void Element::setPosition(double x, double y)
{
	this->position.set(x, y);
}

void Element::setPosition(const Vector& position)
{
	this->position.set(position);
}

void Element::move(double motionX, double motionY)
{
	const double x = this->position.getX();
	const double y = this->position.getY();
	
	this->position.set(x + motionX, y  + motionY);
}

const Vector& Element::getPosition() const
{
	return this->position;
}
