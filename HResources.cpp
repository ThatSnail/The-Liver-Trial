#include "HResources.h"
#include "SDL_image.h"
#include <fstream>
#include <string>

HResources* HResources::instance;

//sprites
SDL_Surface* HResources::SPR_CHAR;
SDL_Surface* HResources::SPR_CHAR_WALK;
SDL_Surface* HResources::SPR_CHAR_JUMP;
SDL_Surface* HResources::SPR_WALL;
SDL_Surface* HResources::SPR_SPIKES;
SDL_Surface* HResources::SPR_ITEM_TURRET;
SDL_Surface* HResources::SPR_ITEM_BOOTS;
SDL_Surface* HResources::SPR_DECAL_POP;

//bkg
SDL_Surface* HResources::BKG_INTRO;
SDL_Surface* HResources::BKG_TRAIL_ENTRANCE;
SDL_Surface* HResources::BKG_LIVER_ENTRANCE;
SDL_Surface* HResources::BKG_FALL;
SDL_Surface* HResources::BKG_1;
SDL_Surface* HResources::BKG_2;
SDL_Surface* HResources::BKG_3;
SDL_Surface* HResources::BKG_3B;

//rooms
Room* HResources::ROOM_INTRO;
Room* HResources::ROOM_TRAIL_ENTRANCE;
Room* HResources::ROOM_LIVER_ENTRANCE;
Room* HResources::ROOM_FALL;
Room* HResources::ROOM_1;
Room* HResources::ROOM_2;
Room* HResources::ROOM_3;

HResources::HResources(void)
{
	instance = this;

	SPR_CHAR = IMG_Load("assets/gfx/sprChar.bmp");
	SPR_CHAR_WALK = IMG_Load("assets/gfx/sprCharWalk.bmp");
	SPR_CHAR_JUMP = IMG_Load("assets/gfx/sprCharJump.bmp");
	SPR_WALL = IMG_Load("assets/gfx/wall.bmp");
	SPR_SPIKES = IMG_Load("assets/gfx/spikes.png");
	SPR_ITEM_TURRET = IMG_Load("assets/gfx/sprItemTurret.png");
	SPR_ITEM_BOOTS = IMG_Load("assets/gfx/sprItemBoots.png");
	SPR_DECAL_POP = IMG_Load("assets/gfx/sprItemBoots.png");

	BKG_INTRO = IMG_Load("assets/gfx/bkg/roomIntro.png");
	BKG_TRAIL_ENTRANCE = IMG_Load("assets/gfx/bkg/roomTrailEntrance.png");
	BKG_LIVER_ENTRANCE = IMG_Load("assets/gfx/bkg/roomLiverEntrance.png");
	BKG_FALL = IMG_Load("assets/gfx/bkg/roomFall.png");
	BKG_1 = IMG_Load("assets/gfx/bkg/room1.png");
	BKG_2 = IMG_Load("assets/gfx/bkg/room2.png");
	BKG_3 = IMG_Load("assets/gfx/bkg/room3.png");
	BKG_3B = IMG_Load("assets/gfx/bkg/room3b.png");

	ROOM_INTRO = Room_Load("assets/rooms/roomIntro.txt");
	ROOM_INTRO->backgroundImage = BKG_INTRO;

	ROOM_TRAIL_ENTRANCE = Room_Load("assets/rooms/roomTrailEntrance.txt");
	ROOM_TRAIL_ENTRANCE->backgroundImage = BKG_TRAIL_ENTRANCE;

	ROOM_LIVER_ENTRANCE = Room_Load("assets/rooms/roomLiverEntrance.txt");
	ROOM_LIVER_ENTRANCE->backgroundImage = BKG_LIVER_ENTRANCE;

	ROOM_FALL = Room_Load("assets/rooms/roomFall.txt");
	ROOM_FALL->backgroundImage = BKG_FALL;

	ROOM_1 = Room_Load("assets/rooms/room1.txt");
	ROOM_1->backgroundImage = BKG_1;

	ROOM_2 = Room_Load("assets/rooms/room2.txt");
	ROOM_2->backgroundImage = BKG_2;

	ROOM_3 = Room_Load("assets/rooms/room3.txt");
	ROOM_3->backgroundImage = BKG_3;
}

HResources::~HResources(void)
{
	SDL_FreeSurface(SPR_CHAR);
	SDL_FreeSurface(SPR_CHAR_WALK);
	SDL_FreeSurface(SPR_CHAR_JUMP);
	SDL_FreeSurface(SPR_WALL);
	SDL_FreeSurface(SPR_SPIKES);
	SDL_FreeSurface(SPR_ITEM_TURRET);
	SDL_FreeSurface(SPR_ITEM_BOOTS);
	SDL_FreeSurface(SPR_DECAL_POP);

	SDL_FreeSurface(BKG_INTRO);
	SDL_FreeSurface(BKG_TRAIL_ENTRANCE);
	SDL_FreeSurface(BKG_LIVER_ENTRANCE);
	SDL_FreeSurface(BKG_FALL);
	SDL_FreeSurface(BKG_1);
	SDL_FreeSurface(BKG_2);
	SDL_FreeSurface(BKG_3);
	SDL_FreeSurface(BKG_3B);
}

HResources* HResources::getInstance()
{
	return instance;
}

Room* HResources::Room_Load(const char* url)
{
	Room* room = new Room();
	std::ifstream file;
	file.open(url);
	
	std::string line;

	while(file.good())
	{
		std::getline(file, line);
		std::string* parseLine = new std::string[3];
		int ac = 0;

		std::string tempStr = "";
		for(unsigned int i=0;i<line.size();i++)
		{
			char c = line.at(i);
			if(c == ' ')
			{
				parseLine[ac] = tempStr;
				tempStr = "";
				ac++;
			}
			else
			{
				tempStr += c;
			}
		}

		room->addObject(atoi(parseLine[0].c_str()), atof(parseLine[1].c_str()), atof(parseLine[2].c_str()));
	}
	file.close();
	return room;
}