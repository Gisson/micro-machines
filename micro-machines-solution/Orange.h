#ifndef __ORANGE_H__
#define __ORANGE_H__

#include <cstdlib>
#include <time.h>
#include "Obstacle.h"

class Orange :Obstacle {
private:
	double _xPosition, _yPosition;
public:
	Orange();
	void draw();
};

#endif
