#ifndef __CAR_H__
#define __CAR_H__
#include "GameObject.h"
#include "DynamicObject.h"

class Car : public DynamicObject {



public:
	Car();
	void draw();
};

#endif