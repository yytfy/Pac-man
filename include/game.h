#ifndef _GAME_
#define _GAME_
#include<gl/glut.h>
#include<gl/GL.h>
#include<string>
#include"map.h"

#include<vector>


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
extern map* curMap;




#endif