#ifndef __GAMEOBJECT_H__
#define __GAMEOBJECT_H__
#include "Entity.h"
#include "HitBox.h"

#define TABLE_SIZE 3

class GameObject :Entity {
	

public:
	GameObject();
	 virtual void draw()=0;
	 virtual void update(double t)=0;

};



#endif