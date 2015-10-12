#ifndef __DYNAMICOBJECT_H__
#define __DYNAMICOBJECT_H__

#include "GameObject.h"

class DynamicObject : public GameObject {

private:
	Vector3 _position,_dof;
	double _acelaration , _speed;

public:
	DynamicObject();
	void update(double);
	void setAcelaration(double);
	void setSpeed(double);
	Vector3 getPosition();
	double getAcelaration();
	double getSpeed();
	void acelarate(int);
	void breakAcelaration(int);

};

#endif