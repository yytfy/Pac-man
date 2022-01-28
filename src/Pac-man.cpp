#include <gl/glut.h>
#include"../include/control.h"
#include"../include/player.h"
#include"../include/gameplay.h"
#include"../include/map.h"
#include<vector>
#include<string>


using namespace std;

/*
*	窗口
*/
unsigned short winWidth = 1280;
unsigned short winHeight = 720;
/*
*	游戏状态
*	0 : 开始菜单
*	1 : 游戏开始
*	2 : 游戏暂停
*	3 : 游戏结束
*	4 : 游戏退出
*/
unsigned short gameState = 0;
/*
*	键盘状态	
*/
vector<bool> keyStates(256,0);
/*
*	地图
*/
unsigned short mapLength = 27;
unsigned short mapWidth = 21;
unsigned short blockSize = 25;


/*
*   Main Menu
*/
int mainMenuSelect = 0;
vector<string> items = {"Game Start", "Quit"};
/*
*	Game
*/
map* curMap;



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
	glutSetKeyRepeat(GLUT_KEY_REPEAT_OFF);
	glutKeyboardFunc(keyPressed);
	glutKeyboardUpFunc(keyUp);
    glutMainLoop();

	return 0;
}

