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
	glColor3f(0.98f, 0.6f, 0.7f);
	glutSolidCube(2*TABLE_SIZE);
	glPopMatrix();
}

void Table::update()
{
}
