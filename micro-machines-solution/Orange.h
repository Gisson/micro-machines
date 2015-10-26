#ifndef __ORANGE_H__
#define __ORANGE_H__

#include <cstdlib>
#include <time.h>
#include "Obstacle.h"

#define ORANGE_RADIUS 0.2
#define SPAWN_TIME 5
#define MAX_SPEED 4

class Orange : public Obstacle {
private:
	double _angle_z,_spawn_time;
public:
	Orange();
	void draw();
	void update(double);
	void setAngle_z(double);
	double getAngle_z();
};

#endif
