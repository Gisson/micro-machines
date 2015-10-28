
#ifndef __OBSTACLE_H__
#define  __OBSTACLE_H__


#include "GameObject.h"
#include "DynamicObject.h"


class Obstacle : public DynamicObject {
public:
	Obstacle();
	~Obstacle();
	bool checkHit(GameObject*) override;
};

#endif