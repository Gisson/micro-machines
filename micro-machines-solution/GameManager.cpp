#include <iostream>

#include "GameManager.h"


Game_manager::Game_manager() {
	for (int i = 0;i < 3;i++) {
		_mrOrange[i] = Orange();
	}
}





void Game_manager::keyPressed(unsigned char key, int x, int y)
{
	switch (key)
	{
	case GLUT_KEY_UP:
		//do something here
		_vrum.setAcelaration(0,2, 0);
		break;
	case GLUT_KEY_DOWN:
		_vrum.setAcelaration(0, -2, 0);
		break;
	case GLUT_KEY_LEFT:
		_vrum.setAcelaration(2, 0, 0);
		break;
	case GLUT_KEY_RIGHT:
		_vrum.setAcelaration(-2, 0, 0);
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
}

void Game_manager::init()
{
}

void Game_manager::display() {
	glPushMatrix();
	std::cout << "In display" << std::endl;
	glClear(GL_COLOR_BUFFER_BIT);
	int newTime=glutGet(GLUT_ELAPSED_TIME);
	int deltaT = newTime - oldTimeSinceStart;
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	/*///////////////////////////////OBJECT DRAWING AREA\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\*/
	_table.draw();
	for (int i = 0; i < 3; i++)
		_mrOrange[0].draw();
	_road.draw();
	_vrum.draw();
	
	_vrum.update(deltaT);
	oldTimeSinceStart = newTime;
	glPopMatrix();
	glFlush();
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