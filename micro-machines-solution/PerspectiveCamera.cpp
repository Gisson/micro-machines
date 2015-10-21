#include "PerspectiveCamera.h"


PerspectiveCamera::PerspectiveCamera(double fovy, double aspect, double near, double far) :Camera (near,far)
{
	_fovy = fovy;
	_aspect = aspect;
}



void PerspectiveCamera::update()
{
}

void PerspectiveCamera::computeProjectionMatrix()
{
}

void PerspectiveCamera::computeVisualizationMatrix()
{
}

void PerspectiveCamera::setFovy(double newFov) {
	_fovy = newFov;
}
void PerspectiveCamera::setAspect(double newAspect) {
	_aspect = newAspect;
}

PerspectiveCamera::~PerspectiveCamera()
{
}

double PerspectiveCamera::getFovy() {
	return _fovy;
}


double PerspectiveCamera::getAspect() {
	return _aspect;
}
