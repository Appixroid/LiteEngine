#ifndef __GRAPHICS_H__
#define __GRAPHICS_H__

#include <map>
#include <vector>

typedef unsigned int Layer;

class Element;
class GameWindow;

class Graphics
{
	public:		
		void draw(Element* element, Layer layer = Graphics::BOTTOM_LAYER);
		void bindOn(GameWindow* window);
		
		static const Layer BOTTOM_LAYER;
		static const Layer TOP_LAYER;
		
	private:
		std::map<Layer, std::vector<Element*>> layers;
		
		std::vector<Layer> getLayers();
};

#endif
