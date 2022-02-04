#include"../include/food.h"

food::food(USHORT t) : type(t) {
    if(type == 1) point = 10;
    else if(type == 2) point = 50;
    else point = 0;
}

void food::draw(int x, int y, USHORT blockSize) {
    if(type == 1) glPointSize(5.0);
    else if(type == 2) glPointSize(10.0);
    else glPointSize(0.0);

	glBegin(GL_POINTS);
	glColor3f(1.0, 0.5, 0.0);
	glVertex2f((x+0.5)*blockSize, (y+0.5)*blockSize);
	glEnd();


}

