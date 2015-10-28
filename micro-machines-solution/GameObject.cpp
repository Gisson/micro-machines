#include <iostream>
#include "GameObject.h"

GameObject::GameObject() {
	_position = new Vector3(0.0, 0.0, 0);
	_hitBox = new HitBox(0,0,0,0);

}

bool GameObject::checkHit(GameObject *object)
{
	int position1 = getHitBox()->getPosition()->norm();
	int position2 = object->getHitBox()->getPosition()->norm();
	position1 = position1 - position2;
	position2 = pow(getHitBox()->getRadius() + object->getHitBox()->getRadius() , 2);
	if (position1 <= position2)
		return true;
	return false;
}

HitBox* GameObject::getHitBox()
{
	return _hitBox;
}

void GameObject::draw()
{ 
}

void GameObject::update(double t)
{
}

void GameObject::setPosition(double x, double y, double z) {
	_position->set(x, y, z);
}

Vector3* GameObject::getPosition() {
	return _position;
}
