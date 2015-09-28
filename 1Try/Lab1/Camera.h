#ifndef __CAMERA_H__
#define __CAMERA_H__
#include "Entity.h";

class Camera : Entity {

private:
	double _far, _near;
public:
	Camera(double near, double far);
	void update();
	void computerProjectionMatrix();
	void computeVisualizationMatrix();


};



#endif
