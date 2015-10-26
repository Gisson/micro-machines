#include "HitBox.h"

HitBox::HitBox(double x, double y, double z, double radius)
{
	_position = new Vector3(x, y, z);
	_radius = radius;
}

HitBox::~HitBox()
{
}

void HitBox::setPosition(Vector3* newPos)
{
	_position = newPos;
}

void HitBox::setRadius(double newRad)
{
	_radius = newRad;
}

Vector3 HitBox::getPosition()
{
	return Vector3();
}

double HitBox::getRadius()
{
	return _radius;
}
