#ifndef __CHEERIOS_H__
#define __CHEERIOS_H__
#include "Obstacle.h"

#define TORUS_RADIUS_INNER 0.03
#define TORUS_RADIUS_OUTER 0.05


class Cheerio :public Obstacle {
public:
	Cheerio(double,double,double);
	~Cheerio();
	void draw();
};

#endif