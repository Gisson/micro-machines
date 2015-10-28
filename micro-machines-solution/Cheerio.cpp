#include "Cheerio.h"

Cheerio::Cheerio(double x, double y, double z)
{
	setPosition(x, y, z);
	getHitBox()->setPosition(x, y, z);
	getHitBox()->setRadius(TORUS_RADIUS_OUTER);
}

Cheerio::~Cheerio()
{
}

void Cheerio::draw()
{
	glPushMatrix();
	glTranslatef(getPosition()->getX(), getPosition()->getY(), getPosition()->getZ());
	glutSolidTorus(TORUS_RADIUS_INNER, TORUS_RADIUS_OUTER, 4, 20);
	glPopMatrix();
}

