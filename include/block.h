#ifndef _BLOCK_
#define _BLOCK_
#include"food.h"
#include <windows.h>
#include<gl/GL.h>


class block{
public:
    block(int size) : bs(size), reachable(true), f(nullptr) {}
    block(bool reach, int size) : bs(size), reachable(reach), f(nullptr) {}
    bool reach() const { return reachable; }
    void setReach(bool r) { reachable = r; }
    food* getFood() { return f; }
    void setFood(food* ff) { f = ff;}
    USHORT getSize() { return bs; }
    void draw(int, int);

private:
    USHORT bs;
    bool reachable;
    food* f;

};
#endif