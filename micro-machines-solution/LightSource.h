#ifndef __LIGHTSOURCE_H__
#define __LIGHTSOURCE_H__

#include <GL/glut.h>
#include "Vector3.h"

class LightSource {
private:
	double _ambient[4], _diffuse[4], _specular[4], _cut_off, _exponent;
	GLenum _num;
	bool _state;
public:
	LightSource(GLenum number);
	bool getState();
	void setState(bool state);
	GLenum getNum();
	void setPosition(const Vector3&); //FIXME maybe Vector4 
	void setDirection(const Vector3&);
	void setCutoff(double cutoff);
	void setExponent(double exponent);
	void setAmbient(const Vector3&);//FIXME maybe Vector4
	void setDiffuse(const Vector3&);//FIXME maybe Vector4
	void setSpecular(const Vector3&);//FIXME maybe Vector 4
	void draw();
};

#endif
