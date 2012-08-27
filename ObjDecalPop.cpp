#include "ObjDecalPop.h"
#include "SprDecalPop.h"

ObjDecalPop::ObjDecalPop(void)
{
	objectType = OBJ_DECAL_POP;

	sprite = new SprDecalPop();
	imageSpeed = 1;
}

ObjDecalPop::ObjDecalPop(double x, double y)
{
	this->x = x;
	this->y = y;
	xstart = x;
	ystart = y;
	
	objectType = OBJ_DECAL_POP;

	sprite = new SprDecalPop();
	imageSpeed = 1;
}

ObjDecalPop::~ObjDecalPop(void)
{
	
}

void ObjDecalPop::destroy()
{
	Obj::destroy();
}

void ObjDecalPop::onAnimationEnd()
{
	destroy();
}