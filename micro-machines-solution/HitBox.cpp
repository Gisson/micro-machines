#include "HitBox.h"

HitBox::HitBox(double x, double y, double z, double radius)
{
	_position = new Vector3(x, y, z);
	_radius = radius;
}

HitBox::~HitBox()
{
}

void HitBox::setPosition(double x, double y, double z)
{
	_position = new Vector3(x, y, z);
}

void HitBox::setRadius(double newRad)
{
	_radius = newRad;
}

Vector3* HitBox::getPosition()
{
	return _position;
}

double HitBox::getRadius()
{
	return _radius;
}
