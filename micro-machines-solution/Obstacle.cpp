#include "Obstacle.h"


Obstacle::Obstacle()
{
}

Obstacle::~Obstacle()
{
}

bool Obstacle::checkHit(GameObject* object)
{
	if (GameObject::checkHit(object) && object->isCar()) {
		((DynamicObject*)object)->setSpeed(0.2);
		setAngle(((DynamicObject*)object)->getAngle());
		setSpeed(0.001);
		return true;
	}
	setSpeed(0);
	return false;
}
