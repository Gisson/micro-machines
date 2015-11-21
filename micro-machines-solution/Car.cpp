#include <iostream>
#include "Car.h"

Car::Car() :DynamicObject()
{
		setPosition(0, 0, (TABLE_SIZE/2)+WHEEL_RADIUS);
		getHitBox()->setPosition(0, 0, TABLE_SIZE / 2 + WHEEL_RADIUS);
		getHitBox()->setRadius(BODY_SIZE);
}

void Car::update(double time) {

	time = time / 1000;
	double deltaX = (getPosition()->getX() + cos(getAngle()* PI / 180)* getSpeed() * time + 0.5 * getAcelaration() * time *time);
	double deltaY = (getPosition()->getY() + sin(getAngle()* PI / 180)* getSpeed() * time + 0.5 * getAcelaration() * time *time);
	double deltaZ = getPosition()->getZ();
	setSpeed(getSpeed() + getAcelaration()*time);
	if (deltaX + BODY_SIZE > TABLE_SIZE/2 || deltaX - BODY_SIZE < -TABLE_SIZE/2 || deltaY + BODY_SIZE > TABLE_SIZE/2 || deltaY - BODY_SIZE < -TABLE_SIZE/2) {
		if (deltaX + BODY_SIZE > TABLE_SIZE/2) {
			deltaX = TABLE_SIZE/2 - BODY_SIZE;
		}
		if (deltaX - BODY_SIZE < -TABLE_SIZE/2) {
			deltaX = -TABLE_SIZE/2 + BODY_SIZE;
		}
		if (deltaY + BODY_SIZE > TABLE_SIZE/2) {
			deltaY = TABLE_SIZE/2 - BODY_SIZE;
		}
		if (deltaY - BODY_SIZE < -TABLE_SIZE/2) {
			deltaY = -TABLE_SIZE/2 + BODY_SIZE;
		}
		setPosition(deltaX, deltaY, deltaZ);
		getHitBox()->setPosition(deltaX, deltaY, deltaZ);
	}
	else
		DynamicObject::update(time);
	if (DynamicObject::getSpeed() > CAR_MAX_SPEED)
		setSpeed(CAR_MAX_SPEED);
	else if (DynamicObject::getSpeed() < -CAR_MAX_SPEED)
		setSpeed(-CAR_MAX_SPEED);
	else
	{
		setSpeed(getSpeed() + DynamicObject::getAcelaration()*time);
	}




}



