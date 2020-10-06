#ifndef __BASIC_STATE_H__
#define __BASIC_STATE_H__

#include "../GameState.h"
#include <vector>
#include "../../graphics/Graphics.h"

class Element;

class BasicState : public GameState
{
	public:
		~BasicState();
		
		void addElement(Element* element);
		void removeElement(Element* element);
		
	
		virtual void init(GameWindow* window) override;
		virtual void destroy(GameWindow* window) override;
		
		virtual void update(GameWindow* window) override;
		virtual void render(GameWindow* window, Graphics* g) override;
		
		virtual void onKeyPressed(KeyCode key, KeyModifier modifiers) override;
		virtual void onKeyReleased(KeyCode key, KeyModifier modifiers) override;
		
		virtual void onMousePressed(ButtonCode button, unsigned int x, unsigned int y) override;
		virtual void onMouseReleased(ButtonCode button, unsigned int x, unsigned int y) override;
		virtual void onMouseMoved(unsigned int x, unsigned int y, signed int motionX, signed int motionY) override;
		
	private:
		std::vector<Element*> elements;
};

#endif
