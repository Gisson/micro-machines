
#include "LightSource.h"
#include "GL/glut.h"
#include <iostream>
LightSource::LightSource(unsigned int number) {
	_num = number; _state = false; _cut_off = 180;
	_direction->set(0, 0, 0);
}
LightSource::~LightSource() { }
bool LightSource::getState() { return _state; }
bool LightSource::setState(bool state) {
	_state = state;
	if (state) {
		glEnable(GL_LIGHT0 + _num);
	}
	else {
		glDisable(GL_LIGHT0 + _num);
	}
	return _state;
}
unsigned int LightSource::getNum() { return _num; }
void LightSource::setPosition(GLdouble x, GLdouble y, GLdouble z, GLdouble w) { _position[0] = x; _position[1] = y; _position[2] = z; _position[3] = w; }
double LightSource::getX() { return _position[0]; }
double LightSource::getY() { return _position[1]; }
double LightSource::getZ() { return _position[2]; }
double LightSource::getW() { return _position[3]; }
void LightSource::setDirection(GLdouble x, GLdouble y, GLdouble z) { _direction->set(x, y, z); }
void LightSource::setCutOff(double cut_off) { _cut_off = cut_off; }
void LightSource::setExponent(double exponent) { _exponent = exponent; }
void LightSource::setAmbient(GLdouble x, GLdouble y, GLdouble z, GLdouble w) { _ambient[0] = x; _ambient[1] = y; _ambient[2] = z; _ambient[3] = w; }
void LightSource::setDiffuse(GLdouble x, GLdouble y, GLdouble z, GLdouble w) { _difuse[0] = x; _difuse[1] = y; _difuse[2] = z; _difuse[3] = w; }
void LightSource::setSpecular(GLdouble x, GLdouble y, GLdouble z, GLdouble w) { _specular[0] = x; _specular[1] = y; _specular[2] = z; _specular[3] = w; }
void LightSource::draw() {
	GLfloat light_position[] = { (GLfloat)_position[0], (GLfloat)_position[1], (GLfloat)_position[2], (GLfloat)_position[3] };
	glLightfv(GL_LIGHT0 + _num, GL_POSITION, light_position);

	GLfloat ambient[] = { (GLfloat)_ambient[0], (GLfloat)_ambient[1], (GLfloat)_ambient[2], (GLfloat)_ambient[3] };
	glLightfv(GL_LIGHT0 + _num, GL_AMBIENT, ambient);

	GLfloat diffuse[] = { (GLfloat)_difuse[0], (GLfloat)_difuse[1], (GLfloat)_difuse[2], (GLfloat)_difuse[3] };
	glLightfv(GL_LIGHT0 + _num, GL_DIFFUSE, diffuse);

	GLfloat specular[] = { (GLfloat)_specular[0], (GLfloat)_specular[1], (GLfloat)_specular[2],(GLfloat)_specular[3] };
	glLightfv(GL_LIGHT0 + _num, GL_SPECULAR, specular);

	glLightf(GL_LIGHT0 + _num, GL_SPOT_CUTOFF, _cut_off);

	GLfloat direction[] = { (GLfloat)_direction->getX(), (GLfloat)_direction->getY(), (GLfloat)_direction->getZ() };
	glLightfv(GL_LIGHT0 + _num, GL_SPOT_DIRECTION, direction);

	glLightf(GL_LIGHT0 + _num, GL_SPOT_EXPONENT, _exponent);

}