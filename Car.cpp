#include "Car.h"

Car::Car()
{
}

void Car::draw()
{
	//--------------CAR BODY--------------------
	glPushMatrix();
	glLoadIdentity();
	glColor3f(0, 1, 0);
	glTranslatef(1.8, 0, 3);
	glRotatef(90, 0, 0, 1);
	glScalef(2, 1, 1);
	glutSolidCube(0.5);


	glPopMatrix();

}
