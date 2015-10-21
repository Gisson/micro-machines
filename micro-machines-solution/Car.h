#ifndef __CAR_H__
#define __CAR_H__
#include "GameObject.h"
#include "DynamicObject.h"

#define BODY_SIZE 0.4
#define WHEEL_RADIUS 0.05
#define LIGHT_RANGE 0.5

class Car : public DynamicObject {



public:
	Car();
	void update(double delta);
	void draw();
};

#endif