#include <iostream>
#include "GameManager.h"


Game_manager gm = Game_manager();

void display() {
	gm.display();

}

void reshape(GLsizei w,GLsizei h) {
	gm.reshape(w,h);

}






int main(int argc, char** argv) {
	
	

	glutInit(&argc, argv);
	glLoadIdentity();
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(600, 600);
	glutInitWindowPosition(1, 1);
	glutCreateWindow("Micro-machines");
	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	glutMainLoop();

	return 0;
}