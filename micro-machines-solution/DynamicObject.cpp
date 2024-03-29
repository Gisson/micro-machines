#include <iostream>
#include <cmath>
#include "DynamicObject.h"


DynamicObject::DynamicObject():GameObject()
{
	
	_speed = 0.0;
	_acelaration = 0.0;
	_angle = 0;
	_dof = Vector3();
	//_hitBox= new Vector3(_position->getX(),_position->getY(),_position->getZ(),)

}

void DynamicObject::update(double time)
{
	float deltaX, deltaY, deltaZ;
	deltaX = getPosition()->getX();
	deltaY = getPosition()->getY();
	deltaZ = getPosition()->getZ();
	deltaX = (deltaX + cos(getAngle()* PI / 180)* getSpeed() * time + 0.5 * getAcelaration() * time *time);
	deltaY = (deltaY + sin(getAngle()* PI / 180)* getSpeed() * time + 0.5 * getAcelaration() * time *time);
	

	setPosition(deltaX, deltaY, deltaZ);
	getHitBox()->setPosition(deltaX, deltaY, deltaZ);
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

void DynamicObject::setAngle(double angle)
{
	_angle = angle;
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

