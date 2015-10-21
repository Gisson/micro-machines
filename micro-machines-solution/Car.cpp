#include <iostream>
#include <math.h>
#include "Car.h"

Car::Car() :DynamicObject()
{
		setPosition(0, 0, 3.2);
}

void Car::update(double time) {
	DynamicObject::update(time);
	time = time / 1000;
	if (DynamicObject::getSpeed() > 5)
		setSpeed(5);
	else if (DynamicObject::getSpeed() < -5)
		setSpeed(-5);
	else
	{
		setSpeed(getSpeed() + DynamicObject::getAcelaration()*time);
	}

	setPosition((getPosition()->getX() + cos(getAngle()* PI / 180)* getSpeed() * time + 0.5 * getAcelaration() * time *time), (getPosition()->getY() + sin(getAngle()* PI / 180)* getSpeed() * time + 0.5 * getAcelaration() * time *time), getPosition()->getZ());
	//std::cout << getSpeed() << "aaa" << getPosition()->getX() << std::endl;
}



void Car::draw()
{
	glPushMatrix();
	glLoadIdentity();

	{
		glTranslatef(getPosition()->getX(), getPosition()->getY(), getPosition()->getZ());
		//std::cout << getPosition()->getZ() << std::endl;
		glRotatef(getAngle(), 0, 0, 1);

		//---------------------WHEELS---------------------
		glColor3f(0, 0, 0);

		//--------------------FRONT WHEELS----------------
		glPushMatrix();
		{
			glTranslatef(0.20, 0, 0);

			//---------------------LEFT FRONT-----------------
			glPushMatrix();
			{
				glTranslatef(0, 0.25, 0);
				glRotatef(90, 1, 0, 0);
				glScalef(1, 1, 6);
				glutSolidTorus(0.01, 0.05, 20, 200);
			}glPopMatrix();

			//------------------RIGHT FRONT--------------

			glPushMatrix(); {
				glTranslatef(0, -0.25, 0);
				glRotatef(90, 1, 0, 0);
				glScalef(1, 1, 6);
				glutSolidTorus(0.01, 0.05, 20, 200);
			}glPopMatrix();

		}
		glPopMatrix();

		//-----------------------------BACK WHEELS-----------
		glPushMatrix();
		{
			glTranslatef(-0.25, 0, 0);

			//-----------------------------LEFT BACK---------------
			glPushMatrix();
			{
				glTranslatef(0, 0.25, 0);
				glRotatef(90, 1, 0, 0);
				glScalef(1, 1, 6);
				glutSolidTorus(0.01, 0.05, 20, 200);
			}
			glPopMatrix();

			//-----------------------------RIGHT BACK---------------
			glPushMatrix();
			{
				glTranslatef(0, -0.25, 0);
				glRotatef(90, 1, 0, 0);
				glScalef(1, 1, 6);
				glutSolidTorus(0.01, 0.05, 20, 200);
			}
			glPopMatrix();
		}glPopMatrix();

		//--------------CAR BODY--------------------
		glPushMatrix();
		{

			glTranslatef(0, 0, 0.1);
			glPushMatrix();
			glColor3f(0.9, 0.86, 0.25);
			glTranslatef(0.5, 0, 0);
			glRotatef(90, 0, 1, 0);
			glRotatef(180, 1, 0, 0);
			glutSolidCone(0.2, 0.5, 5, 5);
			glPopMatrix();

			glPushMatrix(); {
				
				glColor3f(0, 1, 0);
				glScalef(1.4, 1, 0.5);
				glutSolidCube(0.4);
			}glPopMatrix();

			//------------ROOFTOP------------------
			glPushMatrix(); {
				glColor3f(1, 0, 1);
				glTranslatef(0, 0, 0.2);
				glScalef(2, 1.2, 0.4);
				glutSolidCube(0.2);
			}glPopMatrix();



		}glPopMatrix();

	}
	glPopMatrix();

}
