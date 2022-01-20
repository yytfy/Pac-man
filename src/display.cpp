#include"../include/game.h"
#include<utility>
#define _USE_MATH_DEFINES
#include<math.h>
#include <iterator>

using namespace std;

void mainMenuDisplay() {
    glClearColor(0, 0, 0, 1.0);
    string message = "Pac-man";
	auto it = message.begin();
    glColor3f(1.0f, 1.0f, 1.0f);
    glRasterPos2f(340, 200);
    while (it!=message.end()) glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, *it++);
    for(int i=0; i<items.size(); ++i) {
        if(i == mainMenuSelect) {
            glColor3f(1.0f, 0.0f, 0.0f);
        }else {
            glColor3f(1.0f, 1.0f, 1.0f);
        }
        
        glRasterPos2f(340, 300+i*50);
        message = items[i];
        it = message.begin();
        while (it!=message.end()) glutBitmapCharacter(GLUT_BITMAP_9_BY_15, *it++);
    }
}


void temp(){

    // float rotation = 0;
	// pair<float, float> pos = {1.5, 1.5};
	// int x, y;
    // glBegin(GL_LINES);
    // glColor3f(1.0, 1.0, 0.0);
    // for (int k = 0; k < 32; k++){
	// 	x = (float)k / 2.0 * cos((30 + 90 * rotation) * M_PI / 180.0) + (pos.first * 50);
	// 	y = (float)k / 2.0* sin((30 + 90 * rotation) * M_PI / 180.0) + (pos.second * 50);
	// 	for (int i = 30; i < 330; i++){
	// 		glVertex2f(x, y);
	// 		x = (float)k / 2.0 * cos((i + 90 * rotation) * M_PI / 180.0) + (pos.first * 50);
	// 		y = (float)k / 2.0* sin((i + 90 * rotation) * M_PI / 180.0) + (pos.second * 50);
	// 		glVertex2f(x, y);
	// 	}
	// }
    // glEnd();
}