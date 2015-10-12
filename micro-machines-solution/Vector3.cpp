#include "Vector3.h"

Vector3::Vector3()
{
}

Vector3::Vector3(double x, double y , double z)
{
	_x = x;
	_y = y;
	_z = z;
}

double Vector3::getX()
{
	return _x;
}

double Vector3::getY()
{
	return _y;
}

double Vector3::getZ()
{
	return _z;
}

void Vector3::set(double x, double y, double z)
{
	_x = x;
	_y = y;
	_z = z;
}

//TODO: FIXME
Vector3 Vector3::operator=(const Vector3 &v3)
{
	return Vector3();
}

Vector3 Vector3::operator+(const Vector3& v3)
{
	return Vector3(_x + v3._x, _y + v3._y, _z + v3._z);
}

Vector3 Vector3::operator-(const Vector3 &v3)
{
	return Vector3(_x - v3._x, _y-v3._y, _z-v3._z);
}
