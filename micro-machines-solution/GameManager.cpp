#include <iostream>

#include "GameManager.h"


Game_manager::Game_manager() {
	srand(time(NULL));

	//Initializing cameras

	_orthoCam = new OrthogonalCamera(-WINDOW_SIZE, WINDOW_SIZE, -WINDOW_SIZE, WINDOW_SIZE, -WINDOW_SIZE, WINDOW_SIZE);
	_fullRoad = new SeeFullRoadCamera(FOVY,1,-3,3);
	_followCar = new FollowCarCamera(FOVY, 1, -3, 3);

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
	_vrum = new Car();
	_elements.push_back(_vrum);
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
	for (GameObject* go : _elements) {
		go->update(delta);
	}

	glutPostRedisplay();
}

void Game_manager::init()
{
}

void Game_manager::display() {
	glPushMatrix();
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	switch (camera_number) {
	case 1:
		_orthoCam->computeProjectionMatrix();
		break;
	case 2:
		_fullRoad->computeProjectionMatrix();
		gluLookAt(0, -6, 10, 0, 0, 0, 0, 0, 1);
		break;
	case 3:
		_followCar->computeProjectionMatrix();
		gluLookAt(_vrum->getPosition()->getX() + cos(_vrum->getAngle()*PI / 180) * -3, _vrum->getPosition()->getY() + sin(_vrum->getAngle()*PI / 180) * -3, _vrum->getPosition()->getZ()+3,
			_vrum->getPosition()->getX(), _vrum->getPosition()->getY(), _vrum->getPosition()->getZ(),
			0, 0,1);
		break;
	default:
		break;

	}
	glMatrixMode(GL_MODELVIEW);
	glPopMatrix();
	glLoadIdentity();
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
	glPopMatrix();
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
