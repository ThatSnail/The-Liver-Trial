#include "SprCharJump.h"

#include "Spr.h"
#include "HResources.h"

SprCharJump::SprCharJump()
{
	image = HResources::SPR_CHAR_JUMP;
	setOriginTopLeft();

	imageCount = 4;
	setup();
	setHitbox(0, 0, 46, 65, HITBOX_RECTANGLE);
}
SprCharJump::~SprCharJump()
{
	SDL_FreeSurface(image);
}