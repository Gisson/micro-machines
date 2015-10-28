#include "Butter.h"

Butter::Butter()
{
	_xPosition = (((double)rand() / (RAND_MAX)) * 4.8) - 2.4;
	_yPosition = (((double)rand() / (RAND_MAX)) * 4.8) - 2.4;
	_zPosition = (TABLE_SIZE / 2) + BUTTER_SIZE_Z;
	getHitBox()->setPosition(_xPosition, _yPosition, _zPosition);
	getHitBox()->setRadius(sqrt(pow(BUTTER_SIZE_X/2, 2) + pow(BUTTER_SIZE_Y/2, 2)));
}

Butter::~Butter()
{
}

void Butter::draw()
{
	glPushMatrix();
	glLoadIdentity();
	glColor3f(1.0, 1.0, 0.0);
	glTranslatef(_xPosition, _yPosition, _zPosition);
	glScalef(BUTTER_SIZE_X, BUTTER_SIZE_Y, BUTTER_SIZE_X);
	glutSolidCube(1);
	glPopMatrix();

}

bool Butter::checkHit(GameObject* object)
{

	if (GameObject::checkHit(object) && object->isCar()) {
		((DynamicObject*)object)->setSpeed(0.2);
		std::cout << "HIT BUTTER!!!" << std::endl;
		return true;
	}
	return false;
}
