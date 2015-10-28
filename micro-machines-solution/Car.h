#ifndef __CAR_H__
#define __CAR_H__
#include "GameObject.h"
#include "DynamicObject.h"
#include <math.h>

#define BODY_SIZE 0.2
#define WHEEL_RADIUS 0.03
#define LIGHT_RANGE 0.05

class Car : public DynamicObject {



public:
	Car();
	void update(double delta);
	void draw();
};

#endif