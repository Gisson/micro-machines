#pragma once

#include "StaticObject.h"


class Candle :public StaticObject {
private:

public:
	Candle(Vector3 * position);
	~Candle();
	void draw();



};