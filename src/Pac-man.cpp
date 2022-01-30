#include <gl/glut.h>
#include"../include/control.h"
#include"../include/player.h"
#include"../include/gameplay.h"
#include"../include/map.h"
#include<vector>
#include<string>


using namespace std;

/*
*	window size
*/
unsigned short winWidth = 1280;
unsigned short winHeight = 720;
/*
*	game state
*	0 : main menu
*	1 : game running
*	2 : game pause
*	3 : game over
*	4 : exit
*/
unsigned short gameState = 0;
/*
*	key state	
*/
vector<bool> keyStates(256,0);
/*
*	map
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
clock_t gameTime = 0;
map* curMap;
pair<float, float> initPos = {20.5, 10.5};
unsigned short initLives = 3;


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

