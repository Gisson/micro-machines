#ifndef __GAMEOBJECT_H__
#define __GAMEOBJECT_H__
#include "Entity.h"

class GameObject :Entity {
public:
	GameObject();
	void draw();
	void update(double t);
};



#endif