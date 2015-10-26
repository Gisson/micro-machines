#include "Roadside.h"

Roadside::Roadside()
{
	for (int i = 0;i < CHEERIO_NR_IN;i++) {
		cereals_in[i] = new Cheerio();
	}
	for (int i = 0;i < CHEERIO_NR_OUT;i++) {
		cereals_out[i] = new Cheerio();
	}

}

Roadside::~Roadside()
{
}


void Roadside::draw()
{
	glPushMatrix();
	glLoadIdentity();
	glColor3f(0.4f, 0.6f, 0.0f);
	for (int i = 0; i < CHEERIO_NR_OUT; i++) {
		glPushMatrix();
		glRotatef(9 * i, 0, 0, 1);
		glTranslatef(3 - 0.25, 0, 3);
		cereals_in[i]->draw();
		glPopMatrix();
	}

	for (int i = 0; i < CHEERIO_NR_IN; i++) {
		glPushMatrix();
		glRotatef(9 * i, 0, 0, 1);
		glTranslatef(1.0, 0, 3);
		cereals_out[i]->draw();
		glPopMatrix();
	}
	glPopMatrix();
}