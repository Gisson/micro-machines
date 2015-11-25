#ifndef __TABLE_H__
#define __TABLE_H__


#include "StaticObject.h"
#define TABLE_FILENAME	"../wood.bmp"

class Table : public StaticObject {
public:
	Table();
	~Table();
	void draw();
	void update();
};


#endif
