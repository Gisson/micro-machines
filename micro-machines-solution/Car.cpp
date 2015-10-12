#include "Car.h"

Car::Car()
{
}

void Car::draw()
{
	glLoadIdentity();
	glPushMatrix();
	glTranslatef(1.8, 0, 3);
	glRotatef(90, 0, 0, 1);

	//---------------------WHEELS---------------------
	glColor3f(0, 0, 0);

	//--------------------FRONT WHEELS----------------
	glPushMatrix();
	glTranslatef(0.25, 0, 0);

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

	glScalef(2, 1, 1);
	glutSolidCube(0.5);



	glPopMatrix();

}
