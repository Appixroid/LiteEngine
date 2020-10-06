#include "Graphics.h"

#include <climits>
#include "../element/Element.h"
#include "../gamewindow/GameWindow.h"
		
const Layer Graphics::BOTTOM_LAYER = 0;
const Layer Graphics::TOP_LAYER = UINT_MAX;
		
void Graphics::draw(Element* element, Layer layer)
{
	this->layers[layer].push_back(element);
}

void Graphics::bindOn(GameWindow* window)
{
	Surface* screen = window->getScreen();
	
	for(Layer layer : this->getLayers())
	{
		for(Element* element : this->layers[layer])
		{
			if(window->isOnScreen(element))
			{
				SDL_Rect pos = element->getPosition().toSDL();
				screen->attach(element, &pos);
			}
		}
	}
}

std::vector<Layer> Graphics::getLayers()
{
	std::vector<Layer> layersLevel;
	
	for(std::map<Layer, std::vector<Element*>>::iterator it = this->layers.begin(); it != this->layers.end(); ++it)
	{
		layersLevel.push_back(it->first);
	}
	
	return layersLevel;
}
