
#ifndef __ORTHOGONALCAMERA_H__
#define __ORTHOGONALCAMERA_H__
#include "Camera.h"
#include "Entity.h"

class OrthogonalCamera :Camera {

private:
	double _left, _right, _bottom, _top;
public:
	void update();
	void computeProjectionMatrix();
	void computeVisualizationMatrix();
	OrthogonalCamera(double fovy, double aspect, double near, double far);
	~OrthogonalCamera();

};


#endif