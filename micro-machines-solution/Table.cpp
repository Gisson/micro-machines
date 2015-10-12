#include "Table.h"
#include <GL/glut.h>


Table::Table()
{
}

Table::~Table()
{
}

void Table::draw()
{
	glPushMatrix();
	glLoadIdentity();
	glColor3f(1.0f, 1.0f, 1.0f);
	//glTranslatef(20, 20, 10.0f);
	glutSolidCube(6);
	glPopMatrix();
}
