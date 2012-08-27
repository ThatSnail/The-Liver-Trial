#include "ObjWall.h"
#include "SprWall.h"

ObjWall::ObjWall(void)
{
	objectType = OBJ_WALL;
	visible = false;
	sprite = new SprWall();
}

ObjWall::ObjWall(double x, double y)
{
	this->x = x;
	this->y = y;
	xstart = x;
	ystart = y;
	
	objectType = OBJ_WALL;
	visible = false;
	sprite = new SprWall();
}

ObjWall::~ObjWall(void)
{
}
