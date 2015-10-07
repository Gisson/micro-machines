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
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);

	glPushMatrix();
	//glScalef(2.0, 1.0, 1.0);
	//glRotatef(0, 1, 0, 0);
	_table.draw();
	

	glPopMatrix();
	glFlush();
	/*glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0f, 1.0f, 1.0f);
	glBegin(GL_POLYGON);
	glVertex3f(-1.0f, -1.0f, 0.0f);
	glVertex3f(1.0f, -1.0f, 0.0f);
	glVertex3f(1.0f, 1.0f, 0.0f);
	glVertex3f(-1.0f, 1.0f, 0.0f);
	glEnd();
	glFlush();*/

}

void Game_manager::reshape(GLsizei w, GLsizei h) {

	glViewport(0, 0, w, h);
	GLfloat ratio = GLfloat(w) / GLfloat(h);


	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	if (w > h) {
		glOrtho(-2.0f*ratio, 2.0f*ratio, -2.0f, 2.0f, -2.0f, 2.0f);

	}
	else {
		glOrtho(-2.0f, 2.0f, -2.0f / ratio, 2.0f / ratio, -2.0f, 2.0f);
	}

	glMatrixMode(GL_MODELVIEW);

}


void Game_manager::setTable(Table t) {
	_table = t;
}
Table Game_manager::getTable() {
	return _table;
}