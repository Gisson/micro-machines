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
	_angle = fmod((_angle + angle) , 360);
}


Vector3 DynamicObject::getDof() {
	return _dof;
}
double DynamicObject::getAngle() {
	return _angle;
}


//DEPRECATED
/*bool DynamicObject::isOutOfTable(StaticObject* tab) {
	if (_position->getX() > 3)
		setPosition(3, _position->getY(), _position->getZ());
	if (_position->getX() < -3)
		setPosition(-3, _position->getY(), _position->getZ());
	if (_position->getY() < -3)
		setPosition(_position->getX(),-3 , _position->getZ());
	if (_position->getY() > 3)
		setPosition(_position->getX(), 3, _position->getZ());
}*/

