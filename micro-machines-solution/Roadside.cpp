#include "Roadside.h"

Roadside::Roadside():StaticObject()
{
	for (int i = 0;i < CHEERIO_NR_IN;i++) {
		cereals_in[i] = new Cheerio(cos((9 * i * PI) / 180), sin((9 * i * PI) / 180), TABLE_SIZE/2);
	}
	for (int i = 0;i < CHEERIO_NR_OUT;i++) {
		cereals_out[i] = new Cheerio((TABLE_SIZE/2 - LIMIT)*cos((9 * i * PI) / 180), (TABLE_SIZE/2 - LIMIT)*sin((9 * i * PI) / 180), (TABLE_SIZE/2)+TORUS_RADIUS_OUTER);
		//std::cout << "X: " << cereals_out[i]->getPosition()->getX() << " Y: " << cereals_out[i]->getPosition()->getY() << " Z: " << cereals_out[i]->getPosition()->getZ() << std::endl;
	}

}

Roadside::~Roadside()
{
}


void Roadside::draw()
{
	glPushMatrix();
	
	{
		/* comment the material*/
		GLfloat amb[] = { 0.0f,0.0f,0.0f,1.0f };
		GLfloat diff[] = { 0.01f,0.01f,0.01f,1.0f };
		GLfloat spec[] = { 0.5f,0.5f,0.5f,1.0f };
		GLfloat shine = 32.0f;
		glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, amb);
		glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, diff);
		glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, spec);
		glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, shine);
	}
	glColor3f(0.4f, 0.6f, 0.0f);
	for (int i = 0; i < CHEERIO_NR_IN; i++) {
		glPushMatrix();
		//glTranslatef(cereals_in[i]->getPosition()->getX(), cereals_in[i]->getPosition()->getY(), cereals_in[i]->getPosition()->getZ());
		cereals_in[i]->draw();

		
		//std::cout << "REAL VALUES!!!! X: " << cereals_in[i]->getPosition()->getX() << " Y: " << cereals_in[i]->getPosition()->getY() << " Z: " << cereals_in[i]->getPosition()->getZ() << std::endl;

		glPopMatrix();
	}

	for (int i = 0; i < CHEERIO_NR_OUT; i++) {
		glPushMatrix();
		//glTranslatef(cereals_out[i]->getPosition()->getX(), cereals_out[i]->getPosition()->getY(), cereals_out[i]->getPosition()->getZ());

		cereals_out[i]->draw();
		glPopMatrix();
	}
	glPopMatrix();
}

bool Roadside::checkHit(GameObject *object)
{
	for (int i = 0; i < CHEERIO_NR_IN; i++) {
		cereals_in[i]->Obstacle::checkHit(object);

	}

	for (int i = 0; i < CHEERIO_NR_OUT; i++) {
		cereals_out[i]->Obstacle::checkHit(object);
	}
	return false;
}
void Roadside::release()
{
	for (int i = 0; i < CHEERIO_NR_IN; i++) {
		free(cereals_in[i]);

	}

	for (int i = 0; i < CHEERIO_NR_OUT; i++) {
		free(cereals_out[i]);
	}
}
void Roadside::update(double time) {

	for (int i = 0; i < CHEERIO_NR_IN; i++) {
		cereals_in[i]->update(time);

	}

	for (int i = 0; i < CHEERIO_NR_OUT; i++) {
		cereals_out[i]->update(time);
	}
}
