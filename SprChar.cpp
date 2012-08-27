#include "SprChar.h"

#include "Spr.h"
#include "HResources.h"

SprChar::SprChar()
{
	image = HResources::SPR_CHAR;
	setOriginTopLeft();

	imageCount = 3;
	setup();
	setHitbox(0, 0, 46, 65, HITBOX_RECTANGLE);
}
SprChar::~SprChar()
{
	SDL_FreeSurface(image);
}