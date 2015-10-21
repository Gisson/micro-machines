#include <iostream>
#include "SeeFullRoadCamera.h"

SeeFullRoadCamera::SeeFullRoadCamera(double fovy, double aspect, double near, double far) :PerspectiveCamera(fovy, aspect, near, far) {

}
SeeFullRoadCamera::~SeeFullRoadCamera() {

}
void SeeFullRoadCamera::update() {

}
void SeeFullRoadCamera::computeProjectionMatrix() {
	std::cout << "Fovy: " << getFovy() << " Aspect: " << getAspect() << " Near: " << getNear() << " Far: " << getFar() << std::endl;
	gluPerspective(getFovy(), getAspect(), getNear(), getFar());
}

void SeeFullRoadCamera::computeVisualizationMatrix() {

}