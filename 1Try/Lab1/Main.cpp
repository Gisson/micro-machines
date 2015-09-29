#include <iostream>
#include "GameManager.h"


void reshapeWindow(GLsizei w, GLsizei h) {
	glPushMatrix();
	glViewport(0, 0, w, h);
	GLfloat ratio = GLfloat(w) / GLfloat(h);
	
	
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	if (w > h) {
		glOrtho(-2.0f*ratio, 2.0f*ratio, -2.0f, 2.0f, -2.0f, 2.0f);

	}
	else {
		glOrtho(-2.0f, 2.0f, -2.0f/ratio, 2.0f / ratio, -2.0f, 2.0f);
	}

	glMatrixMode(GL_MODELVIEW);
	glPopMatrix();

}

void displayWindow() {
	std::cout <<"O Peter e gay mesmo!"<< std::endl;
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0.0f, 0.0f, 1.0f);
	glLoadIdentity();
	glRotatef (45, 10, 10, 20);
	glutSolidCube(1);
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



int main(int argc, char** argv) {
	

	glutInit(&argc, argv);
	glLoadIdentity();
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(600, 600);
	glutInitWindowPosition(1, 1);
	glutCreateWindow("Peter gay");
	glutDisplayFunc(displayWindow);
	glutReshapeFunc(reshapeWindow);
	glutMainLoop();

	return 0;
}