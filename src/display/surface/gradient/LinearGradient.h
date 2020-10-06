#ifndef __LINEAR_GRADIENT_H__
#define __LINEAR_GRADIENT_H__

#include "../Surface.h"
#include <vector>

enum GradientDirection
{
	VERTICAL,
	HORIZONTAL
};

class LinearGradient : public Surface
{
	public:
		LinearGradient(GradientDirection direction, unsigned int width, unsigned int height, Uint8 from, Uint8 to);
		LinearGradient(GradientDirection direction, unsigned int width, unsigned int height, const Color& from, const Color& to);
		virtual ~LinearGradient();
		
	private:
		GradientDirection direction;
	
		const Color from;
		const Color to;
		
		std::vector<Surface*> gradient;

};

#endif
