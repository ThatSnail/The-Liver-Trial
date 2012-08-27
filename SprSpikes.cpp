#include "SprSpikes.h"
#include "HResources.h"

SprSpikes::SprSpikes(void)
{
	image = HResources::SPR_SPIKES;
	setOriginTopLeft();

	imageCount = 3;
	setup();
	setHitboxFull(HITBOX_RECTANGLE);
}


SprSpikes::~SprSpikes(void)
{
}
