#include "Orange.h"


Orange::Orange()
{
	_xPosition = (((double)rand() / (RAND_MAX)) * 4.8) - 2.4;
	_yPosition = (((double)rand() / (RAND_MAX)) * 4.8) - 2.4;
}


void Orange::draw()
{
	glPushMatrix();
	glLoadIdentity();
	glColor3f(1.0, 0.5, 0.0);
	glTranslatef(_xPosition, _yPosition, 3.2);
	glutSolidSphere(0.2, 15, 15);
	glPopMatrix();

}
