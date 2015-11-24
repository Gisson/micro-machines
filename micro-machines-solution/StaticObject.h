
#ifndef __STATICOBJECT_H__
#define __STATICOBJECT_H__

#include "GameObject.h"

class StaticObject : public GameObject {
public:
	StaticObject();
	~StaticObject();
	void draw();
	void update(double t);
	bool isCar() { return false; }
	bool checkHit(GameObject*) override { return false; };


};

#endif