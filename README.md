# LiteEngine
**_It's a work in progress engine !_**

The goal of LiteEngine is to create a simple C++ game engine on top of the SDL. 
This engine is built with two layers.

## Display Layer
The first layer is the lowest level of the engine. It's a binding of the SDL concepts into object.
There are two main concepts for display in SDL.

### Surface
The first concept is the **Surface**. We can fill a **Surface** with a color or attach another **Surface** on it.
The **Image** is a subclass of the **Surface**, it allows to load the content of the **Surface** from a path.

### Window
The second concept is the **Window**. The **Window** is composed of the title and the icon of the resulting OS window.
It's also composed of a root **Surface** representing the drawable space of the window.
The **Window** contains the update loop and the event loop.

## Engine Layer
The second layer is the logic layer of the engine. It's based on the display layer and add the logic.
The same two main concepts are conserved and expanded, and a new concept is added.

### Element
The **Surface** becomes the **Element**. It integrate a position and the _init_, _update_, _render_ methods.
The **Sprite** is an extention of the **Element** and provide an animation system composed by **Image**.

### Game Window
The **Game Window** is the **Window** composed by **State**. It has an active state corresponding to the state to update.
It has some extra util methods.

### State
The **Game State** makes the bridge between the **Game Window** and the **Elements**.
Each state is composed by **Element** and only one state is active at the same time. This system allows to create like "menu state", "game state", "pause state".
