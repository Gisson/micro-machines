#ifndef __VECTOR3_H__
#define __VECTOR3_H__

#include <string>
#include <iostream>

class Vector3 {
private:
	double _x, _y, _z;
public:
	Vector3();
	Vector3(double, double, double);
	double getX();
	double getY();
	double getZ();
	double norm();
	void set(double, double, double);
	Vector3 operator=(const Vector3&);
	Vector3 operator+(const Vector3&);
	Vector3 operator-(const Vector3&);
	friend std::ostream& operator<<(std::ostream& os, const Vector3& obj);   //FIXME

};

#endif