#include "SprDecalPop.h"
#include "HResources.h"

SprDecalPop::SprDecalPop(void)
{
	image = HResources::SPR_DECAL_POP;
	setOriginTopLeft();

	imageCount = 3;

	setup();
	setHitboxFull(HITBOX_RECTANGLE);
}


SprDecalPop::~SprDecalPop(void)
{
}
