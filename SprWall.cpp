#include "SprWall.h"
#include "HResources.h"

SprWall::SprWall(void)
{
	image = HResources::SPR_WALL;
	setOriginTopLeft();

	setup();
	setHitboxFull(HITBOX_RECTANGLE);
}


SprWall::~SprWall(void)
{
}
