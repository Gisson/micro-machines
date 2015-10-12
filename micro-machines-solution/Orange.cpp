#include "Orange.h"

Orange::Orange()
{
}

void Orange::draw()
{
	double xPosition = ((double) rand() / (RAND_MAX)) * 1.5;
	double yPosition = ((double) rand() / (RAND_MAX)) * 1.5;
	glPushMatrix();
	glLoadIdentity();
	glColor3f(1.0, 0.5, 0.0 );
	glTranslatef( xPosition , yPosition ,3.2);
	glutSolidSphere(0.2,100,100);
	glPopMatrix();

}
