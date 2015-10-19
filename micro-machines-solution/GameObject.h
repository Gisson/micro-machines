#ifndef __GAMEOBJECT_H__
#define __GAMEOBJECT_H__
#include "Entity.h"

class GameObject :Entity {
public:
	GameObject();
	 virtual void draw()=0;
	 virtual void update(double t)=0;
};



#endif