#include "H.h"

#include "LDraw.h"
#include <algorithm>
#include <time.h>

#include "ObjChar.h"

HGame* HGame::instance;

HGame::HGame(void)
{
	instance = this;
	didRoomChange = false;

	isRunning = true;

	new HScreen();
	new HResources();
	new HRoom();

	HRoom::setRoom(HResources::ROOM_INTRO);
	//HRoom::setRoom(HResources::ROOM_3);
	HRoom::buildRoom();

	clock_t t = clock();
	while(isRunning)
	{
		didRoomChange = false;
		while((clock() - t)/static_cast<double>(CLOCKS_PER_SEC) < static_cast<double>(1)/FPS);

		t = clock();
		hEvent();
		hStep();
		hDraw();
		while(destroyQueue.size()>0)
		{
			std::vector<Obj*>* objList = &HGame::getInstance()->objectList;
			std::vector<Obj*>::iterator it = std::find(objList->begin(), objList->end(), destroyQueue.front());
			if(it != objList->end())
			{
				objList->erase(it);
			}

			destroyQueue.pop();
		}
	}
}


HGame::~HGame(void)
{
}

void HGame::hEvent()
{
	SDL_Event event;
	while(SDL_PollEvent(&event))
	{
		if(event.type == SDL_QUIT)
		{
			isRunning = false;
			break;
		}
		if(event.type == SDL_KEYDOWN)
		{
			if(HRoom::getCurrentRoom() == HResources::ROOM_INTRO)
			{
				HRoom::gotoRoom(HResources::ROOM_TRAIL_ENTRANCE);
			}
		}
		if(didRoomChange){break;}
		for each(Obj* o in objectList)
		{
			o->onEvent(event);
		}
	}
}

void HGame::hStep()
{
	for each(Obj* o in objectList)
	{
		if(didRoomChange){break;}
		o->onStep();
	}
}

void HGame::hDraw()
{
	if(HRoom::getCurrentRoom()->backgroundImage != NULL)
	{
		LDraw::DrawImage(HRoom::getCurrentRoom()->backgroundImage, 0, 0);
	}
	else
	{
		LDraw::DrawRect(0, 0, HScreen::SCREEN_WIDTH, HScreen::SCREEN_HEIGHT, HScreen::BACKGROUND_COLOR);
	}
	for each(Obj* o in objectList)
	{
		if(didRoomChange){break;}
		if(o->visible)
		{
			o->onDraw();
		}
	}
	SDL_Flip(HScreen::getScreen());
}

HGame* HGame::getInstance()
{
	return instance;
}

void HGame::addObject(Obj* o)
{
	HGame::getInstance()->objectList.push_back(o);
}

void HGame::removeObject(Obj* o)
{
	HGame::getInstance()->destroyQueue.push(o);
}

std::vector<Obj*> HGame::getObjectList()
{
	return HGame::getInstance()->objectList;
}