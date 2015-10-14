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
	Table::draw();
	/*glPushMatrix();
	glLoadIdentity();
	glColor3f(0.0f, 1.0f, 1.0f);
	isWired==true? glutWireCube(6):glutSolidCube(6);
	glPopMatrix();*/
}

void Table::draw()
{
	glPushMatrix();
	glLoadIdentity();
	glColor3f(0.98f, 0.6f, 0.7f);
	glutSolidCube(6);
	glPopMatrix();
}

void Table::update()
{
}
