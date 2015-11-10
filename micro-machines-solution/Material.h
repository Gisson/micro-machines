#pragma once
#include <GL/glut.h>

class Material {

	Material();
	~Material();
	void defineMaterial(GLfloat *amb, GLfloat *dif, GLfloat *spec, GLfloat *shine);
};