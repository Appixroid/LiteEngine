#ifndef __SPRITE_H__
#define __SPRITE_H__

#include "../Element.h"
#include <vector>
#include <string>
#include "../../../display/surface/image/Image.h"

class Sprite : public Element
{
	public:
		Sprite(std::vector<std::string> framePaths, unsigned int startFrame = 0, bool playAnimation = false);
		Sprite(unsigned int startFrame = 0, bool playAnimation = false);
		
		virtual void init(GameWindow* window, BasicState* state);
		virtual void destroy(GameWindow* window, BasicState* state);
		
		virtual void update(GameWindow* window, BasicState* state);
		virtual void render(GameWindow* window, BasicState* state, Graphics* g);
		
		void setAnimationFrame(unsigned int frame);
		unsigned int getAnimationFrame();
		
		void setAnimationPlaying(bool playAnimation);
		bool isAnimationPlaying();
		
	private:
		std::vector<std::string> framePaths;
		std::vector<Image> frames;
		
		unsigned int currentFrame;
		bool animationPlaying;
};

#endif
