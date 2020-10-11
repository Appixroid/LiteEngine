#ifndef __FIXED_ELEMENT_H__
#define __FIXED_ELEMENT_H__

#include "../Element.h"
#include "../../../display/surface/image/Image.h"
#include "../../gamewindow/GameWindow.h"

#define UNUSED(expr) (void)(expr)

class ImageElement : public Element
{
	public: 
		ImageElement(double x = 0, double y = 0);
		ImageElement(const std::string image, double x = 0, double y = 0);
		
		void loadImage(const std::string& image);
		
		virtual void init(GameWindow* window, BasicState* state) override;
		virtual void destroy(GameWindow* window, BasicState* state) override;
		
		virtual void update(GameWindow* window, BasicState* state, unsigned int delta) override;
		virtual void render(GameWindow* window, BasicState* state, Graphics* g) override;
		
	private:
		const std::string path;
		Image image;
};

#endif
