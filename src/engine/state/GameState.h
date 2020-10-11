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
		
		virtual void update(GameWindow* window, unsigned int delta) = 0;
		virtual void render(GameWindow* window, Graphics* g) = 0;
		
		virtual void enter(GameWindow* window) = 0;
		virtual void leave(GameWindow* window) = 0;
		
		virtual void onResize(GameWindow* window, Size newWidth, Size newHeight) = 0;
		
		virtual void onKeyPressed(GameWindow* window, KeyCode key, KeyModifier modifiers) = 0;
		virtual void onKeyReleased(GameWindow* window, KeyCode key, KeyModifier modifiers) = 0;
		
		virtual void onMousePressed(GameWindow* window, ButtonCode button, unsigned int x, unsigned int y) = 0;
		virtual void onMouseReleased(GameWindow* window, ButtonCode button, unsigned int x, unsigned int y) = 0;
		virtual void onMouseMoved(GameWindow* window, unsigned int x, unsigned int y, signed int motionX, signed int motionY) = 0;
};


class EmptyState : public GameState
{
	public:
		void init(GameWindow* window) override { UNUSED(window); };
		void destroy(GameWindow* window) override { UNUSED(window); };
		
		void update(GameWindow* window, unsigned int delta) override { UNUSED(window); UNUSED(delta); };
		void render(GameWindow* window, Graphics* g) override { UNUSED(window); UNUSED(g); };
		
		void enter(GameWindow* window) override { UNUSED(window); };
		void leave(GameWindow* window) override { UNUSED(window); };
		
		void onResize(GameWindow* window, Size newWidth, Size newHeight) override { UNUSED(window); UNUSED(newWidth); UNUSED(newHeight); }
		
		void onKeyPressed(GameWindow* window, KeyCode key, KeyModifier modifiers) override { UNUSED(window); UNUSED(key); UNUSED(modifiers); };
		void onKeyReleased(GameWindow* window, KeyCode key, KeyModifier modifiers) override { UNUSED(window); UNUSED(key); UNUSED(modifiers); };
		
		void onMousePressed(GameWindow* window, ButtonCode button, unsigned int x, unsigned int y) override { UNUSED(window); UNUSED(button); UNUSED(x); UNUSED(y); };
		void onMouseReleased(GameWindow* window, ButtonCode button, unsigned int x, unsigned int y) override { UNUSED(window); UNUSED(button); UNUSED(x); UNUSED(y); };
		void onMouseMoved(GameWindow* window, unsigned int x, unsigned int y, signed int motionX, signed int motionY) override { UNUSED(window); UNUSED(x); UNUSED(y); UNUSED(motionX); UNUSED(motionY); };
};
#endif
