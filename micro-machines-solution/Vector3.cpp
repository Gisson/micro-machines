#include "Vector3.h"
#include <cmath>

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

double Vector3::norm()
{
	return (pow(getX(), 2)) + pow(getY(), 2) + pow(getZ(), 2);
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


std::ostream& operator<<(std::ostream& os, const Vector3& obj)
{
	return os << "X: " << obj._x<< " Y: " << obj._y << " Z: " << obj._z << std::endl;

}
