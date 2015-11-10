#include "Table.h"



Table::Table()
{
}

Table::~Table()
{
}


void Table::draw()
{
	glPushMatrix();
	glNormal3f(0, 0, 1);
	{
		/* comment the material*/
		GLfloat amb[] = { 0.0f,0.0f,0.52f,1.0f };
		GLfloat diff[] = { 0.01f,0.01f,0.01f,1.0f };
		GLfloat spec[] = { 0.5f,0.5f,0.5f,1.0f };
		GLfloat shine = 32.0f;
		glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, amb);
		glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, diff);
		glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, spec);
		glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, shine);
	}
	glColor3f(0.98f, 0.6f, 0.7f);
	glutSolidCube(TABLE_SIZE);
	glPopMatrix();
}

void Table::update()
{
}
