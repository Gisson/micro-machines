#include <iostream>
#include "DynamicObject.h"


DynamicObject::DynamicObject()
{
	_speed = 0;
	_acelaration = 0;
	_position = Vector3(0, 0, 0);
	_dof = Vector3(0, 1, 0);
}

void DynamicObject::update(double time)
{

	setSpeed(getSpeed() + _acelaration*time);
	_position.set((_position.getX() + getSpeed()) * time,(_position.getY() + getSpeed()) * time,0);

		std::cout << _position.getY() + _acelaration*time << std::endl;
		if(_acelaration>0) _acelaration -= 0.00001;
		else if (_acelaration < 0) _acelaration += 0.00001;
}

void DynamicObject::setSpeed(double speed)
{
	_speed = speed;
}

void DynamicObject::setAcelaration(double d)
{
	_acelaration = d;
}



double DynamicObject::getAcelaration()
{
	return _acelaration;
}

double DynamicObject::getSpeed()
{
	return _speed;
}

Vector3 DynamicObject::getPosition() {
	return _position;
}
