#pragma once

#include "SDL.h"
#include "Spr.h"

class Obj
{
protected:
	enum ObjectType
	{
		OBJ_CHAR,
		OBJ_SOLID,
		OBJ_WALL,
		OBJ_SPIKES,
		OBJ_DECAL_POP,
		OBJ_GLASS
	};

	enum Sides
	{
		RIGHT,
		UP,
		LEFT,
		DOWN
	};

public:
	bool doesExist;

	bool visible;

	ObjectType objectType;

	double imageIndex;
	double imageSpeed;

	double x;
	double y;

	double xstart;
	double ystart;

	double xprev;
	double yprev;

	double hspeed;
	double vspeed;

	double gravity;
	double gravityDirection;

	double friction;

	Spr* sprite;

	Obj(void);
	Obj(double x, double y);
	~Obj(void);

	virtual void destroy();

	virtual void onEvent(SDL_Event event);
	virtual void onStep();
	virtual void onDraw();

	bool isColliding(ObjectType type);
	bool isCollidingAt(double x, double y, ObjectType type);

	bool isOutsideRoom();
	bool isOutsideRoom(Sides side);

	virtual void onAnimationEnd();

	template <class DstType, class SrcType>
	bool IsType(const SrcType* src);

};