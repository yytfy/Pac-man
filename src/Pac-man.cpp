#include <gl/glut.h>
#include"../include/control.h"


using namespace std;

int winWidth = 750;
int winHeight = 750;

void renderSense(void) {
	glClear(GL_COLOR_BUFFER_BIT);
	glBegin(GL_TRIANGLES);
	glVertex3f(-0.5, -0.5, 0.0);
	glVertex3f(0.5, 0.0, 0.0);
	glVertex3f(0.0, 0.5, 0.0);
	glEnd();
	glFlush();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize(winWidth, winHeight);
	glutInitWindowPosition((glutGet(GLUT_SCREEN_WIDTH)-winWidth)/2,
							(glutGet(GLUT_SCREEN_HEIGHT)-winHeight)/2);
	glutCreateWindow("Pac-man");

	//glutDisplayFunc(renderSense);
	glutKeyboardFunc(keyPressed);
	glutKeyboardUpFunc(keyUp);
	
    glutMainLoop();

	return 0;
}

