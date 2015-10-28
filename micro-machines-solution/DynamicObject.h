#ifndef __DYNAMICOBJECT_H__
#define __DYNAMICOBJECT_H__

#include "GameObject.h"
#include "StaticObject.h"
#include "HitBox.h"

#define PI 3.14159265

class DynamicObject : public GameObject {

private:
	Vector3 _dof;
	double _acelaration , _speed,_angle;
	bool _is_acelarating;
	

public:
	DynamicObject();
	void update(double);
	void setAcelaration(double);
	void setSpeed(double);
	double getAcelaration();
	double getSpeed();
	void acelarate(int);
	void breakAcelaration(int);
	void turn(double);
	Vector3 getDof();
	double getAngle();
	void setAngle(double);
	virtual bool isCar() { return false; }

};

#endif