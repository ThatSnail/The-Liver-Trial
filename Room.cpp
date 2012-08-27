#include "Room.h"
#include "ObjChar.h"
#include "ObjWall.h"
#include "ObjSpikes.h"
#include "ObjGlass.h"

Room::Room(void)
{
	SDL_Surface* backgroundImage = NULL;
}


Room::~Room(void)
{
}

void Room::addObject(int obj, double x, double y)
{
	RoomObj ro = RoomObj();
	ro.obj = obj;
	ro.x = x;
	ro.y = y;
	roomObjList.push_back(ro);
}

void Room::buildRoom()
{
	for each(RoomObj o in roomObjList)
	{
		makeObj(o.obj, o.x, o.y);
	}
}

Obj* Room::makeObj(int o, double x, double y)
{
	switch(o)
	{
	case 0: return new ObjWall(x, y);
	case 1: return new ObjChar(x, y);
	case 2: return new ObjSpikes(x, y);
	case 3: return new ObjGlass(x, y);
	}
	return NULL;
}