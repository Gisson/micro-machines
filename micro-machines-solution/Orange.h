#ifndef __ORANGE_H__
#define __ORANGE_H__

#include <cstdlib>
#include <time.h>
#include "Obstacle.h"

#define ORANGE_RADIUS 0.2

class Orange : public Obstacle {
public:
	Orange();
	void draw();
	void update(double);
};

#endif
