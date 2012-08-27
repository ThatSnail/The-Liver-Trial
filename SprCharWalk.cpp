#include "SprCharWalk.h"

#include "Spr.h"
#include "HResources.h"

SprCharWalk::SprCharWalk()
{
	image = HResources::SPR_CHAR_WALK;
	setOriginTopLeft();

	imageCount = 4;
	setup();
	setHitbox(0, 0, 46, 65, HITBOX_RECTANGLE);
}
SprCharWalk::~SprCharWalk()
{
	SDL_FreeSurface(image);
}