#ifndef __TABLE_H__
#define __TABLE_H__

#include "StaticObject.h"
#include <GL/glut.h>

class Table : public StaticObject {

public:
	Table();
	~Table();
	void draw();
	void update();
};


#endif
