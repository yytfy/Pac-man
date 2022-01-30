#ifndef _GAME_
#define _GAME_
#include<gl/glut.h>
#include<gl/GL.h>
#include<string>
#include"map.h"
#include<ctime>
#include<vector>

using namespace std;

extern unsigned short gameState;
extern unsigned short mapLength;
extern unsigned short mapWidth;
extern unsigned short blockSize;
extern unsigned short winWidth;
extern unsigned short winHeight;

extern std::vector<bool> keyStates;

/*
*   Main Menu
*/
extern int mainMenuSelect;
extern std::vector<std::string> items;
/*
*	Game
*/
extern clock_t gameTime;
extern map* curMap;
extern pair<float, float> initPos;
extern unsigned short initLives;




#endif