#include <iostream>
#include "GameManager.h"


Game_manager gm = Game_manager();

void display() {
	gm.display();

}

void reshape(GLsizei w,GLsizei h) {
	gm.reshape(w,h);

}

void keyPressed(unsigned char key,int x,int y) {


}





int main(int argc, char** argv) {
	srand(time(NULL));
	glutInit(&argc, argv);
	glLoadIdentity();
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(600, 600);
	glutInitWindowPosition(-1, -1);
	glutCreateWindow("Micro-machines");
	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	glutKeyboardFunc(keyPressed);
	glutMainLoop();

	return 0;
}