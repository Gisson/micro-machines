#include <iostream>

#include "GameManager.h"


Game_manager::Game_manager() {
	srand(time(NULL));

	//Initializing cameras

	_orthoCam = new OrthogonalCamera(-WINDOW_SIZE, WINDOW_SIZE, -WINDOW_SIZE, WINDOW_SIZE, -WINDOW_SIZE, WINDOW_SIZE);
	_fullRoad = new SeeFullRoadCamera(FOVY,1,3,-3);
	_followCar = new FollowCarCamera(FOVY, 1, 3, -3);

	//Initializing elements of the game

	_elements = std::vector<GameObject*>();
	_table = new Table();
	_elements.push_back(_table);
	_road = new Roadside();
	_elements.push_back(_road);
	for (int i = 0;i < ORANGE_NR;i++) {
		_elements.push_back(new Orange());
	}
	for (int i = 0; i < BUTTER_NR; i++) {
		_elements.push_back(new Butter());
	}
	for (int i = 0; i < CANDLE_NR; i++) {
		LightSource* lh = new LightSource(i + 1);
		lh->setPosition(-TABLE_SIZE/2+i, -TABLE_SIZE/2+i, 4, 1);
		lh->setDirection(0, 0, -1);
		lh->setAmbient(0.2, 0.2, 0.2, 1);
		lh->setDiffuse(1, 1, 1, 1);
		lh->setSpecular(1, 1, 1, 1);
		_candles.push_back(lh);
		_elements.push_back(new Candle(new Vector3(lh->getX(), lh->getY(), lh->getZ())));
	}

	_vrum = new Car();
	_elements.push_back(_vrum);

	_globalLight = new LightSource(0);
	_globalLight->setPosition (5,5,5,0 );
	
	_globalLight->setDirection(-1, -1, -1);
	_globalLight->setAmbient(0.2,0.2,0.2,1 );
	_globalLight->setDiffuse(1,1,1,1 );
	_globalLight->setSpecular(1,1,1,1 );
	


/*
	aux = new LightSource(_candles.size());
	Vector3 *v1 = new Vector3(0, 0, 3.15);
	Vector3* v2 = new Vector3(1, 1, 1);
	Candle *newCandle = new Candle(v1, v2);
	

	aux->setPosition(newCandle->getPosition()->getX(), newCandle->getPosition()->getY(), newCandle->getPosition()->getZ()+0.2,1);
	aux->setDirection(1, 1, 1);
	aux->setSpecular(1.0, 1.0, 1.0, 1.0);
	aux->setDiffuse(1.0, 1.0, 1.0, 1.0);
	aux->setAmbient(0.2, 0.2, 0.2, 1.0);

	_elements.push_back(newCandle);*/
	

}


void Game_manager::specialKeyPressed(int key, int x, int y)
{
	switch (key)
	{
	case GLUT_KEY_UP:
		keyUp = true;
		_vrum->acelarate(ACELARATION_NUMBER);
		break;
	case GLUT_KEY_DOWN:
		keyDown = true;
		_vrum->breakAcelaration(-ACELARATION_NUMBER);
		break;
	case GLUT_KEY_LEFT:
		keyLeft = true;
		_vrum->turn(ANGLE_TURN);
		break;
	case GLUT_KEY_RIGHT:
		keyRight = true;
		_vrum->turn(-ANGLE_TURN);
		break;
	}
}
void Game_manager::specialKeyUp(int key, int x, int y)
{
	switch (key)
	{
	case GLUT_KEY_UP:
		keyUp = false;
		break;
	case GLUT_KEY_DOWN:
		keyDown = false;
		break;
	case GLUT_KEY_LEFT:
		keyLeft = false;
		break;
	case GLUT_KEY_RIGHT:
		keyRight = false;
		break;
	}

}
void Game_manager::keyPressed(unsigned char key, int x, int y)
{
	switch (key) {
	case 'a':
		_isWired == true ? _isWired = false : _isWired = true;
		break;
	case '1':
		camera_number = 1;
		break;
	case '2':
		camera_number = 2;
		_fullRoad->computeProjectionMatrix();
		break;
	case '3':
		camera_number = 3;
		_followCar->computeProjectionMatrix();
		break;

	case 'l':
		lightEnabled ? lightEnabled = false : lightEnabled = true;
		break;
	
	case 'n':
		globalOn ? globalOn = false : globalOn = true;
		break;


	case 'g':
		goroud ? goroud = false: goroud = true;
		break;

	case 'c':
		candlesOn ? candlesOn = false : candlesOn = true;
		break;
	default:
		std::cout << "Not supported" << std::endl;
		break;

	}

}

