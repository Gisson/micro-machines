#ifndef __CHEERIOS_H__
#define __CHEERIOS_H__
#include "Obstacle.h"


class Cheerio :public Obstacle {
public:
	Cheerio();
	~Cheerio();
	void draw();
};

#endif