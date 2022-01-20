#include"../include/game.h"
#include"../include/display.h"





void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    if(gameState == 0) {
        // 主菜单
        mainMenu();
        mainMenuDisplay();

    }else if(gameState == 3) {
        // 游戏结束


    }else{
        // 游戏进行或暂停

    }



    
    glutSwapBuffers();
}


void reshape(int w, int h) {
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glViewport(0, 0, (GLsizei)w, (GLsizei)h);
	glOrtho(0, 750, 750, 0, -1.0, 1.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

void mainMenu() {
    if(keyStates['w'] && mainMenuSelect > 0) mainMenuSelect--;
    if(keyStates['s'] && mainMenuSelect < items.size()-1) mainMenuSelect++;

}

