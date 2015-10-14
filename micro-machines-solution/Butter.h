#ifndef __BUTTER_H__
#define __BUTTER_H__

#include <cstdlib>
#include <time.h>
#include "Obstacle.h"

class Butter :public Obstacle {
private:
	double _xPosition, _yPosition;
public:
	Butter();
	~Butter();
	void draw(bool);
	void draw();
};

#endif
