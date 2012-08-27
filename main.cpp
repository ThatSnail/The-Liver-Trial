#include "SDL.h"
#include "HGame.h"

int main(int argc, char* argv[])
{
	SDL_Init(SDL_INIT_EVERYTHING);
	new HGame();
	SDL_Quit();

	return 0;
}