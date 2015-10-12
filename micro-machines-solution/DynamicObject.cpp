#include <iostream>
#include "DynamicObject.h"


DynamicObject::DynamicObject()
{
	_speed = 0;
	_acelaration =0;
	_position = Vector3(0, 0, 0);
}

void DynamicObject::update(double time)
{
	_position.set(0, _position.getY() + _acelaration*time*time*(0.5)*0.001, 0);
	//std::cout << "acelaration: "<< std::endl;
	//_position.set(_position.getX()+(1 / 2)*(_acelaration.getX()*t * _acelaration.getX()*t),_position.getY()+ (1 / 2)*((_acelaration.getY() * t * _acelaration.getY()) * t),_position.getZ()+ (1 / 2)*(_acelaration.getZ() * t * _acelaration.getZ() * t));
	//_position.set(0, _position.getY() + (1 / 2)*_acelaration*t*t, 0);
		std::cout << (_position.getY() + _acelaration*time*time*(0.5))<<std::endl;
	if(_position.getY()!=0) std::cout << "positionY: "<<_position.getY() << std::endl;
	
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
