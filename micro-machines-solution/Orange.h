#ifndef __ORANGE_H__
#define __ORANGE_H__

#include <cstdlib>
#include <time.h>
#include "Obstacle.h"

class Orange : public Obstacle {
private:
	double _xPosition, _yPosition;
public:
	Orange();
	void draw(bool);
	void draw();
};

#endif
