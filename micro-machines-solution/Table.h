#ifndef __TABLE_H__
#define __TABLE_H__


#include "StaticObject.h"
#include "BmpRead.h"


class Table : public StaticObject {
private:
	BmpRead *bmp;
	GLuint	nuno;
public:
	Table();
	~Table();
	void draw();
	void update();
	void loadText();
};


#endif
