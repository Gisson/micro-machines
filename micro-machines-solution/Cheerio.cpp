#include "Cheerio.h"

Cheerio::Cheerio(double x, double y, double z)
{
	setPosition(x, y, z);
	getHitBox()->setPosition(x, y, z);
	getHitBox()->setRadius(TORUS_RADIUS_OUTER);
	//std::cout<<"RADIUS: "<<getHitBox()->getRadius() << std::endl;
}

Cheerio::~Cheerio()
{
}

void Cheerio::draw()
{
	glutSolidTorus(TORUS_RADIUS_INNER, TORUS_RADIUS_OUTER, 4, 20);
}

void Cheerio::update(double time)
{

}

