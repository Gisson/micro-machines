#ifndef __TABLE_H__
#define __TABLE_H__

#include "SOIL.h"
#include "StaticObject.h"


class Table : public StaticObject {

public:
	Table();
	~Table();
	void draw();
	void update();
};


#endif
