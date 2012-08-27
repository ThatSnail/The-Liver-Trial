#pragma once

#include "SDL.h"

class Spr
{
public:
	enum HitboxType
	{
		HITBOX_PRECISE,
		HITBOX_RECTANGLE,
		HITBOX_ELLIPSE
	};

	HitboxType hitbox;

	SDL_Surface* image;

	double origX;
	double origY;

	double hitboxX1;
	double hitboxY1;
	double hitboxX2;
	double hitboxY2;

	unsigned int imageCount;
	int imageWidth;
	int imageHeight;

	Spr(void);
	~Spr(void);

	void Spr::setOriginCenter();
	void Spr::setOriginTopLeft();

protected:
	void setHitbox(int x1, int y1, int x2, int y2, HitboxType type);
	void setHitboxFull(HitboxType hitbox);
	void setup();
};