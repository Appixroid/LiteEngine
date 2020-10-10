#include "GameWindow.h"

GameWindow::GameWindow(const std::string& title, unsigned int width, unsigned int height, unsigned int windowMode, const std::string& icon) : Window(title, width, height, windowMode, icon)
{
	this->currentState = &this->defaultEmptyState;
}

GameWindow::~GameWindow()
{
	for(std::pair<std::string, GameState*> pair : this->states)
	{
		delete pair.second;
	}
}

void GameWindow::show(const std::string& startingStateName)
{
	this->currentState = this->states.at(startingStateName);
	Window::show();
}
		
void GameWindow::addState(const std::string& name, GameState* state)
{
	this->states.insert(std::pair<std::string, GameState*>(name, state));
}

void GameWindow::changeState(const std::string& name)
{
	this->currentState->leave(this);
	this->currentState = this->states.at(name);
	this->currentState->enter(this);
}

bool GameWindow::isOnScreen(Element* element)
{
	double x = element->getPosition().getX();
	double y = element->getPosition().getY();
	unsigned int width = element->getWidth();
	unsigned int height = element->getHeight();
	
	return (x + width > 0) && (y + height > 0) && (x < this->getWidth()) && (y < this->getHeight());
}

Random* GameWindow::getRandom()
{
	return &this->random;
}

void GameWindow::init()
{
	for(std::pair<std::string, GameState*> pair : this->states)
	{
		pair.second->init(this);
	}
}

void GameWindow::update(unsigned int delta)
{
	this->currentState->update(this, delta);
	
	Graphics g;
	this->currentState->render(this, &g);
	g.bindOn(this);
	
	this->getScreen()->refresh();
}

void GameWindow::stop()
{
	for(std::pair<std::string, GameState*> pair : this->states)
	{
		pair.second->init(this);
	}
}
		
void GameWindow::catchEvent(const SDL_Event& event)
{
	switch(event.type)
	{            
        case SDL_VIDEORESIZE:
        	this->currentState->onResize(event.resize.w, event.resize.h);
        	break;  
        
		case SDL_KEYDOWN:
			this->currentState->onKeyPressed(event.key.keysym.sym, event.key.keysym.mod);
			break;
			
		case SDL_KEYUP:
			this->currentState->onKeyReleased(event.key.keysym.sym, event.key.keysym.mod);
			break;
			
		case SDL_MOUSEBUTTONDOWN:
			this->currentState->onMousePressed(event.button.button, event.button.x, event.button.y);
			break;
			
		case SDL_MOUSEBUTTONUP:
			this->currentState->onMouseReleased(event.button.button, event.button.x, event.button.y);
			break;
			
		case SDL_MOUSEMOTION:
			this->currentState->onMouseMoved(event.motion.x, event.motion.y, event.motion.xrel, event.motion.yrel);
			break;
	}
}
