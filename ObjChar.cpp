#include "ObjChar.h"

#include "LDraw.h"

#include "SprChar.h"
#include "SprCharWalk.h"
#include "SprCharJump.h"
#include "SprItemBoots.h"
#include "SprItemTurret.h"

#include "ObjWall.h"
#include "ObjDecalPop.h"

#include "HGame.h"
#include "HRoom.h"
#include "HResources.h"

#include "SDL.h"

#include <cmath>

ObjChar::ObjChar()
{
	objectType = OBJ_CHAR;

	spriteStand = new SprChar();
	spriteWalk = new SprCharWalk();
	spriteJump = new SprCharJump();

	spriteItemBoots = new SprItemBoots();
	spriteItemTurret = new SprItemTurret();

	sprite = spriteStand;

	imageSpeed = 0;

	gravity = 0.1;
	gravityDirection = 270;
}

ObjChar::ObjChar(double x, double y)
{
	this->x = x;
	this->y = y;
	xstart = x;
	ystart = y;
	
	objectType = OBJ_CHAR;

	spriteStand = new SprChar();
	spriteWalk = new SprCharWalk();
	spriteJump = new SprCharJump();

	spriteItemBoots = new SprItemBoots();
	spriteItemTurret = new SprItemTurret();

	sprite = spriteStand;

	imageSpeed = 0;

	gravity = 0.1;
	gravityDirection = 270;
}

ObjChar::~ObjChar()
{
	delete spriteStand;
	delete spriteWalk;
	delete spriteJump;
	delete spriteItemBoots;
	delete spriteItemTurret;
}

void ObjChar::onEvent(SDL_Event event)
{
}

void ObjChar::onStep()
{
	Uint8* keystate = SDL_GetKeyState(NULL);

	if(keystate[SDLK_w])
	{
		if(isCollidingAt(x, y+1, OBJ_WALL))
		{
			vspeed = -10;
		}
	}
	if(keystate[SDLK_a])
	{
		if(!isCollidingAt(x - WALK_SPEED, y, OBJ_WALL))
		{
			x -= WALK_SPEED;
		}
	}
	if(keystate[SDLK_d])
	{
		if(!isCollidingAt(x + WALK_SPEED, y, OBJ_WALL))
		{
			x += WALK_SPEED;
		}
	}

	if(isCollidingAt(x, y+1, OBJ_WALL))
	{
		gravity = 0;
	}
	else
	{
		gravity = 1;
	}

	//image handling
	if(isCollidingAt(x, y+1, OBJ_WALL) || (isCollidingAt(x, y+1, OBJ_SPIKES) && state == STATE_IRONBOOTS))
	{
		if(keystate[SDLK_a])
		{
			sprite = spriteWalk;
		}
		else if(keystate[SDLK_d])
		{
			sprite = spriteWalk;
		}
		else
		{
			sprite = spriteStand;
		}
		imageSpeed = 1/3;
	}
	else
	{
		sprite = spriteJump;
		imageSpeed = 0;
		if(vspeed < -2)
		{
			imageIndex = 0;
		}
		else if(vspeed < 0)
		{
			imageIndex = 1;
		}
		else if(vspeed < 2)
		{
			imageIndex = 2;
		}
		else
		{
			imageIndex = 3;
		}
	}

	Obj::onStep();

	//collision
	if(isColliding(OBJ_SPIKES))
	{
		if(state == STATE_IRONBOOTS)
		{
			//walk on spikes
			x = xprev;
			y = yprev;
			for(int i = static_cast<int>(abs(vspeed)); i>0 ; i--)
			{
				if(!isCollidingAt(x, y + i * vspeed/abs(vspeed), OBJ_SPIKES))
				{
					y += i;
					break;
				}
			}
			vspeed = 0;
		}
		else
		{
			state = STATE_IRONBOOTS;
			Die();
		}
	}

	if(isColliding(OBJ_GLASS))
	{
		if(state == STATE_IRONBOOTS)
		{
			for each(Obj* o in HGame::getObjectList())
			{
				if(o->objectType == OBJ_GLASS)
				{
					o->destroy();
				}
			}
			HRoom::getCurrentRoom()->backgroundImage = HResources::BKG_3B;
		}
		else
		{
			x = xprev;
			y = yprev;
			for(int i = static_cast<int>(abs(vspeed)); i>0 ; i--)
			{
				if(!isCollidingAt(x, y + i * vspeed/abs(vspeed), OBJ_GLASS))
				{
					y += i;
					break;
				}
			}
			vspeed = 0;
		}
	}

	if(isColliding(OBJ_WALL))
	{
		x = xprev;
		y = yprev;
		for(int i = static_cast<int>(abs(vspeed)); i>0 ; i--)
		{
			if(!isCollidingAt(x, y + i * vspeed/abs(vspeed), OBJ_WALL))
			{
				y += i;
				break;
			}
		}
		vspeed = 0;
	}

	
	if(HRoom::getCurrentRoom() == HResources::ROOM_TRAIL_ENTRANCE)
	{
		if(isOutsideRoom(RIGHT))
		{
			HRoom::gotoRoom(HResources::ROOM_LIVER_ENTRANCE);
		}
	}
	else if(HRoom::getCurrentRoom() == HResources::ROOM_LIVER_ENTRANCE)
	{
		if(isOutsideRoom(DOWN))
		{
			HRoom::gotoRoom(HResources::ROOM_FALL);
		}
	}
	else if(HRoom::getCurrentRoom() == HResources::ROOM_FALL)
	{
		if(isOutsideRoom(DOWN))
		{
			HRoom::gotoRoom(HResources::ROOM_1);
		}
	}
	else if(HRoom::getCurrentRoom() == HResources::ROOM_1)
	{
		if(isOutsideRoom(RIGHT))
		{
			HRoom::gotoRoom(HResources::ROOM_2);
		}
	}
	else if(HRoom::getCurrentRoom() == HResources::ROOM_2)
	{
		if(isOutsideRoom(RIGHT))
		{
			HRoom::gotoRoom(HResources::ROOM_3);
		}
	}
	else if(HRoom::getCurrentRoom() == HResources::ROOM_3)
	{
		if(isOutsideRoom(DOWN))
		{
			HRoom::gotoRoom(HResources::ROOM_TRAIL_ENTRANCE);
		}
	}
}

void ObjChar::onDraw()
{
	Obj::onDraw();
	if(state == STATE_IRONBOOTS)
	{
		LDraw::DrawSprite(spriteItemBoots, 0, x, y+40);
	}
	//if(state == STATE_TURRET)
	//{
	//	LDraw::DrawSprite(spriteItemTurret, static_cast<int>(floor(imageIndex)) % 3, x, y);
	//}
}

void ObjChar::Die()
{
	x = xstart;
	y = ystart;
	xprev = x;
	yprev = y;
	new ObjDecalPop(x, y);
}