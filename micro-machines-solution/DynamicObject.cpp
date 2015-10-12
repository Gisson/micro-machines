#include <iostream>
#include "DynamicObject.h"


DynamicObject::DynamicObject()
{
	_speed = 0.0;
	_acelaration = 0.0;
	_position = Vector3(0, 0, 0);
}

void DynamicObject::update(double time)
{
	time = time / 1000;
	setSpeed(getSpeed() + _acelaration*time);
	_position.set(0,0.5*(_position.getY() + getSpeed()) * time, 0);
		std::cout << time << std::endl;
		if(_acelaration>0) _acelaration -= 1;
		else if (_acelaration < 0) _acelaration += 1;
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

void DynamicObject::acelarate(int amount) {
	if (_acelaration > 1000) {
		_acelaration = 1000;
		return;
	}
	_acelaration += amount;
}

void DynamicObject::breakAcelaration(int amount) {
	if (_acelaration < -1000) {
		_acelaration = -1000;
		return;
	}
	_acelaration -= amount;
}
