#include "BasicState.h"
#include <algorithm>
#include "../../element/Element.h"

BasicState::~BasicState()
{
	for(Element* element : this->elements)
	{
		delete element;
	}
}

void BasicState::addElement(Element* element)
{
	this->elements.push_back(element);
}

void BasicState::removeElement(Element* element)
{
	this->elements.erase(std::find(this->elements.begin(), this->elements.end(), element));
}


void BasicState::init(GameWindow* window)
{
	for(Element* element : this->elements)
	{
		element->init(window, this);
	}
}

void BasicState::destroy(GameWindow* window)
{
	for(Element* element : this->elements)
	{
		element->destroy(window, this);
	}
}

void BasicState::update(GameWindow* window)
{
	for(Element* element : this->elements)
	{
		element->update(window, this);
	}
}

void BasicState::render(GameWindow* window, Graphics* g)
{
	for(Element* element : this->elements)
	{
		element->render(window, this, g);
	}
}

void BasicState::onKeyPressed(KeyCode key, KeyModifier modifiers)
{
	for(Element* element : this->elements)
	{
		element->onKeyPressed(this, key, modifiers);
	}
}

void BasicState::onKeyReleased(KeyCode key, KeyModifier modifiers)
{
	for(Element* element : this->elements)
	{
		element->onKeyReleased(this, key, modifiers);
	}
}

void BasicState::onMousePressed(ButtonCode button, unsigned int x, unsigned int y)
{
	for(Element* element : this->elements)
	{
		element->onMousePressed(this, button, x, y);
	}
}

void BasicState::onMouseReleased(ButtonCode button, unsigned int x, unsigned int y)
{
	for(Element* element : this->elements)
	{
		element->onMouseReleased(this, button, x, y);
	}
}

void BasicState::onMouseMoved(unsigned int x, unsigned int y, signed int motionX, signed int motionY)
{
	for(Element* element : this->elements)
	{
		element->onMouseMoved(this, x, y, motionX, motionY);
	}
}

