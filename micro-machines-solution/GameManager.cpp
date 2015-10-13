#include <iostream>

#include "GameManager.h"


Game_manager::Game_manager() {
	srand(time(NULL));
	for (int i = 0;i < 3;i++) {
		_mrOrange[i] = Orange();
	}
	for (int j = 0; j < 5; j++) {
		_mrButter[j] = Butter();
	}
}


void Game_manager::keyPressed(int key, int x, int y)
{
	switch (key)
	{
	case GLUT_KEY_UP:
		//do something here
		_vrum.acelarate(5);
		break;
	case GLUT_KEY_DOWN:
		_vrum.breakAcelaration(-5);
		break;
	case GLUT_KEY_LEFT:
		_vrum.turnLeft(5);
		break;
	case GLUT_KEY_RIGHT:
		_vrum.turnRight(5);
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
	_vrum.update(delta);
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
	_table.draw();
	for (int i = 0; i < 3; i++)
		_mrOrange[i].draw();
	for (int j = 0; j < 5; j++)
		_mrButter[j].draw();
	_road.draw();
	_vrum.draw();
	
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
	_table = t;
}
Table Game_manager::getTable() {
	return _table;
}