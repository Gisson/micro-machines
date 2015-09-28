#include <GL/glut.h>

void myReshape(GLsizei w, GLsizei h) {
	glViewport(0, 0, w, h);
	GLfloat ratio = GLfloat(w) / GLfloat(h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	if (w > h) {
		glOrtho(-2.0f*ratio, 2.0f*ratio, -2.0f, 2.0f, -2.0f, 2.0f);

	}
	else {
		glOrtho(-2.0f, 2.0f, -2.0f/ratio, 2.0f/ratio, -2.0f, 2.0f);
	}
	
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

void myDisplay(void) {
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0.0f, 0.0f, 1.0f);
	glBegin(GL_POLYGON);
	glutSolidCube(1);
	glEnd();
	glFlush();
}

void main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(400, 400);
	glutInitWindowPosition(-1, -1);
	glutCreateWindow("Micromachines");
	glutDisplayFunc(myDisplay);
	glutReshapeFunc(myReshape);
	glutMainLoop();
}