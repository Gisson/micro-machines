#pragma once

#include "PerspectiveCamera.h"

class SeeFullRoadCamera :PerspectiveCamera {

public:
	SeeFullRoadCamera(double fovy, double aspect, double near, double far);
	~SeeFullRoadCamera();
	void update();
	void computeProjectionMatrix();
	void computeVisualizationMatrix();

};
