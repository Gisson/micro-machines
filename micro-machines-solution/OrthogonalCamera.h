
#ifndef __ORTHOGONALCAMERA_H__
#define __ORTHOGONALCAMERA_H__
#include "Camera.h"
#include "Entity.h"

class OrthogonalCamera :Camera {

private:
	double _left, _right, _bottom, _top;
public:
	OrthogonalCamera(double left, double right, double bottom, double top, double near, double far);
	~OrthogonalCamera();
	void update();
	void computeProjectionMatrix();
	void computeVisualizationMatrix();
	void setLeft(double left);
	void setRight(double right);
	void setBottom(double bottom);
	void setTop(double top);
};


#endif