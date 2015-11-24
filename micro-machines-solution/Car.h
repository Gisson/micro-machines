#ifndef __CAR_H__
#define __CAR_H__
#include "GameObject.h"
#include "DynamicObject.h"
#include "LightSource.h"
#include <math.h>

#define BODY_SIZE 0.2
#define WHEEL_RADIUS 0.03
#define LIGHT_RANGE 0.05
#define LIGHT_NUMBER 8

class Car : public DynamicObject {

private:
	LightSource* _frontLight;


public:
	Car();
	void update(double delta);
	void draw();
	bool checkHit(GameObject*) override;
	bool isCar() override { return true; }
};

#endif