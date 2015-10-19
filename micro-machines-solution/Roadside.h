
#ifndef __ROADSIDE_H__
#define  __ROADSIDE_H__

#include "GameObject.h"
#include "StaticObject.h"

class Roadside : public StaticObject {
public:
	Roadside();
	~Roadside();
	void draw();
};

#endif
