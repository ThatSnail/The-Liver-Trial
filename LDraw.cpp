#include "LDraw.h"

void LDraw::DrawRect(double x, double y, double w, double h, Uint32 color)
{
	boxColor(HScreen::getScreen(), static_cast<Sint16>(x), static_cast<Sint16>(y), static_cast<Sint16>(x + w), static_cast<Sint16>(y + h), color);
}
void LDraw::DrawCircle(double x, double y, double r, Uint32 color)
{
	filledCircleColor(HScreen::getScreen(), static_cast<Sint16>(x), static_cast<Sint16>(y), static_cast<Sint16>(r), color);
}
void LDraw::DrawSprite(Spr* spr, double imageIndex, double x, double y)
{
	SDL_Rect srcRect;
	srcRect.x = floor(imageIndex) * spr->imageWidth;
	srcRect.y = 0;
	srcRect.w = spr->imageWidth;
	srcRect.h = spr->imageHeight;

	SDL_Surface* dest = HScreen::getScreen();

	SDL_Rect destRect;
	destRect.x = x;
	destRect.y = y;
	destRect.w = dest->w;
	destRect.h = dest->h;

	SDL_BlitSurface(spr->image, &srcRect, dest, &destRect);
}

void LDraw::DrawImage(SDL_Surface* img, double x, double y)
{
	SDL_Rect srcRect;
	srcRect.x = 0;
	srcRect.y = 0;
	srcRect.w = img->w;
	srcRect.h = img->h;

	SDL_Surface* dest = HScreen::getScreen();

	SDL_Rect destRect;
	destRect.x = x;
	destRect.y = y;
	destRect.w = dest->w;
	destRect.h = dest->h;

	SDL_BlitSurface(img, &srcRect, dest, &destRect);
}