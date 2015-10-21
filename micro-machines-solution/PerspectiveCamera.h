
#ifndef __PERSPECTIVECAMERA_H__
#define __PERSPECTIVECAMERA_H__
#include "Camera.h"
#include "Entity.h"

class PerspectiveCamera :public Camera {

private:
	double _fovy, _aspect;

public:
	virtual void update();
	virtual void computeProjectionMatrix();
	virtual void computeVisualizationMatrix();
	PerspectiveCamera(double fovy, double aspect, double near, double far);
	~PerspectiveCamera();
	void setFovy(double newFov);
	double getFovy();
	void setAspect(double newAspect);
	double getAspect();
};


#endif