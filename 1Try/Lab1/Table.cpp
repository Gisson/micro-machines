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
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0f, 0.7f, 0.9f);
	glutSolidCube(3);
}
