#ifndef __LIGHTSOURCE__
#define __LIGHTSOURCE__
#include "Vector3.h"
#include "GL/glut.h"
class LightSource
{
	double _ambient[4],_difuse[4],_specular[4],_position[4];
	Vector3 *_direction;
	GLfloat	_cut_off;
	GLfloat	_exponent;
	unsigned int _num;
	bool	_state;
public:
	LightSource(unsigned int number);
	~LightSource();
	bool getState();
	bool setState(bool state);
	unsigned int getNum();
	double getX();
	double getY();
	double getZ();
	double getW();
	void setPosition(GLdouble x, GLdouble y, GLdouble z, GLdouble w);
	void setDirection(GLdouble x, GLdouble y, GLdouble z);
	void setCutOff(double cut_off);
	void setExponent(double exponent);
	void setAmbient(GLdouble x, GLdouble y, GLdouble z, GLdouble w);
	void setDiffuse(GLdouble x, GLdouble y, GLdouble z, GLdouble w);
	void setSpecular(GLdouble x, GLdouble y, GLdouble z, GLdouble w);
	void draw();
};


#endif

