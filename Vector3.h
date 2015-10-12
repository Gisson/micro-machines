#ifndef __VECTOR3_H__
#define __VECTOR3_H__


class Vector3 {
private:
	double _x, _y, _z;
public:
	Vector3();
	Vector3(double, double, double);
	double getX();
	double getY();
	double getZ();
	void set(double, double, double);
	Vector3 operator=(const Vector3&);
	Vector3 operator+(const Vector3&);
	Vector3 operator-(const Vector3&);

};

#endif