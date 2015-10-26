#pragma once

#include "Vector3.h"


class HitBox {

private:
	Vector3 *_position;
	double _radius;
public:
	HitBox(double x, double y,double z,double radius);
	~HitBox();
	void setPosition(Vector3* newPos);
	void setRadius(double newRad);
	Vector3 getPosition();
	double getRadius();
};
