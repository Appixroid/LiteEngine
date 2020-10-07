#include "Sprite.h"

#define MAX(left, right) (left > right ? left : right)

Sprite::Sprite(std::vector<std::string> framePaths, unsigned int startFrame, bool playAnimation) : Sprite(startFrame, playAnimation)
{
	for(std::string path : framePaths)
	{
		this->enqueueFramePath(path);
	}
}

Sprite::Sprite(unsigned int startFrame, bool playAnimation)
{
	this->setAnimationFrame(startFrame);
	this->setAnimationPlaying(playAnimation);
}

Sprite::~Sprite()
{
	for(Image* frame : this->frames)
	{
		delete frame;
	}
}

void Sprite::init(GameWindow* window, BasicState* state)
{
	UNUSED(window);
	UNUSED(state);
	
	unsigned int maxWidth = 0;
	unsigned int maxHeight = 0;
	
	while(!this->framePaths.empty())
	{
		Image* frame = new Image(this->framePaths.front());
		
		maxWidth = MAX(maxWidth, frame->getWidth());
		maxHeight = MAX(maxHeight, frame->getHeight());
		
		this->frames.push_back(frame);
		this->framePaths.pop();
	}
	
	this->resize(maxWidth, maxHeight);
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

	this->attach(this->frames[this->currentFrame], &Surface::UPPER_LEFT_CORNER);
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

void Sprite::enqueueFramePath(std::string& framePath)
{
	this->framePaths.push(framePath);
}

void Sprite::clearEnqueuedFramePaths()
{
	while(!this->framePaths.empty())
	{
		this->framePaths.pop();
	}
}
