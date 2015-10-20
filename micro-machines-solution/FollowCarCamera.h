#pragma once

#include "PerspectiveCamera.h"

class FollowCarCamera :PerspectiveCamera {

public:
	FollowCarCamera(double fovy, double aspect, double near, double far);
	~FollowCarCamera();
	void update();
	void computeProjectionMatrix();
	void computeVisualizationMatrix();

};
