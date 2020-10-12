#ifndef __GAME_WINDOW_H__
#define __GAME_WINDOW_H__

#include "../../display/window/Window.h"

#include <SDL/SDL.h>
#include <string>
#include <map>
#include "../state/GameState.h"
#include "../element/Element.h"
#include "../math/random/Random.h"
#include "../events/listenable/resize/ResizeListenable.h"

class GameWindow : public Window, public ResizeListenable
{
	public:
		GameWindow(const std::string& title, Size width, Size height, WindowMode windowMode, const std::string& icon = "");
		virtual ~GameWindow();

		void show(const std::string& startingStateName);
		
		void addState(const std::string& name, GameState* state);
		void changeState(const std::string& name);
		
		bool isOnScreen(Element* element);
		
		Random* getRandom();
		
	protected:		
		virtual void init() override;
		virtual void update(unsigned int delta) override;
		virtual void stop() override;
		
		virtual void catchEvent(const SDL_Event& event) override;
		
	private:
		GameState* currentState;
		std::map<std::string, GameState*> states;
		
		EmptyState defaultEmptyState;
		
		Random random;
};

#endif
