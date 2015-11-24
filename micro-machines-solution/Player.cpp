#include "Player.h"

Player::Player()
{
	
	_lifeNum = MAX_LIFES;
	for (int i = 0; i < MAX_LIFES; i++) {
		Car* nc = new Car();
		Vector3 *v3 = new Vector3(0, 0, 4);
		v3->set(4-BODY_SIZE*2*i, 4, 4+ BODY_SIZE);
		nc->setPosition(v3);
		_lifeCar.push_back(nc);
	}
	_oc = new OrthogonalCamera(-5, 5, -5, 5, -5, 5);

}

Player::~Player()
{
}

int Player::gainLife() //not tested
{
	if (_lifeNum == MAX_LIFES)  _lifeNum = MAX_LIFES;  
	else {
		_lifeNum++; Car* nc = new Car(); nc->setPosition(new Vector3(BODY_SIZE*_lifeNum,0,4)); _lifeCar.push_back(nc);
	}
	_lifeCar.pop_back();
	return _lifeNum;
}

int Player::loseLife()
{
	if (_lifeNum == 0) _lifeNum = -1; else { _lifeNum--; _lifeCar.pop_back();  }
	 
	return _lifeNum;
}

bool Player::isDead()
{
	return _lifeNum < 0 ? true : false;
}

void Player::draw()
{
	glMatrixMode(GL_PROJECTION);
	glPushMatrix();
	glLoadIdentity();
	_oc->computeProjectionMatrix();
	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();
	glLoadIdentity();
	for (Car* go : _lifeCar) {
		go->draw();
	}
	glPopMatrix();
	glMatrixMode(GL_PROJECTION);
	glPopMatrix();
	glMatrixMode(GL_MODELVIEW);
}
