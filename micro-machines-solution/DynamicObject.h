#ifndef __DYNAMICOBJECT_H__
#define __DYNAMICOBJECT_H__

#include "GameObject.h"

class DynamicObject : public GameObject {

private:
	Vector3 _position;
	double _acelaration , _speed;

public:
	DynamicObject();
	void update(double);
	void setAcelaration(double);
	void setSpeed(double);
	Vector3 getPosition();
	double getAcelaration();
	double getSpeed();

};

#endif