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
	glScalef(0.2, 0.5, 0.2);
	glutSolidCube(1);
	glPopMatrix();

}
