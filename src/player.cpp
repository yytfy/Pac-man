#include"../include/player.h"
#include <windows.h>
#include<gl/GL.h>
#define _USE_MATH_DEFINES
#include<math.h>


void pca_man::draw(){
    int x, y;
    glBegin(GL_LINES);
    glColor3f(1.0, 1.0, 0.0);
    for (int k = 0; k < 32; k++){
		x = (float)k / 2.0 * cos((30 + 90 * rotation) * M_PI / 180.0) + (pos.first * 50);
		y = (float)k / 2.0* sin((30 + 90 * rotation) * M_PI / 180.0) + (pos.second * 50);
		for (int i = 30; i < 330; i++){
			glVertex2f(x, y);
			x = (float)k / 2.0 * cos((i + 90 * rotation) * M_PI / 180.0) + (pos.first * 50);
			y = (float)k / 2.0* sin((i + 90 * rotation) * M_PI / 180.0) + (pos.second * 50);
			glVertex2f(x, y);
		}
	}
    glEnd();
}

