#include "Camera.h"

Camera::Camera(double near, double far) :Entity()
{
	_near = near;
	_far = far;
}

void Camera::update()
{
}

void Camera::computeProjectionMatrix()
{
}

void Camera::computeVisualizationMatrix()
{
}

double Camera::getNear() {
	return _near;
}

double Camera::getFar() {
	return _far;
}
