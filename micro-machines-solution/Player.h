#pragma once
#include <vector>
#include "Car.h"
#include "OrthogonalCamera.h"

#define MAX_LIFES	5

class Player {
private:
	int _lifeNum;
	std::vector<Car*> _lifeCar;
	OrthogonalCamera* _oc;
	Texture* _pause;
public:
	Player();
	~Player();
	int gainLife();
	int loseLife();
	int getLifes() { return _lifeNum; }
	bool isDead();
	void reviveToFullHp() { _lifeNum = MAX_LIFES; };
	void draw();
};