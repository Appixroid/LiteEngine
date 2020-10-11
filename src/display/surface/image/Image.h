#ifndef __IMAGE_H__
#define __IMAGE_H__

#include "../Surface.h"
#include <SDL/SDL.h>
#include <string>
#include <stdexcept>

class Image : public Surface
{
	public:
		Image();
		Image(const std::string& file);
		
		void loadImage(const std::string& file);
		
		virtual void fill(const Color& color) override;
		virtual void resize(Size width, Size height, ColorDefinition colorDefinition = Color::BEST_COLOR_DEFINTION) override;
};

#endif
