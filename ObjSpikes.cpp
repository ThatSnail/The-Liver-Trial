#include "ObjSpikes.h"
#include "SprSpikes.h"

ObjSpikes::ObjSpikes(void)
{
	objectType = OBJ_SPIKES;

	sprite = new SprSpikes();
}

ObjSpikes::ObjSpikes(double x, double y)
{
	this->x = x;
	this->y = y;
	xstart = x;
	ystart = y;
	
	objectType = OBJ_SPIKES;

	sprite = new SprSpikes();
}

ObjSpikes::~ObjSpikes(void)
{
}
