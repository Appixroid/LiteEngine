#ifndef __GAME_STATE_H__
#define __GAME_STATE_H__

#define UNUSED(expr) (void)(expr)

#include <SDL/SDL.h>
#include "../graphics/Graphics.h"

typedef SDLKey KeyCode;
typedef Uint16 KeyModifier;
typedef Uint8 ButtonCode;
typedef unsigned int Size;

class GameWindow;

class GameState
{
	public:
		virtual ~GameState() {}
		
		virtual void init(GameWindow* window) = 0;
		virtual void destroy(GameWindow* window) = 0;
		
		virtual void update(GameWindow* window) = 0;
		virtual void render(GameWindow* window, Graphics* g) = 0;
		
		virtual void enter(GameWindow* window) = 0;
		virtual void leave(GameWindow* window) = 0;
		
		virtual void onResize(Size newWidth, Size newHeight) = 0;
		
		virtual void onKeyPressed(KeyCode key, KeyModifier modifiers) = 0;
		virtual void onKeyReleased(KeyCode key, KeyModifier modifiers) = 0;
		
		virtual void onMousePressed(ButtonCode button, unsigned int x, unsigned int y) = 0;
		virtual void onMouseReleased(ButtonCode button, unsigned int x, unsigned int y) = 0;
		virtual void onMouseMoved(unsigned int x, unsigned int y, signed int motionX, signed int motionY) = 0;
};


class EmptyState : public GameState
{
	public:
		void init(GameWindow* window) override { UNUSED(window); };
		void destroy(GameWindow* window) override { UNUSED(window); };
		
		void update(GameWindow* window) override { UNUSED(window); };
		void render(GameWindow* window, Graphics* g) override { UNUSED(window); UNUSED(g); };
		
		void enter(GameWindow* window) override { UNUSED(window); };
		void leave(GameWindow* window) override { UNUSED(window); };
		
		void onResize(Size newWidth, Size newHeight) override { UNUSED(newWidth); UNUSED(newHeight); }
		
		void onKeyPressed(KeyCode key, KeyModifier modifiers) override { UNUSED(key); UNUSED(modifiers); };
		void onKeyReleased(KeyCode key, KeyModifier modifiers) override { UNUSED(key); UNUSED(modifiers); };
		
		void onMousePressed(ButtonCode button, unsigned int x, unsigned int y) override { UNUSED(button); UNUSED(x); UNUSED(y); };
		void onMouseReleased(ButtonCode button, unsigned int x, unsigned int y) override { UNUSED(button); UNUSED(x); UNUSED(y); };
		void onMouseMoved(unsigned int x, unsigned int y, signed int motionX, signed int motionY) override { UNUSED(x); UNUSED(y); UNUSED(motionX); UNUSED(motionY); };
};
#endif
