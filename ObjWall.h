#pragma once
#include "objsolid.h"
class ObjWall :
	public ObjSolid
{
public:
	ObjWall(void);
	ObjWall(double x, double y);
	~ObjWall(void);
};

