#include <iostream>
#include "Orange.h"

Orange::Orange()
{
	double _xPosition, _yPosition , _ZPosition;
	_xPosition = (((double)rand() / (RAND_MAX)) * 5.8) - 2.8;
	_yPosition = (((double)rand() / (RAND_MAX)) * 5.8) - 2.8;
	_ZPosition = 5;
	turn(((double)rand() / (RAND_MAX)) * 360);
	setSpeed(0.5 + (double)rand() / (RAND_MAX)* 2);
	setPosition(_xPosition, _yPosition, _ZPosition);
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
	deltaX = getPosition()->getX();
	deltaY = getPosition()->getY();
	deltaZ = getPosition()->getZ();
	time = time / 1000;


	deltaX += cos(getAngle()* PI / 180) * time;
	deltaY += sin(getAngle()* PI / 180) * time;
	setAngle_z( (getSpeed() * time / (2 * PI * ORANGE_RADIUS))*360);

	//std::cout << getAngle() << std::endl;
	DynamicObject::update(time);

	if (deltaZ <= -3) {
		deltaX = (((double)rand() / (RAND_MAX)) * 5.8) - 2.8;
		deltaY = (((double)rand() / (RAND_MAX)) * 5.8) - 2.8;
		deltaZ = 5;
		setSpeed(0.5 + (double)rand() / (RAND_MAX) * 2);
		setPosition(deltaX, deltaY, deltaZ);
	}
	else if (deltaZ > 3.2) {
		deltaZ -= 0.1;
	}

	if (deltaX > 3) {
		deltaZ -=0.1;
	}
	if (deltaX < -3) {
		deltaZ -= 0.1;
	}
	if (deltaY > 3) {
		deltaZ -= 0.1;
	}
	if (deltaY < -3) {
		deltaZ -= 0.1;
	}
	std::cout << deltaZ << std::endl;
	setPosition(deltaX, deltaY, deltaZ);
}

void Orange::setAngle_z(double angle)
{
	_angle_z = fmod((_angle_z + angle), 360);
}

double Orange::getAngle_z()
{
	return _angle_z;
}
