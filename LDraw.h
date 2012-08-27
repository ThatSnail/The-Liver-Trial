#pragma once

#include "HScreen.h"
#include "SDL.h"
#include "SDL_gfxPrimitives.h"
#include "Spr.h"

class LDraw
{
public:
	static void DrawRect(double x, double y, double w, double h, Uint32 color);
	static void DrawCircle(double x, double y, double r, Uint32 color);
	static void DrawSprite(Spr* spr, double imageIndex, double x, double y);
	static void DrawImage(SDL_Surface* img, double x, double y);
};