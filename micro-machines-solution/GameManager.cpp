#include <iostream>

#include "GameManager.h"


Game_manager::Game_manager() {
	srand(time(NULL));
	
	_elements = std::vector<GameObject*>();
	_table = new Table();
	_elements.push_back(_table);
	_road = new Roadside();
	_elements.push_back(_road);
	for (int i = 0;i < 3;i++) {
		_mrOrange[i] = new Orange();
		_elements.push_back(_mrOrange[i]);
	}
	for (int i = 0; i < 5; i++) {
		_mrButter[i] = new Butter();
		_elements.push_back(_mrButter[i]);
	}
	_vrum = new Car();
	_elements.push_back(_vrum);
}


void Game_manager::specialKeyPressed(int key, int x, int y)
{
	switch (key)
	{
	case GLUT_KEY_UP:
		_vrum->acelarate(4);
		break;
	case GLUT_KEY_DOWN:
		_vrum->breakAcelaration(-4);
		break;
	case GLUT_KEY_LEFT:
		_vrum->turn(5);
		break;
	case GLUT_KEY_RIGHT:
		_vrum->turn(-5);
		break;
	}
}
void Game_manager::keyPressed(unsigned char key, int x, int y)
{
	switch (key) {
	case 'a':
		_isWired == true ? _isWired = false : _isWired = true;
		break;
	default:
		//std::cout << "Not supported" << std::endl;
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
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	/*///////////////////////////////OBJECT DRAWING AREA\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\*/

	if (!_isWired) {
		for (GameObject* go : _elements) {
			go->draw();
		}
		/*_table.draw();
		for (int i = 0; i < 3; i++)
			_mrOrange[i].draw();
		for (int j = 0; j < 5; j++)
			_mrButter[j].draw();
		_road.draw();
		_vrum.draw();*/
	}else {
		for (GameObject *go : _elements)
			go->draw(_isWired);
		/*_table.draw();
		for (int i = 0; i < 3; i++)
			_mrOrange[i].draw(_isWired);
		for (int j = 0; j < 5; j++)
			_mrButter[j].draw(_isWired);
		_road.draw(_isWired);
		_vrum.draw(_isWired);*/
	}

	glPopMatrix();
	glFlush();
	glutPostRedisplay();
}

void Game_manager::reshape(GLsizei w, GLsizei h) {
	
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glViewport(0, 0, w, h);
	GLfloat ratio = GLfloat(w) / GLfloat(h);
	if (w > h) {
		glOrtho(-5.0f*ratio, 5.0f*ratio, -5.0f, 5.0f, -5.0f, 5.0f);

	}
	else {
		glOrtho(-5.0f, 5.0f, -5.0f / ratio, 5.0f / ratio, -5.0f, 5.0f);
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
