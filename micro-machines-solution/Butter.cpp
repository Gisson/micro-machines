#include "Butter.h"

Butter::Butter()
{
	double _xPosition = (((double)rand() / (RAND_MAX)) * 4.8) - 2.4;
	double _yPosition = (((double)rand() / (RAND_MAX)) * 4.8) - 2.4;
	double _zPosition = (TABLE_SIZE / 2) + BUTTER_SIZE_Z;
	setPosition(_xPosition, _yPosition, _zPosition);
	getHitBox()->setPosition(_xPosition, _yPosition, _zPosition);
	getHitBox()->setRadius(sqrt(pow(BUTTER_SIZE_X/4, 2) + pow(BUTTER_SIZE_Y/4, 2)));
}

Butter::~Butter()
{
}

void Butter::draw()
{
	glPushMatrix();
	glLoadIdentity();

	{
		/* comment the material*/
		GLfloat amb[] = { 1.0f,1.0f,0.0f,1.0f };
		GLfloat diff[] = { 0.4f,0.4f,0.4f,1.0f };
		GLfloat spec[] = { 0.774597f,0.774597f,0.774597f,1.0f };
		GLfloat shine = 76.8f;
		glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, amb);
		glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, diff);
		glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, spec);
		glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, shine);
	}
	glColor3f(1.0, 1.0, 0.0);
	glTranslatef(getPosition()->getX(), getPosition()->getY(), getPosition()->getZ());
	glScalef(BUTTER_SIZE_X, BUTTER_SIZE_Y, BUTTER_SIZE_X);
	glutSolidCube(1);
	glPopMatrix();

}


