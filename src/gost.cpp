#include"../include/gost.h"

void gost::draw() {
    int x, y;
	glBegin(GL_LINES);
    if(No == 0) glColor3f(0.545, 0.0, 0.0);
	else if(No == 1) glColor3f(0.968, 0.811, 0.952);
	else if(No == 2) glColor3f(0.117, 0.447, 1);
	else if(No == 3) glColor3f(0.627, 0.321, 0.176);
    else glColor3f(0.7, 0.0, 0.0);
	
	//头
	for (int k = 0; k < 32; k++){
		x = (float)k / 2.0 * cos(360 * M_PI / 180.0) + pos.second;
		y = (float)k / 2.0* sin(360 * M_PI / 180.0) + pos.first;
		for (int i = 180; i <= 360; i++){
			glVertex2f(x, y);
			x = (float)k / 2.0 * cos(i * M_PI / 180.0) + pos.second;
			y = (float)k / 2.0* sin(i * M_PI / 180.0) + pos.first;
			glVertex2f(x, y);
		}
	}
	glEnd();
	//身体
	glRectf(pos.second - 17, pos.first, pos.second + 15, pos.first + 15);
	//眼睛和退
	glColor3f(0, 0.0, 0.0);
	glPointSize(8.0);
	glBegin(GL_POINTS);
	glVertex2f(pos.second + 4, pos.first - 3); //eyes
	glVertex2f(pos.second - 7, pos.first - 3); //eyes 
	glEnd();

	glColor3f(0, 0.0, 0.0);
	glPointSize(5.0);
	glBegin(GL_POINTS);
    glVertex2f(pos.second - 11, pos.first + 14); //legs
	glVertex2f(pos.second - 1, pos.first + 14); //legs
	glVertex2f(pos.second + 8, pos.first + 14); //legs
	glEnd();

	

}



