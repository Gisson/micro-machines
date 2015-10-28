#ifndef __GAMEOBJECT_H__
#define __GAMEOBJECT_H__
#include "Entity.h"
#include "HitBox.h"

#define TABLE_SIZE 6

class GameObject :Entity {
private:
	Vector3 *_position;
	HitBox *_hitBox;

public:
	void setPosition(double, double, double);
	Vector3* getPosition();

	GameObject();
	virtual bool checkHit(GameObject *);
	HitBox* getHitBox();

	virtual void draw()=0;
	virtual void update(double t)=0;
	virtual bool isCar()=0;

};



#endif