#pragma once
#include "objsolid.h"
class ObjDecalPop :
	public ObjSolid
{
public:
	ObjDecalPop(void);
	ObjDecalPop(double x, double y);
	~ObjDecalPop(void);

	void destroy();
	void onAnimationEnd();
};

