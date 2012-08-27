#include "Obj.h"

class ObjChar : public Obj
{
private:
	static const int WALK_SPEED = 4;

	enum State
	{
		STATE_NORMAL,
		STATE_IRONBOOTS,
		STATE_PROPELLOR,
		STATE_HEADSHOT
	};

	State state;

	void Die();

public:
	Spr* spriteStand;
	Spr* spriteWalk;
	Spr* spriteJump;
	Spr* spriteItemBoots;
	Spr* spriteItemTurret;

	ObjChar();
	ObjChar(double x, double y);
	~ObjChar();

	void onEvent(SDL_Event event);
	void onStep();
	void onDraw();
};