#include <iostream>
#include <math.h>
#include "Car.h"

Car::Car() : DynamicObject()
{
}

void Car::update(double delta) {
	DynamicObject::update(delta);

}

void Car::draw(bool isWired)
{
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glPushMatrix();

	glTranslatef(getPosition()->getX(), getPosition()->getY(), getPosition()->getZ());

	glRotatef(getAngle(), 0, 0, 1);

	//---------------------WHEELS---------------------
	glColor3f(0, 0, 0);

	//--------------------FRONT WHEELS----------------
	glPushMatrix();
	glTranslatef(0.20, 0, 0);

	//---------------------LEFT FRONT-----------------
	glPushMatrix();
	glTranslatef(0, 0.25, 0);
	glRotatef(90, 1, 0, 0);
	glScalef(1, 1, 6);
	glutSolidTorus(0.01, 0.05, 20, 200);
	glPopMatrix();

	//------------------RIGHT FRONT--------------

	glPushMatrix();

	glTranslatef(0, -0.25, 0);
	glRotatef(90, 1, 0, 0);
	glScalef(1, 1, 6);
	glutSolidTorus(0.01, 0.05, 20, 200);

	glPopMatrix();

	glPopMatrix();

	//-----------------------------BACK WHEELS-----------
	glPushMatrix();
	glTranslatef(-0.25, 0, 0);


	//-----------------------------LEFT BACK---------------
	glPushMatrix();
	glTranslatef(0, 0.25, 0);
	glRotatef(90, 1, 0, 0);
	glScalef(1, 1, 6);
	glutSolidTorus(0.01, 0.05, 20, 200);
	glPopMatrix();

	//-----------------------------RIGHT BACK---------------
	glPushMatrix();
	glTranslatef(0, -0.25, 0);
	glRotatef(90, 1, 0, 0);
	glScalef(1, 1, 6);
	glutSolidTorus(0.01, 0.05, 20, 200);
	glPopMatrix();
	glPopMatrix();

	//--------------CAR BODY--------------------


	glColor3f(0, 1, 0);

	glScalef(1.2, 0.4, 0.4);
	glutWireCube(0.4);



	glPopMatrix();

}


void Car::draw()
{
	
	glLoadIdentity();
	glPushMatrix();

	glTranslatef(getPosition()->getX(), getPosition()->getY(), getPosition()->getZ());

	glRotatef(getAngle(), 0, 0, 1);

	//---------------------WHEELS---------------------
	glColor3f(0, 0, 0);

	//--------------------FRONT WHEELS----------------
	glPushMatrix();
	glTranslatef(0.20, 0, 0);

	//---------------------LEFT FRONT-----------------
	glPushMatrix();
	glTranslatef(0, 0.25, 0);
	glRotatef(90, 1, 0, 0);
	glScalef(1, 1, 6);
	glutSolidTorus(0.01, 0.05, 20, 200);
	glPopMatrix();

	//------------------RIGHT FRONT--------------

	glPushMatrix();

	glTranslatef(0, -0.25, 0);
	glRotatef(90, 1, 0, 0);
	glScalef(1, 1, 6);
	glutSolidTorus(0.01, 0.05, 20, 200);

	glPopMatrix();

	glPopMatrix();

	//-----------------------------BACK WHEELS-----------
	glPushMatrix();
	glTranslatef(-0.25, 0, 0);


	//-----------------------------LEFT BACK---------------
	glPushMatrix();
	glTranslatef(0, 0.25, 0);
	glRotatef(90, 1, 0, 0);
	glScalef(1, 1, 6);
	glutSolidTorus(0.01, 0.05, 20, 200);
	glPopMatrix();

	//-----------------------------RIGHT BACK---------------
	glPushMatrix();
	glTranslatef(0, -0.25, 0);
	glRotatef(90, 1, 0, 0);
	glScalef(1, 1, 6);
	glutSolidTorus(0.01, 0.05, 20, 200);
	glPopMatrix();
	glPopMatrix();

	//--------------CAR BODY--------------------


	glColor3f(0, 1, 0);

	glScalef(1.4, 1,1);
	glutSolidCube(0.4);

	//------------ROOFTOP------------------
	glColor3f(1, 0, 0);
	glScalef(1.4, 1.2, 1);
	glutSolidCube(0.2);



	glPopMatrix();

}