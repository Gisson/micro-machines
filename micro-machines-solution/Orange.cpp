#include <iostream>
#include "Orange.h"

Orange::Orange():Obstacle()
{
	double _xPosition, _yPosition , _ZPosition;
	_spawn_time = SPAWN_TIME;
	_xPosition = (((double)rand() / (RAND_MAX)) * 5.8) - 2.8;
	_yPosition = (((double)rand() / (RAND_MAX)) * 5.8) - 2.8;
	_ZPosition = FALL_HEIGHT;
	turn(((double)rand() / (RAND_MAX)) * 360);
	setSpeed(MIN_SPEED + (double)rand() / (RAND_MAX));

	setPosition(_xPosition, _yPosition, _ZPosition);
	getHitBox()->setPosition(_xPosition, _yPosition, _ZPosition);
	//std::cout <<"INITIAL X: " <<_xPosition<<" Y: "<<_yPosition<<" Z: "<<_ZPosition << std::endl;
	getHitBox()->setRadius(ORANGE_RADIUS);
}


void Orange::draw()
{
	glPushMatrix();
	glColor3f(1.0, 0.5, 0.0);
	glTranslatef(getPosition()->getX(), getPosition()->getY(), getPosition()->getZ());
	glRotatef(getAngle(), 0, 0, 1);
	glRotatef(getAngle_z(), 0, 1, 0);
	glutSolidSphere(ORANGE_RADIUS, 10, 10);
	glPopMatrix();

}

void Orange::update(double time)
{
	float deltaX, deltaY, deltaZ;
	if (_spawn_time <= 0)
		_spawn_time = SPAWN_TIME;
		
	deltaX = getPosition()->getX();
	deltaY = getPosition()->getY();
	deltaZ = getPosition()->getZ();
	time = time / 1000;


	deltaX += cos(getAngle()* PI / 180) * time * getSpeed();
	deltaY += sin(getAngle()* PI / 180) * time * getSpeed();
	setAngle_z( (getSpeed() * time / (2 * PI * ORANGE_RADIUS))*360);

	//std::cout << getAngle() << std::endl;
	DynamicObject::update(time);
	if (deltaZ <= -TABLE_SIZE/2) {
		_spawn_time -= time;
		//std::cout << _spawn_time << std::endl;
		if (_spawn_time <= 0) {
			deltaX = (((double)rand() / (RAND_MAX)) * 5.8) - 2.8;
			deltaY = (((double)rand() / (RAND_MAX)) * 5.8) - 2.8;
			deltaZ = 5;
			setSpeed(MIN_SPEED + (double)rand() / (RAND_MAX));
			setPosition(deltaX, deltaY, deltaZ);
			getHitBox()->setPosition(deltaX, deltaY, deltaZ);
		}
	}
	else if (deltaZ > TABLE_SIZE/2 +ORANGE_RADIUS) {
		deltaZ -= FALL_FACTOR;
	}

	if (deltaX > TABLE_SIZE/2) {
		deltaZ -= FALL_FACTOR;
		deltaX = OUT_OF_RANGE;
	}
	if (deltaX < -TABLE_SIZE/2) {
		deltaZ -= FALL_FACTOR;
		deltaX = -OUT_OF_RANGE;
	}
	if (deltaY > TABLE_SIZE/2) {
		deltaZ -= FALL_FACTOR;
		deltaY = OUT_OF_RANGE;

	}
	if (deltaY < -TABLE_SIZE/2) {
		deltaZ -= FALL_FACTOR;
	}
	if(getSpeed()<MAX_SPEED)
		setSpeed(getSpeed() + ORANGE_SPEEDUP_FACTOR);
	//std::cout << deltaZ << std::endl;
	setPosition(deltaX, deltaY, deltaZ);
	getHitBox()->setPosition(deltaX, deltaY, deltaZ);
	//std::cout << "X: " << getHitBox()->getPosition()->getX() << " Y: " << getHitBox()->getPosition()->getY() << " Z: " << getHitBox()->getPosition()->getZ() << std::endl;
}

void Orange::setAngle_z(double angle)
{
	_angle_z = fmod((_angle_z + angle), 360);
}

double Orange::getAngle_z()
{
	return _angle_z;
}

bool Orange::checkHit(GameObject* object)
{
	//std::cout << "xCARRO : " << object->getHitBox()->getPosition()->getX() << " yCARRO: " << object->getHitBox()->getPosition()->getY() << " zCARRO: " << object->getHitBox()->getPosition()->getZ()<< std::endl;

	if (GameObject::checkHit(object)) {
		object->setPosition(0, 0, TABLE_SIZE/2+ORANGE_RADIUS);
		((DynamicObject*)object)->setSpeed(0);
		((DynamicObject*)object)->setAcelaration(0);
	}

	return false;
}
