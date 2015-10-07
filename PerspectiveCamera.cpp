#include "PerspectiveCamera.h"


PerspectiveCamera::PerspectiveCamera(double fovy, double aspect, double near, double far) :Camera (near,far)
{
	
}



void PerspectiveCamera::update()
{
}

void PerspectiveCamera::computeProjectionMatrix()
{
}

void PerspectiveCamera::computeVisualizationMatrix()
{
}


PerspectiveCamera::~PerspectiveCamera()
{
}
