#include "SprItemTurret.h"
#include "HResources.h"

SprItemTurret::SprItemTurret(void)
{
	image = HResources::SPR_ITEM_TURRET;
	setOriginTopLeft();

	setup();
	setHitboxFull(HITBOX_RECTANGLE);
}


SprItemTurret::~SprItemTurret(void)
{
}
