#pragma once
#include <vector>
#include "Car.h"

#define MAX_LIFES	3

class Player {
private:
	int _lifeNum;
	std::vector<Car*> _lifeCar;
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