#ifndef __CHEERIOS_H__
#define __CHEERIOS_H__
#include "Obstacle.h"

#define TORUS_RADIUS_INNER 0.01
#define TORUS_RADIUS_OUTER 0.05


class Cheerio :public Obstacle {
public:
	Cheerio(double,double,double);
	~Cheerio();
	void draw();
	void update(double time);
};

#endif