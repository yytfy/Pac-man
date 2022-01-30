#ifndef _GAMEPLAY_
#define _GAMEPLAY_
#include<ctime>

extern int mainMenuSelect;

void display();
void reshape(int w, int h);

void mainMenu();
void initGame();
void game(double t);
void playerControl(double t);

#endif