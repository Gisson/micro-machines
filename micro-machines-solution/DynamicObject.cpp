#include "DynamicObject.h"


DynamicObject::DynamicObject()
{
	_speed = Vector3(0, 0, 0);
	_acelaration = Vector3(0, 0, 0);
	_position = Vector3(0, 0, 0);
}

void DynamicObject::update(double t)
{
	_position.set(_position.getX()+(1 / 2)*(_acelaration.getX()*t * _acelaration.getX()*t),_position.getY()+ (1 / 2)*((_acelaration.getY() * t * _acelaration.getY()) * t),_position.getZ()+ (1 / 2)*(_acelaration.getZ() * t * _acelaration.getZ() * t));
	
}

void DynamicObject::setAcelaration(const Vector3 &v3)
{
	_acelaration = v3;
}

void DynamicObject::setAcelaration(double x, double y, double z)
{
	DynamicObject::setAcelaration( Vector3(x, y, z));
}


Vector3 DynamicObject::getAcelaration()
{
	return _acelaration;
}

Vector3 DynamicObject::getSpeed()
{
	return _speed;
}
