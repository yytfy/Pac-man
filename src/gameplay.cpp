#include"../include/game.h"
#include"../include/display.h"
#include"../include/gameplay.h"





void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    if(gameState == 0) {
        // 主菜单
        mainMenu();
        mainMenuDisplay();

    }else if(gameState == 1) {
        // 游戏进行或暂停
        game();
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
	glOrtho(0, winWidth, winHeight, 0, -1.0, 1.0);
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
        }
        else if(mainMenuSelect = 1) gameState = 4;

    }
}

void initGame(){
    if(curMap != nullptr) delete curMap;
    curMap = new map(mapLength, mapWidth, blockSize);

}

void game() {


}

