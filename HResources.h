#pragma once

#include "SDL.h"
#include "Room.h"

class HResources
{
private:
	static HResources* instance;

public:
	static SDL_Surface* SPR_CHAR;
	static SDL_Surface* SPR_CHAR_WALK;
	static SDL_Surface* SPR_CHAR_JUMP;
	static SDL_Surface* SPR_WALL;
	static SDL_Surface* SPR_SPIKES;
	static SDL_Surface* SPR_ITEM_TURRET;
	static SDL_Surface* SPR_ITEM_BOOTS;
	static SDL_Surface* SPR_DECAL_POP;

	static SDL_Surface* HResources::BKG_INTRO;
	static SDL_Surface* HResources::BKG_TRAIL_ENTRANCE;
	static SDL_Surface* HResources::BKG_LIVER_ENTRANCE;
	static SDL_Surface* HResources::BKG_FALL;
	static SDL_Surface* HResources::BKG_1;
	static SDL_Surface* HResources::BKG_2;
	static SDL_Surface* HResources::BKG_3;
	static SDL_Surface* HResources::BKG_3B;

	static Room* ROOM_INTRO;
	static Room* ROOM_TRAIL_ENTRANCE;
	static Room* ROOM_LIVER_ENTRANCE;
	static Room* ROOM_FALL;
	static Room* ROOM_1;
	static Room* ROOM_2;
	static Room* ROOM_3;

	HResources(void);
	~HResources(void);

	static HResources* getInstance();

	static Room* Room_Load(const char* url);
};

