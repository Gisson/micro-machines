#include "OrthogonalCamera.h"

OrthogonalCamera::OrthogonalCamera(double left, double right,double bottom,double top,double near, double far) :Camera(near, far)
{
	_left = left;
	_right = right;
	_bottom = bottom;
	_top = top;
}


OrthogonalCamera::~OrthogonalCamera()
{
}

void OrthogonalCamera::update()
{
}

void OrthogonalCamera::computeProjectionMatrix()
{
	glOrtho(_left, _right, _bottom, _top, Camera::getNear(), Camera::getFar());
}

void OrthogonalCamera::computeVisualizationMatrix()
{
}

void OrthogonalCamera::setLeft(double left) {
	_left = left;
}
void OrthogonalCamera::setRight(double right) {
	_right = right;
}
void OrthogonalCamera::setBottom(double bottom) {
	_bottom = bottom;
}
void OrthogonalCamera::setTop(double top) {
	_top = top;
}

