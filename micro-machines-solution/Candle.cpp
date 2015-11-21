#include "Candle.h"

Candle::Candle(Vector3 * position)
{
	setPosition(position);
	//_direction->set(direction->getX(), direction->getY(), direction->getZ());
}

Candle::~Candle()
{
}

void Candle::draw()
{
	glPushMatrix();

	glTranslatef(getPosition()->getX(), getPosition()->getY(), getPosition()->getZ()+0.25);

	/* comment the material*/
	GLfloat amb[] = { 0.0f,1.0f,1.0f,1.0f };
	GLfloat diff[] = { 0.01f,0.01f,0.01f,1.0f };
	GLfloat spec[] = { 0.0f,1.0f,0.5f,1.0f };
	GLfloat shine = 0.f;
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, amb);
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, diff);
	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, spec);
	glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, shine);
	glColor3f(0, 0.2, 0.8);
	glutSolidCube(0.25);
	glPopMatrix();
}
