#include <gl/glut.h>
#include"../include/control.h"
#include"../include/player.h"
#include"../include/gameplay.h"
#include<vector>
#include<string>


using namespace std;


/*
*	游戏状态
*	0 : 开始菜单
*	1 : 游戏开始
*	2 : 游戏暂停
*	3 : 游戏结束
*/
unsigned short gameState = 0;

vector<bool> keyStates(256,0);
/*
*	地图大小
*/
unsigned short mapLength = 21;
unsigned short mapWidth = 27;
/*
*	方块大小
*/
unsigned short blockSize = 50;
unsigned short winWidth = 750;
unsigned short winHeight = 750;


/*
*   Main Menu
*/
int mainMenuSelect = 0;
vector<string> items = {"Game Start", "Quit"};




int main(int argc, char** argv) {
    glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize(winWidth, winHeight);
	glutInitWindowPosition((glutGet(GLUT_SCREEN_WIDTH)-winWidth)/2,
							(glutGet(GLUT_SCREEN_HEIGHT)-winHeight)/2);
	glutCreateWindow("Pac-man");


	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	glutIdleFunc(display);
	glutKeyboardFunc(keyPressed);
	glutKeyboardUpFunc(keyUp);
    glutMainLoop();

	return 0;
}

