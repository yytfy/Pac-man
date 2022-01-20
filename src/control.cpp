#include "../include/control.h"
#include"../include/game.h"
#include<iostream>

void keyPressed(unsigned char key, int x, int y) {
    keyStates[key] = true;

}

void keyUp(unsigned char key, int x, int y){
    keyStates[key] = false;
}