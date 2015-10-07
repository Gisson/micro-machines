#include "LightSource.h"

LightSource::LightSource(GLenum number)
{
	_num = number;
}

bool LightSource::getState()
{
	return _state;
}

void LightSource::setState(bool state)
{
	_state=state;
}

GLenum LightSource::getNum()
{
	return _num;
}

//FIXME
void LightSource::setPosition(const Vector3 &)
{
}


//FIXME
void LightSource::setDirection(const Vector3 &)
{
}


//FIXME
void LightSource::setCutoff(double cutoff)
{
	_cut_off = cutoff;
}

void LightSource::setExponent(double exponent)
{
	_exponent = exponent;
}

//FIXME
void LightSource::setAmbient(const Vector3 &)
{
}

//FIXME
void LightSource::setDiffuse(const Vector3 &)
{
}

//FIXME
void LightSource::setSpecular(const Vector3 &)
{
}

void LightSource::draw()
{
}
