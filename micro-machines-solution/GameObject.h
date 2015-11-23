#ifndef __GAMEOBJECT_H__
#define __GAMEOBJECT_H__
#include <SOIL.h>
#include "Entity.h"
#include "HitBox.h"

#define TABLE_SIZE 6

class GameObject :Entity {
private:
	Vector3 *_position;
	HitBox *_hitBox;
	GLuint _tex;

public:
	void setPosition(double, double, double);
	void setPosition(Vector3*);
	Vector3* getPosition();

	void setTexture(GLuint);
	GLuint getTexture();

	GameObject();
	virtual bool checkHit(GameObject *);
	HitBox* getHitBox();

	virtual void draw()=0;
	virtual void update(double t)=0;
	virtual bool isCar()=0;

};



#endif