void Car::draw()
{
	glPushMatrix();
	

	{
		glTranslatef(getPosition()->getX(), getPosition()->getY(), getPosition()->getZ());
		//std::cout << getPosition()->getZ() << std::endl;
		glRotatef(getAngle(), 0, 0, 1);

		//---------------------WHEELS---------------------  TODO: POLYGONIZAR AS RODAS
		{
			/* comment the material*/
			GLfloat amb[] = { 0.05375f,0.05f,0.06625f,1.0f };
			GLfloat diff[] = { 0.18275f,0.17f,0.22525f,1.0f };
			GLfloat spec[] = { 0.332741f,0.328634f,0.346435f,1.0f };
			GLfloat shine = 38.4f;
			glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, amb);
			glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, diff);
			glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, spec);
			glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, shine);
		}
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
			/*
			//----FRONT LIGHT....OR SOMETHING
			{glPushMatrix();
			glColor3f(0.9, 0.86, 0.25);
			glTranslatef(BODY_SIZE, 0, 0);
			glRotatef(180, 1, 0, 0);
			glRotatef(-90, 0, 1, 0);
			glutSolidCone(0.2, LIGHT_RANGE, 5, 5);
			glPopMatrix();

			}*/glPushMatrix(); {
				
				{
					/* comment the material*/
					GLfloat amb[] = { 0.13f,0.27f,0.03f,1.0f };
					GLfloat diff[] = { 0.07568f,0.61424f,0.07568f,1.0f };
					GLfloat spec[] = { 0.06f,0.55f,0.02f,1.0f };
					GLfloat shine = 128.0f;
					glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, amb);
					glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, diff);
					glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, spec);
					glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, shine);
				}
				glColor3f(0, 1, 0);
				glScalef(1, 1, 0.5);
				
				//CAR BODY MALHAS

				glPushMatrix(); {
					
					glBegin(GL_POLYGON);
					glNormal3f(0, 0, -1);
					glVertex3f(-BODY_SIZE / 2, -BODY_SIZE / 2, -BODY_SIZE / 2);
					glVertex3f(-BODY_SIZE / 2, BODY_SIZE / 2, -BODY_SIZE / 2);
					glVertex3f(BODY_SIZE / 2, BODY_SIZE / 2, -BODY_SIZE / 2);
					glVertex3f(BODY_SIZE / 2, -BODY_SIZE / 2, -BODY_SIZE / 2);

					glEnd();

					glBegin(GL_POLYGON);
					glNormal3f(0, 0, 1);
					glVertex3f(-BODY_SIZE / 2, -BODY_SIZE / 2, BODY_SIZE / 2);
					glVertex3f(-BODY_SIZE / 2, BODY_SIZE / 2, BODY_SIZE / 2);
					glVertex3f(BODY_SIZE / 2, BODY_SIZE / 2, BODY_SIZE / 2);
					glVertex3f(BODY_SIZE / 2, -BODY_SIZE / 2, BODY_SIZE / 2);

					glEnd();

					glBegin(GL_POLYGON);
					glNormal3f(1, 0, 0);
					glVertex3f(BODY_SIZE / 2, -BODY_SIZE / 2, -BODY_SIZE / 2);
					glVertex3f(BODY_SIZE / 2, BODY_SIZE / 2, BODY_SIZE / 2);
					glVertex3f(BODY_SIZE / 2, BODY_SIZE / 2, -BODY_SIZE / 2);
					glVertex3f(BODY_SIZE / 2, -BODY_SIZE / 2, BODY_SIZE / 2);

					glEnd();

					glBegin(GL_POLYGON);
					glNormal3f(-1, 0, 0);
					glVertex3f(-BODY_SIZE / 2, -BODY_SIZE / 2, -BODY_SIZE / 2);
					glVertex3f(-BODY_SIZE / 2, BODY_SIZE / 2, BODY_SIZE / 2);
					glVertex3f(-BODY_SIZE / 2, BODY_SIZE / 2, -BODY_SIZE / 2);
					glVertex3f(-BODY_SIZE / 2, -BODY_SIZE / 2, BODY_SIZE / 2);

					glEnd();

					glBegin(GL_POLYGON);
					glNormal3f(0, 1, 0);
					glVertex3f(-BODY_SIZE / 2, BODY_SIZE / 2, -BODY_SIZE / 2);
					glVertex3f(BODY_SIZE / 2, BODY_SIZE / 2, BODY_SIZE / 2);
					glVertex3f(-BODY_SIZE / 2, BODY_SIZE / 2, BODY_SIZE / 2);
					glVertex3f(BODY_SIZE / 2, BODY_SIZE / 2, BODY_SIZE / 2);

					glEnd();

					glBegin(GL_POLYGON);
					glNormal3f(0, -1, 0);
					glVertex3f(-BODY_SIZE / 2, -BODY_SIZE / 2, -BODY_SIZE / 2);
					glVertex3f(BODY_SIZE / 2, -BODY_SIZE / 2, BODY_SIZE / 2);
					glVertex3f(-BODY_SIZE / 2, -BODY_SIZE / 2, BODY_SIZE / 2);
					glVertex3f(BODY_SIZE / 2, -BODY_SIZE / 2, BODY_SIZE / 2);

					glEnd();


				}glPopMatrix();

				//glutSolidCube(BODY_SIZE);
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

bool Car::checkHit(GameObject *)
{
	return false;
}
