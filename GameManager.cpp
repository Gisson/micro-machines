#include "GameManager.h";


Game_manager::Game_manager() {


}





void Game_manager::keyPressed()
{
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
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	/*///////////////////////////////OBJECT DRAWING AREA\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\*/
	_table.draw();

	glPopMatrix();
	glFlush();
}

void Game_manager::reshape(GLsizei w, GLsizei h) {
	glPushMatrix();
	glViewport(0, 0, w, h);
	GLfloat ratio = GLfloat(w) / GLfloat(h);


	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	if (w > h) {
		glOrtho(-4.0f*ratio, 4.0f*ratio, -4.0f, 4.0f, -4.0f, 4.0f);

	}
	else {
		glOrtho(-4.0f, 4.0f, -4.0f / ratio, 4.0f / ratio, -4.0f, 4.0f);
	}

	glMatrixMode(GL_MODELVIEW);
	glPopMatrix();
}


void Game_manager::setTable(Table t) {
	_table = t;
}
Table Game_manager::getTable() {
	return _table;
}