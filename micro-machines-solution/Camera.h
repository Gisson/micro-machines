#ifndef __CAMERA_H__
#define __CAMERA_H__
#include "Entity.h"



class Camera : Entity {

private:
	double _far, _near;
public:
	Camera(double near, double far);
	virtual void update()=0;
	virtual void computeProjectionMatrix()=0;
	virtual void computeVisualizationMatrix()=0;
protected:
	double getNear();
	double getFar();


};



#endif
