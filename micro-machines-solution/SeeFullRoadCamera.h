#pragma once

#include "PerspectiveCamera.h"

class SeeFullRoadCamera : public PerspectiveCamera {

public:
	SeeFullRoadCamera(double fovy, double aspect, double near, double far);
	~SeeFullRoadCamera();
	void update();
	void computeProjectionMatrix();
	void computeVisualizationMatrix();

};
