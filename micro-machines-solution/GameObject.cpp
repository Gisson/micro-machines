#include <iostream>
#include "GameObject.h"

GameObject::GameObject() {
	_position = new Vector3(0.0, 0.0, 0);
	_hitBox = new HitBox(0,0,0,0);

}

bool GameObject::checkHit(GameObject *object)
{
	Vector3 resultV= (*(getHitBox()->getPosition()) - *(object->getHitBox()->getPosition()));
	double distance = resultV.norm();
	double radSum = pow(getHitBox()->getRadius() + object->getHitBox()->getRadius(),2);
	//std::cout << "xRES : " << resultV.getX()<<" yRES: "<<resultV.getY()<<" zRES: "<<resultV.getZ()<<" NORM: "<<distance <<" RAD SUM: "<<radSum << std::endl;

	if (distance <= radSum) {

		return true;
	}
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

void GameObject::setPosition(Vector3 * pos)
{
	_position = pos;
}

Vector3* GameObject::getPosition() {
	return _position;
}
