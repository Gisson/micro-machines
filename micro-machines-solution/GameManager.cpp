#include <iostream>

#include "GameManager.h"


Game_manager::Game_manager() {
	srand(time(NULL));
	_orthoCam = new OrthogonalCamera(-WINDOW_SIZE, WINDOW_SIZE, -WINDOW_SIZE, WINDOW_SIZE, -WINDOW_SIZE, WINDOW_SIZE);
	_elements = std::vector<GameObject*>();
	_table = new Table();
	_elements.push_back(_table);
	_road = new Roadside();
	_elements.push_back(_road);
	for (int i = 0;i < 20;i++) {
		_elements.push_back(new Orange());
	}
	for (int i = 0; i < 5; i++) {
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
		_vrum->acelarate(ACELARATION_NUMBER);
		break;
	case GLUT_KEY_DOWN:
		_vrum->breakAcelaration(-ACELARATION_NUMBER);
		break;
	case GLUT_KEY_LEFT:
		_vrum->turn(ANGLE_TURN);
		break;
	case GLUT_KEY_RIGHT:
		_vrum->turn(-ANGLE_TURN);
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
		break;
	case '3':
		camera_number = 3;
		break;

	default:
		std::cout << "Not supported" << std::endl;
		break;

	}
	glutPostRedisplay();

}

void Game_manager::onTimer()
{
}

void Game_manager::idle()
{
	
}

void Game_manager::update(double delta)
{
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
	glClear(GL_COLOR_BUFFER_BIT);
	glClear(GL_DEPTH_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
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
			_orthoCam->computeProjectionMatrix();

		}
		else {
			_orthoCam->setLeft(-WINDOW_SIZE);
			_orthoCam->setRight(WINDOW_SIZE);
			_orthoCam->setBottom(-WINDOW_SIZE / ratio);
			_orthoCam->setTop(WINDOW_SIZE / ratio);
			_orthoCam->computeVisualizationMatrix();
			_orthoCam->computeProjectionMatrix();
		}
	}
	else if(camera_number==2){
		gluPerspective(45, ratio, -5, 5);
		gluLookAt(1, -1, 6, 0, 0, 0, 0, 0, 1);
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
