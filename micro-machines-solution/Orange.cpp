#include "Orange.h"

Orange::Orange()
{
	_xPosition = ((double)rand() / (RAND_MAX)) * 1.5;
	_yPosition = ((double)rand() / (RAND_MAX)) * 1.5;
}

void Orange::draw()
{

	glPushMatrix();
	glLoadIdentity();
	glColor3f(1.0, 0.5, 0.0 );
	glTranslatef( _xPosition , _yPosition ,3.2);
	glutSolidSphere(0.2,100,100);
	glPopMatrix();

}
