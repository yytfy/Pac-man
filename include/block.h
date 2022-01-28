#ifndef _BLOCK_
#define _BLOCK_
#include"food.h"
#include <windows.h>
#include<gl/GL.h>


class block{
public:
    block(int size) : bs(size), reachable(true) {}
    block(bool reach, int size) : bs(size), reachable(reach) {}
    bool reach() const { return reachable; }
    void setReach(bool r) { reachable = r; }
    void draw(int, int);

private:
    int bs;
    bool reachable;
    food* f;

};
#endif