#include"../include/game.h"
#include"../include/display.h"
#include"../include/gameplay.h"
#include<iostream>

using namespace std;


void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    if(gameState == 0) {
        // 主菜单
        mainMenu();
        mainMenuDisplay();

    }else if(gameState == 1) {
        // 游戏进行或暂停
        clock_t now = clock();
        double diff = (double)(now - gameTime) / CLOCKS_PER_SEC;
        game(diff);
        gameTime = now;
        gameDisplay();
    }else if(gameState == 3) {
        // 游戏结束

    }else {
        //游戏退出
        exit(0);
    }

    
    glutSwapBuffers();
}


void reshape(int w, int h) {
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glViewport(0, 0, (GLsizei)w, (GLsizei)h);
    gluOrtho2D(0, winWidth, winHeight, 0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

void mainMenu() {
    if(keyStates['w'] && mainMenuSelect > 0) mainMenuSelect--;
    if(keyStates['s'] && mainMenuSelect < items.size()-1) mainMenuSelect++;
    if(keyStates['\r']) {
        if(mainMenuSelect == 0) {
            initGame();
            gameState = 1;
            gameTime = clock();
        }
        else if(mainMenuSelect = 1) gameState = 4;

    }
}

void initGame(){
    if(curMap != nullptr) delete curMap;
    curMap = new map(mapLength, mapWidth, blockSize, initPos, initLives);

}

void game(double t) {
    playerControl(t);
    


}

void playerControl(double t) {
    int x = curMap->player->pos.first / 25 - 1, y = curMap->player->pos.second / 25 - 10;
    float rx = (1.5 + x) * 25, ry = (10.5 + y) * 25;
    if(keyStates['w'] && curMap->player->pos.second > (ry -8) && curMap->player->pos.second < (ry + 8)) {
        curMap->player->pos.second = ry;
        curMap->player->pos.first -= t * curMap->player->speed;
        if(!curMap->reach(x-1, y) && curMap->player->pos.first < (1.5 + x) * 25) {
            curMap->player->pos.first = (1.5 + x) * 25;
        }
        curMap->player->setRotation(-1);
    }
    else if(keyStates['s'] && curMap->player->pos.second > (ry -8) && curMap->player->pos.second < (ry + 8)) {
        curMap->player->pos.second = ry;
        curMap->player->pos.first += t * curMap->player->speed;
        if(!curMap->reach(x+1, y) && curMap->player->pos.first > (1.5 + x) * 25) {
            curMap->player->pos.first = (1.5 + x) * 25;
        }
        curMap->player->setRotation(1);
    }
    else if(keyStates['a'] && curMap->player->pos.first > (rx -8) && curMap->player->pos.first < (rx + 8)) {
        curMap->player->pos.first = rx;
        curMap->player->pos.second -= t * curMap->player->speed;
        if(curMap->player->pos.second < 10 * blockSize) curMap->player->pos.second += mapWidth * blockSize;
        if(!curMap->reach(x, (y-1 + mapWidth) % mapWidth) && curMap->player->pos.second < (10.5 + y) * 25) {
            curMap->player->pos.second = (10.5 + y) * 25;
        }
        curMap->player->setRotation(2);
    }
    else if(keyStates['d'] && curMap->player->pos.first > (rx -8) && curMap->player->pos.first < (rx + 8)) {
        curMap->player->pos.first = rx;
        curMap->player->pos.second += t * curMap->player->speed;
        if(curMap->player->pos.second > (10 + mapWidth) * blockSize) curMap->player->pos.second -= mapWidth * blockSize;
        if(!curMap->reach(x, (y+1 + mapWidth) % mapWidth) && curMap->player->pos.second > (10.5 + y) * 25) {
            curMap->player->pos.second = (10.5 + y) * 25;
        }
        curMap->player->setRotation(0);
    }
}



