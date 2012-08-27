#include "ObjGlass.h"
#include "SprWall.h"

ObjGlass::ObjGlass(void)
{
	objectType = OBJ_GLASS;
	visible = false;
	sprite = new SprWall();
}

ObjGlass::ObjGlass(double x, double y)
{
	this->x = x;
	this->y = y;
	xstart = x;
	ystart = y;
	
	objectType = OBJ_GLASS;
	visible = false;
	sprite = new SprWall();
}

ObjGlass::~ObjGlass(void)
{
}
