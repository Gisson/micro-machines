#ifndef __BUTTER_H__
#define __BUTTER_H__


#include <time.h>
#include "Obstacle.h"

#define BUTTER_SIZE_X 0.2
#define BUTTER_SIZE_Y 0.5
#define BUTTER_SIZE_Z 0.2

class Butter :public Obstacle {
private:
	double _xPosition, _yPosition,_zPosition;
public:
	Butter();
	~Butter();
	void draw();
	bool checkHit(GameObject*) override;
};

#endif
