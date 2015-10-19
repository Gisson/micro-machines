#include "Butter.h"

Butter::Butter()
{
	_xPosition = (((double)rand() / (RAND_MAX)) * 4.8) - 2.4;
	_yPosition = (((double)rand() / (RAND_MAX)) * 4.8) - 2.4;

}

Butter::~Butter()
{
}

void Butter::draw()
{
	glPushMatrix();
	glLoadIdentity();
	glColor3f(1.0, 1.0, 0.0);
	glTranslatef(_xPosition, _yPosition, 3.2);
	glScalef(BUTTER_SIZE_X, BUTTER_SIZE_Y, BUTTER_SIZE_X);
	glutSolidCube(1);
	glPopMatrix();

}