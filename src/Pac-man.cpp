
#define GLUT_DISABLE_ATEXIT_HACK
#define _STDCALL_SUPPORTED
#include"gl/glut.h"
#include<stdio.h>
#include<windows.h>


using namespace std;


int main(int argc, char** argv) {
    glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);//显示方式(双缓重区，深度缓冲)
	glutInitWindowSize(750, 750);//窗口大小
	glutInitWindowPosition(500, 50);//窗口起始位置
	glutCreateWindow("Pacman - by shiyanlou");

    glutMainLoop();
}

