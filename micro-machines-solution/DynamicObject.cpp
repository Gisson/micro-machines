
#include <iostream>
#include <cmath>
#include "DynamicObject.h"

#define PI 3.14159265

DynamicObject::DynamicObject()
{
	_speed = 0.0;
	_acelaration = 0.0;
	_position = Vector3(0, 0, 0);
	_angle = 0;
	_dof = Vector3();
}

void DynamicObject::update(double time)
{
	time = time / 1000;
	if (_speed > 5)
		setSpeed(5);
	else if (_speed < -5)
		setSpeed(-5);
	else
	{
		setSpeed(getSpeed() + _acelaration*time);
	}
	
	_position.set(_position.getX() + cos(_angle* PI / 180)* getSpeed() * time + 0.5 * _acelaration * time *time , _position.getY()  + sin(_angle* PI / 180)* getSpeed() * time + 0.5 * _acelaration * time *time, 0);
	
	std::cout << _speed << "aaa" << _angle << std::endl;
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

