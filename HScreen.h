#pragma once

#include "SDL.h"

class HScreen
{
private:
	static HScreen* instance;

	SDL_Surface* screen;
	static const int SCREEN_BPP = 32;
public:
	static const Uint32 BACKGROUND_COLOR = 0xFFFFFFFF;
	static const int SCREEN_WIDTH = 800;
	static const int SCREEN_HEIGHT = 600;

	HScreen(void);
	~HScreen(void);

	static HScreen* getInstance();
	static SDL_Surface* getScreen();
};

