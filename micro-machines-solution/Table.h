#ifndef __TABLE_H__
#define __TABLE_H__

#include "StaticObject.h"

class Table : public StaticObject {

public:
	Table();
	~Table();
	void draw(bool);
	void draw();
};


#endif
