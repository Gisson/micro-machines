#include "Roadside.h"

Roadside::Roadside()
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
		glTranslatef(cereals_in[i]->getPosition()->getX(), cereals_in[i]->getPosition()->getY(), cereals_in[i]->getPosition()->getZ());
		cereals_in[i]->draw();

		
		//std::cout << "REAL VALUES!!!! X: " << cereals_in[i]->getPosition()->getX() << " Y: " << cereals_in[i]->getPosition()->getY() << " Z: " << cereals_in[i]->getPosition()->getZ() << std::endl;

		glPopMatrix();
	}

	for (int i = 0; i < CHEERIO_NR_OUT; i++) {
		glPushMatrix();
		glTranslatef(cereals_out[i]->getPosition()->getX(), cereals_out[i]->getPosition()->getY(), cereals_out[i]->getPosition()->getZ());

		cereals_out[i]->draw();
		glPopMatrix();
	}
	glPopMatrix();
}

void Roadside::update(double time)
{

}

bool Roadside::checkHit(GameObject *object)
{
	for (int i = 0; i < CHEERIO_NR_IN; i++) {
		int position1 = cereals_in[i]->getHitBox()->getPosition()->norm();
		int position2 = object->getHitBox()->getPosition()->norm();
		position1 = position1 - position2;
		position2 = pow(getHitBox()->getRadius() + object->getHitBox()->getRadius(), 2);
		if (position1 <= position2) {
			std::cout << "TRUE" << std::endl;
			return true;

		}
	}
	for (int i = 0; i < CHEERIO_NR_OUT; i++) {
		int position1 = cereals_out[i]->getHitBox()->getPosition()->norm();
		int position2 = object->getHitBox()->getPosition()->norm();
		position1 = position1 - position2;
		position2 = pow(getHitBox()->getRadius() + object->getHitBox()->getRadius(), 2);
		if (position1 <= position2) {
			std::cout << "TRUE" << std::endl;
			return true;
		}
	}
	std::cout << "FALSE" << std::endl;

	return false;

}
