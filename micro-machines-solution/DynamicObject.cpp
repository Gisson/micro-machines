
#include <iostream>
#include <cmath>
#include "DynamicObject.h"


DynamicObject::DynamicObject()
{
	_speed = 0.0;
	_acelaration = 0.0;
	_position = new Vector3(0.0, 0.0, 0);
	_angle = 0;
	_dof = Vector3();

}

void DynamicObject::update(double time)
{
	
}

void DynamicObject::setSpeed(double speed)
{
	_speed = speed;
}

void DynamicObject::setPosition(double x, double y, double z){
	_position->set(x, y, z);
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

Vector3* DynamicObject::getPosition() {
	return _position;
}

void DynamicObject::acelarate(int amount) {

	setAcelaration(amount);
}

void DynamicObject::breakAcelaration(int amount) {

	setAcelaration(amount);

}


void DynamicObject::turn(double angle) {
	_angle = (int)(_angle + angle) % 360;
	/*if (_angle + angle > 359)
		_angle -= 360;
	else if (_angle + angle < 1)
		_angle += 360;
	_angle += angle;*/
}


Vector3 DynamicObject::getDof() {
	return _dof;
}
double DynamicObject::getAngle() {
	return _angle;
}

