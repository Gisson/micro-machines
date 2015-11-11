#pragma once

#include "StaticObject.h"
#include "Vector3.h"

class Candle :public StaticObject {
private:

	Vector3 *_direction;

public:
	Candle(Vector3* position, Vector3* direction);
	~Candle();
	void draw();


};