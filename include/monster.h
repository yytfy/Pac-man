#ifndef _MONSTER_
#define _MONSTER_
#include<utility>
#include <windows.h>
#include<gl/GL.h>
#define _USE_MATH_DEFINES
#include<math.h>

using namespace std;

class monster{
public:
    monster(pair<float, float> p, float spd, USHORT n) : pos(p), rotation(0), speed(spd), No(n) { }

    void setRotation(float r) { rotation = r; }
    void draw();
    
    pair<float, float> pos;
    float speed;

private:
    float rotation;
    USHORT No;

};
#endif