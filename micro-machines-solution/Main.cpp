#include <iostream>
#include "GameManager.h"


Game_manager gm = Game_manager();

void display() {
	gm.display();

}

void reshape(GLsizei w,GLsizei h) {
	gm.reshape(w,h);

}

void keyPressed(int key,int x,int y) {
	std::cout << "yes" << std::endl;
	gm.keyPressed(key, x, y);

}

void update(int value) {
	gm.update(value);
	glutTimerFunc(10, update, 10);
}



int main(int argc, char** argv) {

	glutInit(&argc, argv);
	glLoadIdentity();
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(600, 600);
	glutInitWindowPosition(-1, -1);
	glutCreateWindow("Micro-machines");
	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	glutSpecialFunc(keyPressed);
	glutTimerFunc(10, update, 10);
	glutMainLoop();

	return 0;
}