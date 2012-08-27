#include "Obj.h"
#include "HGame.h"
#include <vector>
#include <cmath>

#include "LDraw.h"

Obj::Obj(void)
{
	doesExist = true;

	visible = true;

	imageIndex = 0;
	imageSpeed = 0;

	x = 0;
	y = 0;

	xstart = 0;
	ystart = 0;

	xprev = 0;
	yprev = 0;

	hspeed = 0;
	vspeed = 0;

	gravity = 0;
	gravityDirection = 0;

	friction = 0;

	//sprite = NULL;

	HGame::addObject(this);
}

Obj::Obj(double x, double y)
{
		doesExist = true;

	visible = true;

	imageIndex = 0;
	imageSpeed = 0;

	xprev = 0;
	yprev = 0;

	hspeed = 0;
	vspeed = 0;

	gravity = 0;
	gravityDirection = 0;

	friction = 0;

	//sprite = NULL;

	HGame::addObject(this);
	this->x = x;
	this->y = y;
	xstart = 0;
	ystart = 0;
}


Obj::~Obj(void)
{
	if(sprite != NULL)
	{
		delete sprite;
	}
}

void Obj::destroy()
{
	HGame::removeObject(this);
}

void Obj::onEvent(SDL_Event event)
{

}

void Obj::onStep()
{
	imageIndex += imageSpeed;
	if(imageIndex >= sprite->imageCount)
	{
		while(imageIndex >= sprite->imageCount)
		{
			imageIndex -= sprite->imageCount;
		}
		onAnimationEnd();
	}
	if(!doesExist){return;}

	xprev = x;
	yprev = y;

	x += hspeed;
	y += vspeed;
	hspeed += cos(3.14159265358979323 / 180 * gravityDirection) * gravity;
	vspeed -= sin(3.14159265358979323 / 180 * gravityDirection) * gravity;
	if(abs(hspeed) <= friction){hspeed = 0;}
	else{hspeed -= hspeed/abs(hspeed) * friction;}
	if(abs(vspeed) <= friction){vspeed = 0;}
	else{vspeed -= vspeed/abs(vspeed) * friction;}
}

void Obj::onDraw()
{
	if(sprite->image != NULL)
	{
		LDraw::DrawSprite(sprite, imageIndex, x, y);
	}
}

bool Obj::isColliding(ObjectType type)
{
	//TODO rect only for now
	for each(Obj* o in HGame::getObjectList())
	{
		if(o->objectType == type)
		{
			Spr* spr1 = sprite;
			Spr* spr2 = o->sprite;
			switch(sprite->hitbox)
			{
			case sprite->HITBOX_RECTANGLE:
				double r1x1 = x + spr1->hitboxX1 - spr1->origX;
				double r1y1 = y + spr1->hitboxY1 - spr1->origY;
				double r1x2 = x + spr1->hitboxX2 - spr1->origX;
				double r1y2 = y + spr1->hitboxY2 - spr1->origY;

				double r2x1 = o->x + spr2->hitboxX1 - spr2->origX;
				double r2y1 = o->y + spr2->hitboxY1 - spr2->origY;
				double r2x2 = o->x + spr2->hitboxX2 - spr2->origX;
				double r2y2 = o->y + spr2->hitboxY2 - spr2->origY;

				if(r1x1 <= r2x2 && r1x2 >= r2x1 && r1y1 <= r2y2 && r1y2 >= r2y1)
				{
					return true;
				}
				break;
			}
		}
	}
	return false;
}

bool Obj::isCollidingAt(double x, double y, ObjectType type)
{
	double px = this->x;
	double py = this->y;
	
	this->x = x;
	this->y = y;

	bool res = isColliding(type);

	this->x = px;
	this->y = py;

	return res;
}

bool Obj::isOutsideRoom()
{
	if(isOutsideRoom(RIGHT) || isOutsideRoom(UP) || isOutsideRoom(LEFT) || isOutsideRoom(DOWN))
	{
		return true;
	}
	return false;
}

bool Obj::isOutsideRoom(Sides side)
{
	switch(side)
	{
	case RIGHT:
		if(x - sprite->origX >= HScreen::SCREEN_WIDTH)
		{
			return true;
		}
		return false;
		break;
	case UP:
		if(y - sprite->origY + sprite->image->h <= 0)
		{
			return true;
		}
		return false;
		break;
	case LEFT:
		if(x - sprite->origX + sprite->image->w <= 0)
		{
			return true;
		}
		return false;
		break;
	case DOWN:
		if(y - sprite->origY >= HScreen::SCREEN_HEIGHT)
		{
			return true;
		}
		return false;
		break;
	}
	return false;
}

void Obj::onAnimationEnd()
{
	
}