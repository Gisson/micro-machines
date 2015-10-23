#include <iostream>
#include "Orange.h"

Orange::Orange()
{
	double _xPosition, _yPosition , _ZPosition;
	_xPosition = (((double)rand() / (RAND_MAX)) * 4.8) - 2.4;
	_yPosition = (((double)rand() / (RAND_MAX)) * 4.8) - 2.4;
	_ZPosition = 3.2;
	setPosition(_xPosition, _yPosition, _ZPosition);
}


void Orange::draw()
{
	glPushMatrix();
	glColor3f(1.0, 0.5, 0.0);
	glTranslatef(getPosition()->getX(), getPosition()->getY(), getPosition()->getZ());
	glRotatef(getAngle(), 0, 1, 0);
	glutSolidSphere(ORANGE_RADIUS, 10, 10);
	glPopMatrix();

}

void Orange::update(double time)
{
	float deltaX, deltaY, deltaZ;
	deltaX = getPosition()->getX();
	deltaY = getPosition()->getY();
	deltaZ = getPosition()->getZ();
	time = time / 1000;

	setSpeed(1);

	deltaX +=  getSpeed() * time ;
	turn( (getSpeed() * time / (2 * PI * ORANGE_RADIUS))*360);

	//std::cout << getAngle() << std::endl;
	DynamicObject::update(time);
	if (deltaZ <= -3) {
		deltaX = -3 + ORANGE_RADIUS;
		deltaZ = 5;
	}
	else if (deltaZ > 3.2) {
		deltaZ -= 0.2;
	}
	if (deltaX + ORANGE_RADIUS > 3) {
		deltaZ -=0.2;
	}
	if (deltaX - ORANGE_RADIUS < -3) {
		deltaZ -= 0.2;
	}
	if (deltaY + ORANGE_RADIUS > 3) {
		deltaZ -= 0.2;
	}
	if (deltaY - ORANGE_RADIUS < -3) {
		deltaZ -= 0.2;
	}
	std::cout << deltaZ << std::endl;
	setPosition(deltaX, deltaY, deltaZ);
}
