#ifndef __ORANGE_H__
#define __ORANGE_H__

#include <time.h>
#include "Obstacle.h"

#define ORANGE_RADIUS 0.2
#define SPAWN_TIME 5
#define MAX_SPEED 4
#define FALL_HEIGHT 5
#define OUT_OF_RANGE 500
#define FALL_FACTOR 0.1
#define MIN_SPEED 0.5
#define ORANGE_SPEEDUP_FACTOR 0.01

class Orange : public Obstacle {
private:
	double _angle_z,_spawn_time;
	GLfloat amb_orange[4], dif_orange[4], spec_orange[4], shine_orange[4];
public:
	Orange();
	void draw();
	void update(double);
	void setAngle_z(double);
	double getAngle_z();
	bool checkHit(GameObject*)override;
};

#endif
