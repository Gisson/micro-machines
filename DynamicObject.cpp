#include "DynamicObject.h"


DynamicObject::DynamicObject()
{
	_speed = Vector3(0, 0, 0);
	_acelaration = Vector3(0, 0, 0);
	_position = Vector3(0, 0, 0);
}

void DynamicObject::update(double t)
{
	_position.set(_position.getX+(1 / 2)*(_acelaration.getX*t ^ 2),_position.getY+ (1 / 2)*(_acelaration.getY*t ^ 2),_position.getZ+ (1 / 2)*(_acelaration.getZ*t ^ 2));
	
}

void DynamicObject::setSpeed(const Vector3 &v3)
{
	_acelaration = v3;
}

void DynamicObject::setSpeed(double x, double y, double z)
{
	DynamicObject::setSpeed( Vector3(x, y, z));
}

Vector3 DynamicObject::getSpeed()
{
	return _speed;
}
