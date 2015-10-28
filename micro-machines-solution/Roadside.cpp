#include "Roadside.h"

Roadside::Roadside():StaticObject()
{
	for (int i = 0;i < CHEERIO_NR_IN;i++) {
		cereals_in[i] = new Cheerio(cos((9 * i * PI) / 180), sin((9 * i * PI) / 180), 3.2);
	}
	for (int i = 0;i < CHEERIO_NR_OUT;i++) {
		cereals_out[i] = new Cheerio((3 - 0.25)*cos((9 * i * PI) / 180), (3 - 0.25)*sin((9 * i * PI) / 180), 3);
		//std::cout << "X: " << cereals_out[i]->getPosition()->getX() << " Y: " << cereals_out[i]->getPosition()->getY() << " Z: " << cereals_out[i]->getPosition()->getZ() << std::endl;
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
	bool rtn = false;
	for (int i = 0; i < CHEERIO_NR_IN; i++) {
		cereals_in[i]->Obstacle::checkHit(object);

	}

	for (int i = 0; i < CHEERIO_NR_OUT; i++) {
		rtn=cereals_out[i]->Obstacle::checkHit(object);
	}
	return rtn;
}
void Roadside::update(double time) {

	for (int i = 0; i < CHEERIO_NR_IN; i++) {
		cereals_in[i]->update(time);

	}

	for (int i = 0; i < CHEERIO_NR_OUT; i++) {
		cereals_out[i]->update(time);
	}
}
