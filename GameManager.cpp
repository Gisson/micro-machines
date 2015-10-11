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
	
	_road.draw();

	

	glPopMatrix();
	glFlush();
}

void Game_manager::reshape(GLsizei w, GLsizei h) {
	glPushMatrix();
	glMatrixMode(GL_PROJECTION);
	glViewport(0, 0, w, h);
	GLfloat ratio = GLfloat(w) / GLfloat(h);
	glLoadIdentity();
	if (w > h) {
		glOrtho(-5.0f*ratio, 5.0f*ratio, -5.0f, 5.0f, -5.0f, 5.0f);

	}
	else {
		glOrtho(-5.0f, 5.0f, -5.0f / ratio, 5.0f / ratio, -5.0f, 5.0f);
	}

	
	glPopMatrix();

}


void Game_manager::setTable(Table t) {
	_table = t;
}
Table Game_manager::getTable() {
	return _table;
}