void Game_manager::onTimer()
{
}

void Game_manager::idle()
{
	
}

void Game_manager::update(double delta)
{
	if (keyUp) {
		_vrum->acelarate(ACELARATION_NUMBER);
	}

	if (keyDown) {
		_vrum->breakAcelaration(-ACELARATION_NUMBER);
	}
	if (keyLeft) {
		_vrum->turn(ANGLE_TURN);
	}
	if (keyRight) {
		_vrum->turn(-ANGLE_TURN);
	}

	for (std::vector<LightSource*>::iterator it = _candles.begin(); it != _candles.end(); ++it)
		(*it)->setState(candlesOn?true:false);

	if (globalOn)
		_globalLight->setState(true);
	else
		_globalLight->setState(false);
	if (lightEnabled)
		glEnable(GL_LIGHTING);
	else
		glDisable(GL_LIGHTING);
	if (goroud) {
		glShadeModel(GL_SMOOTH);
	}
	else
		glShadeModel(GL_FLAT);


	for (std::vector<GameObject*>::iterator it = _elements.begin(); it != _elements.end(); ++it) {
		/*for (std::vector<GameObject*>::iterator jt = it; jt != _elements.end(); ++jt) {
			std::cout << "for IT: " << (*it)->getPosition()->getX() << " " << (*it)->getPosition()->getY() << " RADIUS IT: " << (*it)->getHitBox()->getRadius() << " FOR JT:" << (*jt)->getPosition()->getX() << " " << (*jt)->getPosition()->getY() << " RADIUS JT: " << (*jt)->getHitBox()->getRadius() << std::endl;

			if ((*it)->checkHit(*jt) && (*it)!=(*jt)) {
			}
		}*/
		(*it)->update(delta);
	}
	for (std::vector<GameObject*>::iterator it = _elements.begin(); it != _elements.end(); ++it) {
		(*it)->checkHit(_vrum);


	}
}

void Game_manager::init()
{
}

void Game_manager::display() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	switch (camera_number) {
	case 1:
		_orthoCam->computeProjectionMatrix();
		break;
	case 2:
		_fullRoad->computeProjectionMatrix();
		glMatrixMode(GL_MODELVIEW);
		gluLookAt(0, -6, 10, 0, 0, 0, 0, 0, 1);
		break;
	case 3:
		_followCar->computeProjectionMatrix();
		glMatrixMode(GL_MODELVIEW);
		gluLookAt(_vrum->getPosition()->getX() + cos(_vrum->getAngle()*PI / 180) * -3, _vrum->getPosition()->getY() + sin(_vrum->getAngle()*PI / 180) * -3, _vrum->getPosition()->getZ()+2,
			_vrum->getPosition()->getX(), _vrum->getPosition()->getY(), _vrum->getPosition()->getZ(),
			0, 0,1);
		break;
	default:
		break;

	}
	glMatrixMode(GL_MODELVIEW);
	/*///////////////////////////////OBJECT DRAWING AREA\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\*/

	if (!_isWired) {
		glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
		}
	else {
		glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	}
	
	for (GameObject* go : _elements) {
		go->draw();
	}
	if (globalOn) _globalLight->draw();
	if (candlesOn) {
		for (LightSource* lh : _candles)
			lh->draw();
	}
	glFlush();
	glutPostRedisplay();
}

void Game_manager::reshape(GLsizei w, GLsizei h) {
	
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glViewport(VIEWPORT_X, VIEWPORT_Y, w, h);
	GLfloat ratio = GLfloat(w) / GLfloat(h);
	if (camera_number == 1) {
		if (w > h) {
			_orthoCam->setLeft(-WINDOW_SIZE*ratio);
			_orthoCam->setRight(WINDOW_SIZE*ratio);
			_orthoCam->setBottom(-WINDOW_SIZE);
			_orthoCam->setTop(WINDOW_SIZE);
			

		}
		else {
			_orthoCam->setLeft(-WINDOW_SIZE);
			_orthoCam->setRight(WINDOW_SIZE);
			_orthoCam->setBottom(-WINDOW_SIZE / ratio);
			_orthoCam->setTop(WINDOW_SIZE / ratio);
		}
	}
	else if(camera_number==2 || camera_number==3){
		camera_number == 2 ? _fullRoad->setAspect(ratio):_followCar->setAspect(ratio);

		
	}

	
	

	

}


void Game_manager::setTable(Table t) {
	_table = &t;
}
Table Game_manager::getTable() {
	return *_table;
}

bool Game_manager::isWired()
{
	return _isWired;
}
