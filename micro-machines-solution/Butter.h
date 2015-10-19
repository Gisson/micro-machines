#ifndef __BUTTER_H__
#define __BUTTER_H__

#include <cstdlib>
#include <time.h>
#include "Obstacle.h"

#define BUTTER_SIZE_X 0.2
#define BUTTER_SIZE_Y 0.5

class Butter :public Obstacle {
private:
	double _xPosition, _yPosition;
public:
	Butter();
	~Butter();
	void draw();
};

#endif
