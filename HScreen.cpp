#include "HScreen.h"

HScreen* HScreen::instance;

HScreen::HScreen(void)
{
	instance = this;
	screen = SDL_SetVideoMode(SCREEN_WIDTH, SCREEN_HEIGHT, SCREEN_BPP, SDL_SWSURFACE);
}


HScreen::~HScreen(void)
{
}

HScreen* HScreen::getInstance()
{
	return instance;
}

SDL_Surface* HScreen::getScreen()
{
	return getInstance()->screen;
}