#ifndef __COLOR_H__
#define __COLOR_H__

#include <SDL/SDL.h>
#include <ostream>

class Color
{
	public:
		Color(const Color& other) : Color(other.r, other.g, other.b) {}
		Color(Uint8 r, Uint8 g, Uint8 b) : r(r), g(g), b(b) {}
		
		Uint32 toInt(SDL_PixelFormat* format) const { return SDL_MapRGB(format, this->r, this->g, this->b); } 
		
		Uint8 getRed() const { return this->r; }
		Uint8 getGreen() const { return this->g; }
		Uint8 getBlue() const { return this->b; }
		
		Color& operator=(const Color& other) { this->r = other.r; this->g = other.g; this->b = other.b; return *this;}
		friend std::ostream& operator<<(std::ostream& stream, const Color& color);
		
		static const Uint8 BEST_COLOR_DEFINTION = 32;
		
	private:
		Uint8 r;
		Uint8 g;
		Uint8 b;
};

inline std::ostream& operator<<(std::ostream& stream, const Color& color)
{ 
	return stream << "rgb(" << +color.r << ", " << +color.g << ", " << +color.b << ")";
}

#endif
