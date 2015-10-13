#include "Table.h"
#include <GL/glut.h>


Table::Table()
{
}

Table::~Table()
{
}

void Table::draw(bool isWired)
{
	glPushMatrix();
	glLoadIdentity();
	glColor3f(1.0f, 1.0f, 1.0f);
	isWired==true? glutWireCube(6):glutSolidCube(6);
	glPopMatrix();
}

void Table::draw()
{
	glPushMatrix();
	glLoadIdentity();
	glColor3f(1.0f, 1.0f, 1.0f);
	glutSolidCube(6);
	glPopMatrix();
}
