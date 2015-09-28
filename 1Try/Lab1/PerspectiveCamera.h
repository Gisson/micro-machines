
#ifndef __PERSPECTIVECAMERA_H__
#define __PERSPECTIVECAMERA_H__
#include "Camera.h";
#include "Entity.h"

class PerspectiveCamera :Camera {

private:
	double _fovy, _aspect;
public:
	void update();
	void computeProjectionMatrix();
	void computeVisualizationMatrix();
	PerspectiveCamera(double fovy, double aspect, double near, double far);
	~PerspectiveCamera();

};


#endif