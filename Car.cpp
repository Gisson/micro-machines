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

	//---------------------WHEELS---------------------
	glColor3f(0, 0, 0);
	
	//--------------------FRONT WHEELS----------------
	glPushMatrix();
	glTranslatef(0.25, 0, 0);

	//---------------------LEFT FRONT-----------------
	glPushMatrix();
	glTranslatef(0, 0.25, 0);
	glRotatef(90, 1, 0, 0);
	glScalef(1, 1, 4);
	glutSolidTorus(0.01, 0.05, 20, 200);
	glPopMatrix();

	//------------------RIGHT FRONT--------------

	glPushMatrix();

	glTranslatef(0, -0.25, 0);
	glRotatef(90, 1, 0, 0);
	glScalef(1, 1, 4);
	glutSolidTorus(0.01, 0.05, 20, 200);

	glPopMatrix();

	glPopMatrix();

	glPopMatrix();

}
