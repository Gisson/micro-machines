#include <iostream>
#include "FollowCarCamera.h"

FollowCarCamera::FollowCarCamera(double fovy, double aspect, double near, double far):PerspectiveCamera(fovy,aspect,near,far) {

}
FollowCarCamera::~FollowCarCamera() {

}
void FollowCarCamera::update() {

}
void FollowCarCamera::computeProjectionMatrix(){
	//std::cout << getAspect() << std::endl;
	gluPerspective(getFovy(), getAspect(), getNear(), getFar());
}

void FollowCarCamera::computeVisualizationMatrix() {

}