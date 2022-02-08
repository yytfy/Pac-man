#include"../include/player.h"


float initSpeed = 125;

void pca_man::draw(){
    float x, y;
    glBegin(GL_LINES);
    glColor3f(1.0, 0.5, 0.0);
    for (int k = 0; k < 32; k++){
		x = (float)k / 2.0 * cos((30 + 90 * rotation) * M_PI / 180.0) + pos.second;
		y = (float)k / 2.0* sin((30 + 90 * rotation) * M_PI / 180.0) + pos.first;
		for (int i = 30; i < 330; i++){
			glVertex2f(x, y);
			x = (float)k / 2.0 * cos((i + 90 * rotation) * M_PI / 180.0) + pos.second;
			y = (float)k / 2.0* sin((i + 90 * rotation) * M_PI / 180.0) + pos.first;
			glVertex2f(x, y);
		}
	}
    glEnd();
}

