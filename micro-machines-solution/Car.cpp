#include <iostream>
#include "Car.h"

Car::Car() :DynamicObject()
{
		setPosition(0, 0, 3.2);
		getHitBox()->setPosition(0, 0, 3.2);
		getHitBox()->setRadius(BODY_SIZE*sqrt(3)/2);
}

void Car::update(double time) {
	float deltaX, deltaY, deltaZ;
	deltaX = getPosition()->getX();
	deltaY = getPosition()->getY();
	deltaZ = getPosition()->getZ();
	time = time / 1000;

	DynamicObject::update(time);
	if (DynamicObject::getSpeed() > 5)
		setSpeed(5);
	else if (DynamicObject::getSpeed() < -5)
		setSpeed(-5);
	else
	{
		setSpeed(getSpeed() + DynamicObject::getAcelaration()*time);
	}
	deltaX = (deltaX + cos(getAngle()* PI / 180)* getSpeed() * time + 0.5 * getAcelaration() * time *time);
	deltaY = (deltaY + sin(getAngle()* PI / 180)* getSpeed() * time + 0.5 * getAcelaration() * time *time);
	if (deltaX + BODY_SIZE > 3) {
		deltaX = 3-BODY_SIZE;
	}
	if (deltaX - BODY_SIZE < -3) {
		deltaX = -3+BODY_SIZE;
	}
	if (deltaY + BODY_SIZE > 3) {
		deltaY = 3-BODY_SIZE;
	}
	if (deltaY - BODY_SIZE < -3) {
		deltaY = -3+BODY_SIZE;
	}

	setPosition(deltaX, deltaY, deltaZ);
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
			glTranslatef(BODY_SIZE/2, 0, 0);

			//---------------------LEFT FRONT-----------------
			glPushMatrix();
			{
				glTranslatef(0, BODY_SIZE/2, 0);
				glRotatef(90, 1, 0, 0);
				glScalef(1, 1, 6);
				glutSolidTorus(0.01, WHEEL_RADIUS, 20, 200);
			}glPopMatrix();

			//------------------RIGHT FRONT--------------

			glPushMatrix(); {
				glTranslatef(0, -BODY_SIZE/2, 0);
				glRotatef(90, 1, 0, 0);
				glScalef(1, 1, 6);
				glutSolidTorus(0.01, WHEEL_RADIUS, 20, 200);
			}glPopMatrix();

		}
		glPopMatrix();

		//-----------------------------BACK WHEELS-----------
		glPushMatrix();
		{
			glTranslatef(-BODY_SIZE/2, 0, 0);

			//-----------------------------LEFT BACK---------------
			glPushMatrix();
			{
				glTranslatef(0, BODY_SIZE/2, 0);
				glRotatef(90, 1, 0, 0);
				glScalef(1, 1, 6);
				glutSolidTorus(0.01, WHEEL_RADIUS, 20, 200);
			}
			glPopMatrix();

			//-----------------------------RIGHT BACK---------------
			glPushMatrix();
			{
				glTranslatef(0, -BODY_SIZE/2, 0);
				glRotatef(90, 1, 0, 0);
				glScalef(1, 1, 6);
				glutSolidTorus(0.01, WHEEL_RADIUS, 20, 200);
			}
			glPopMatrix();
		}glPopMatrix();

		//--------------CAR BODY--------------------
		glPushMatrix();
		{

			glTranslatef(0, 0, WHEEL_RADIUS);
			
			//----FRONT LIGHT....OR SOMETHING
			{glPushMatrix();
			glColor3f(0.9, 0.86, 0.25);
			glTranslatef(BODY_SIZE, 0, 0);
			glRotatef(180, 1, 0, 0);
			glRotatef(-90, 0, 1, 0);
			glutSolidCone(0.2, LIGHT_RANGE, 5, 5);
			glPopMatrix();

			}glPushMatrix(); {
				
				glColor3f(0, 1, 0);
				glScalef(1, 1, 0.5);
				glutSolidCube(BODY_SIZE);
			}glPopMatrix();

			/*//------------ROOFTOP------------------
			glPushMatrix(); {
				glColor3f(1, 0, 1);
				glTranslatef(0, 0, 0.2);
				glScalef(1.5, 1.2, 0.4);
				glutSolidCube(0.2);
			}glPopMatrix();*/



		}glPopMatrix();

	}
	glPopMatrix();

}
