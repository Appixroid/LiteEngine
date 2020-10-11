#ifndef __BASIC_STATE_H__
#define __BASIC_STATE_H__

#include "../GameState.h"
#include <vector>
#include "../../graphics/Graphics.h"

class Element;

class BasicState : public GameState
{
	public:
		virtual ~BasicState();
		
		void addElement(Element* element);
		void removeElement(Element* element);
		
	
		virtual void init(GameWindow* window) override;
		virtual void destroy(GameWindow* window) override;
		
		virtual void update(GameWindow* window, unsigned int delta) override;
		virtual void render(GameWindow* window, Graphics* g) override;
		
		virtual void onKeyPressed(GameWindow* window, KeyCode key, KeyModifier modifiers) override;
		virtual void onKeyReleased(GameWindow* window, KeyCode key, KeyModifier modifiers) override;
		
		virtual void onMousePressed(GameWindow* window, ButtonCode button, unsigned int x, unsigned int y) override;
		virtual void onMouseReleased(GameWindow* window, ButtonCode button, unsigned int x, unsigned int y) override;
		virtual void onMouseMoved(GameWindow* window, unsigned int x, unsigned int y, signed int motionX, signed int motionY) override;
		
	private:
		std::vector<Element*> elements;
};

#endif
