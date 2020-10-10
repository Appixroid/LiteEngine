#ifndef __SPRITE_H__
#define __SPRITE_H__

#include "../Element.h"
#include <queue>
#include <vector>
#include <string>
#include "../../../display/surface/image/Image.h"

class Sprite : public Element
{
	public:
		Sprite(std::vector<std::string> framePaths, unsigned int startFrame = 0, bool playAnimation = false, bool visible = true);
		Sprite(unsigned int startFrame = 0, bool playAnimation = false, bool visible = true);
		virtual ~Sprite();
		
		virtual void init(GameWindow* window, BasicState* state);
		virtual void destroy(GameWindow* window, BasicState* state);
		
		virtual void update(GameWindow* window, BasicState* state, unsigned int delta);
		virtual void render(GameWindow* window, BasicState* state, Graphics* g);
		
		void setAnimationFrame(unsigned int frame);
		unsigned int getAnimationFrame();
		
		void setAnimationPlaying(bool playAnimation);
		bool isAnimationPlaying();
		
		void enqueueFramePath(std::string& framePath);
		void clearEnqueuedFramePaths();
		
		void setVisibility(bool visibility);
		bool isVisible();
		
	private:
		std::queue<std::string> framePaths;
		std::vector<Image*> frames;
		
		unsigned int currentFrame;
		bool animationPlaying;
		
		bool visible;
};

#endif
