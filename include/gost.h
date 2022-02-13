#ifndef _gost_
#define _gost_
#include<utility>
#include <windows.h>
#include<gl/GL.h>
#define _USE_MATH_DEFINES
#include<math.h>

using namespace std;

class gost{
public:
    gost(pair<float, float> p, pair<USHORT, USHORT> t, float spd, USHORT n) : pos(p), rotation(0), speed(spd), No(n), targetPos(t) { }

    void draw();
    
    pair<float, float> pos;
    float speed;
    /*
        -1 : top
        0  : right
        1  : bottom
        2  : left
    */
    float rotation;
    pair<USHORT, USHORT> targetPos;
private:
    
    USHORT No;

};
#endif