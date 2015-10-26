#include "Cheerio.h"

Cheerio::Cheerio()
{
}

Cheerio::~Cheerio()
{
}

void Cheerio::draw()
{
	glutSolidTorus(0.01, 0.05, 4, 20);
}
