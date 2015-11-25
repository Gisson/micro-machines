#include <iostream>
#include "GameManager.h"
void display();
void reshape(GLsizei w, GLsizei h);
void specialKeyPressed(int key, int x, int y);
void keyPressed(unsigned char key, int x, int y);
void update(int value);
void specialUp(int key, int x, int y);
void init();
void restart();


Game_manager* gm =new Game_manager();

void display() {

	if (gm->dead) {

		glPushMatrix();
		glDisable(GL_LIGHTING);
		glEnable(GL_TEXTURE_2D);
		glMatrixMode(GL_PROJECTION);
		glLoadIdentity();
		glOrtho(-5, 5, -5, 5, -5, 5);
		glBindTexture(GL_TEXTURE_2D, gm->getEndGameTexture()->getTexture());

		glColor3f(1, 1, 1);
		glMatrixMode(GL_MODELVIEW);
		glPushMatrix();
		glLoadIdentity();
		glBegin(GL_POLYGON);
		glNormal3f(0, 0, 1);
		glTexCoord2f(1.0f, 1.0f);
		glVertex3f(4.0, 4.0, 5.0);
		glTexCoord2f(1.0f, 0.0f);
		glVertex3f(4.0, -4.0, 5.0);
		glTexCoord2f(0.0f, 0.0f);
		glVertex3f(-4.0, -4.0, 5.0);
		glTexCoord2f(0.0f, 1.0f);
		glVertex3f(-4.0f, 4.0, 5.0);
		glEnd();
		
		glDisable(GL_TEXTURE_2D);
		glEnable(GL_LIGHTING);
		glPopMatrix();
		glMatrixMode(GL_PROJECTION);
		glPopMatrix();
		glFinish();
		glutPostRedisplay();
		return;
	}
	gm->display();

}

void reshape(GLsizei w,GLsizei h) {
	gm->reshape(w,h);

}

void specialKeyPressed(int key,int x,int y) {
	//std::cout << "yes" << std::endl;
	gm->specialKeyPressed(key, x, y);
}

void keyPressed(unsigned char key, int x, int y) {
	if (gm->dead && key == 'r') {
		restart(); glutPostRedisplay();
	}
	gm->keyPressed(key,x,y);
}

void update(int value) {
	if (gm->dead) return;
	gm->update(value);
	glutTimerFunc(10, update, 10);
}

void specialUp(int key, int x, int y) {
	gm->specialKeyUp(key,x,y);
}

void init() {
	gm->init();
}
void restart() {
	glFinish();
	gm->clearGM();
	free(gm);
	gm = new Game_manager();
	gm->init();
	update(10);
	
}

int main(int argc, char** argv) {
	
	glutInit(&argc, argv);
	glLoadIdentity();
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(600, 600);
	glutInitWindowPosition(-1, -1);
	
	glutCreateWindow("Micro-machines");
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_NORMALIZE);
	glEnable(GL_TEXTURE_2D);
	gm->init();

	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	glutSpecialUpFunc(specialUp);
	glutSpecialFunc(specialKeyPressed);
	glutKeyboardFunc(keyPressed);
	glutTimerFunc(10, update, 10);
	glutMainLoop();


	return 0;
}
