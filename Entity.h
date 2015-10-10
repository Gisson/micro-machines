#ifndef __ENTITY_H__
#define __ENTITY_H__
#include "Vector3.h"
#include <GL/glut.h>

class Entity {

public:
	Entity();
	Vector3 getPosition();
	Vector3 setPosition(double x,double y,double z);
	Vector3 setPosition(const Vector3&);


};


#endif
