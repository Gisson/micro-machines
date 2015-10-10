#include "Roadside.h"

Roadside::Roadside()
{

}

Roadside::~Roadside()
{
}

void Roadside::draw()
{
	glPushMatrix();
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0.4f, 0.6f, 0.0f);
	for (int i = 0; i < 40; i++) {
		glPushMatrix();
		glRotatef(9 * i, 0, 0, 1);
		glTranslatef(2 - 0.25, 0, -2);
		glutSolidTorus(0.01, 0.05, 4, 20);
		glPopMatrix();
	}

	for (int i = 0; i < 40; i++) {
		glPushMatrix();
		glRotatef(6 * i, 0, 0, 1);
		glTranslatef(1.0, 0, 2);
		glutSolidTorus(0.01, 0.05, 4, 20);
		glPopMatrix();
	}
	glPopMatrix();
}