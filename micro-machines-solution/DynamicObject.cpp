#include <iostream>
#include <math.h>
#include "DynamicObject.h"


DynamicObject::DynamicObject()
{
	_speed = 0.0;
	_acelaration = 0.0;
	_position = Vector3(0, 0, 0);
	_angle = 90;
	_dof = Vector3(cos(_angle), sin(_angle), 0);
}

void DynamicObject::update(double time)
{
	time = time / 1000;
	setSpeed(getSpeed() + _acelaration*time);
	
	_position.set(0, _position.getY()  + getSpeed() * time + 0.5 * _acelaration * time *time, 0);
		std::cout << _speed << "aaa" << _acelaration << std::endl;
		if(_acelaration>0 && _speed > 0) _acelaration = -0.5;
		else if (_acelaration < 0 && _speed < 0) {
			_acelaration = 0;
			_speed = 0;
		}
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
	_acelaration = amount;
}

void DynamicObject::breakAcelaration(int amount) {
	if (_acelaration < -1000) {
		_acelaration = -1000;
		return;
	}
	_acelaration = amount;
}


void DynamicObject::turnLeft(double angle) {
	if (_angle+angle > 360) {
		_angle += angle - 360;
		_dof.set(cos(_angle), sin(_angle), 0);
		return;
	}
	_angle += angle;
	_dof.set(cos(_angle), sin(_angle), 0);
}
void DynamicObject::turnRight(double angle) {
	if (_angle - angle < -360) {
		_angle -= -angle +360;
		_dof.set(cos(_angle), sin(_angle), 0);
		return;
	}
	_angle -= angle;
	_dof.set(cos(_angle), sin(_angle), 0);
}

Vector3 DynamicObject::getDof() {
	return _dof;
}
double DynamicObject::getAngle() {
	return _angle;
}

