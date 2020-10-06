#include "Sprite.h"

Sprite::Sprite(std::vector<std::string> framePaths, unsigned int startFrame, bool playAnimation) : Sprite(startFrame, playAnimation)
{
	this->framePaths.swap(framePaths);
}

Sprite::Sprite(unsigned int startFrame, bool playAnimation)
{
	this->setAnimationFrame(startFrame);
	this->setAnimationPlaying(playAnimation);
}

void Sprite::init(GameWindow* window, BasicState* state)
{
	UNUSED(window);
	UNUSED(state);
	
	for(std::string path : this->framePaths)
	{
		this->frames.push_back(Image(path));
	}
}

void Sprite::destroy(GameWindow* window, BasicState* state)
{
	UNUSED(window);
	UNUSED(state);
}

void Sprite::update(GameWindow* window, BasicState* state)
{
	UNUSED(window);
	UNUSED(state);
	
	if(this->isAnimationPlaying())
	{
		this->currentFrame = (this->currentFrame + 1) % this->frames.size();
	}
}

void Sprite::render(GameWindow* window, BasicState* state, Graphics* g)
{
	UNUSED(window);
	UNUSED(state);

	this->attach(&this->frames[this->currentFrame], &Surface::UPPER_LEFT_CORNER);
	this->refresh();
	
	g->draw(this);
}

void Sprite::setAnimationFrame(unsigned int frame)
{
	this->currentFrame = frame;
}

unsigned int Sprite::getAnimationFrame()
{
	return this->currentFrame;
}
		
void Sprite::setAnimationPlaying(bool playAnimation)
{
	this->animationPlaying = playAnimation;
}

bool Sprite::isAnimationPlaying()
{
	return this->animationPlaying;
}
