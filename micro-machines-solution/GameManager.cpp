#include <iostream>

#include "GameManager.h"


Game_manager::Game_manager() {
	for (int i = 0;i < 3;i++) {
		_mrOrange[i] = Orange();
	}
}





void Game_manager::keyPressed(int key, int x, int y)
{
	std::cout << "Inside"<< std::endl;
	switch (key)
	{
	case GLUT_KEY_UP:
		//do something here
		_vrum.setAcelaration(0.008);
		break;
	case GLUT_KEY_DOWN:
		_vrum.setAcelaration(-0.008);
		break;
	case GLUT_KEY_LEFT:
		_vrum.setAcelaration(0.008);
		break;
	case GLUT_KEY_RIGHT:
		_vrum.setAcelaration(-0.008);
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
	glClear(GL_COLOR_BUFFER_BIT);
	double newTime=glutGet(GLUT_ELAPSED_TIME);
	double deltaT = (newTime - oldTimeSinceStart) / 1000;
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	_vrum.update(1);
	/*///////////////////////////////OBJECT DRAWING AREA\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\*/
	_table.draw();
	for (int i = 0; i < 3; i++)
		_mrOrange[i].draw();
	_road.draw();
	_vrum.draw();
	
	_vrum.update(deltaT);
	oldTimeSinceStart = newTime;
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