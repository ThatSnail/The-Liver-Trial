#include "SprItemBoots.h"
#include "HResources.h"

SprItemBoots::SprItemBoots(void)
{
	image = HResources::SPR_ITEM_BOOTS;
	setOriginTopLeft();

	imageCount = 3;

	setup();
	setHitboxFull(HITBOX_RECTANGLE);
}


SprItemBoots::~SprItemBoots(void)
{
}
