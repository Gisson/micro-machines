#ifndef __DYNAMICOBJECT_H__
#define __DYNAMICOBJECT_H__

#include "GameObject.h"

class DynamicObject : public GameObject {

private:
	Vector3 _speed, _acelaration,_position;

public:
	DynamicObject();
	void update(double t);
	void setAcelaration(const Vector3 &v3);
	void setAcelaration(double x, double y, double z);
	Vector3 getAcelaration();
	Vector3 getSpeed();

};

#endif