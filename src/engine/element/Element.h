#ifndef __ELEMENT_H__
#define __ELEMENT_H__

#include "../../display/surface/Surface.h"

#include <SDL/SDL.h>
#include <string>
#include "../math/vector/Vector.h"
#include "../graphics/Graphics.h"
#include "../state/basic/BasicState.h"

class GameWindow;

class Element : public Surface
{
	public:
		Element(double x = 0, double y = 0);
		
		void setPosition(double x, double y);
		void setPosition(const Vector& position);
		void move(double motionX, double motionY);
		const Vector& getPosition() const;
		
		virtual void init(GameWindow* window, BasicState* state) = 0;
		virtual void destroy(GameWindow* window, BasicState* state) = 0;
		
		virtual void update(GameWindow* window, BasicState* state, unsigned int delta) = 0;
		virtual void render(GameWindow* window, BasicState* state, Graphics* g) = 0;
		
	private:
		Vector position;
};

#endif
