#pragma once

#include "PerspectiveCamera.h"

class FollowCarCamera :public PerspectiveCamera {

public:
	FollowCarCamera(double fovy, double aspect, double near, double far);
	~FollowCarCamera();
	void update();
	void computeProjectionMatrix();
	void computeVisualizationMatrix();

};
