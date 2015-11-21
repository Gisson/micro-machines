#pragma once

#include "StaticObject.h"
#include "Vector3.h"

class Candle :public StaticObject {
private:

public:
	Candle(Vector3 * position);
	~Candle();
	void draw();



};