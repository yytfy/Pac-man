#ifndef _PCAMAN_
#define _PCAMAN_
#include<utility>
#include <windows.h>
#include<gl/GL.h>
#define _USE_MATH_DEFINES
#include<math.h>

using namespace std;

extern float initSpeed;

class pca_man{
public:

    pca_man(pair<float, float> p, unsigned short l) : pos(p), lives(l), rotation(0), speed(initSpeed) { }

    void setRotation(float r) { rotation = r; }
    void draw();
    
    std::pair<float, float> pos;
    float speed;

private:
    /*
    *   move direction:
    *   -1 为初始状态原地不动;
    *   0  left;
    *   1  right;
    *   2  top;
    *   3  buttom;
    */
    float rotation;
    /*
    *   position
    */
    
    unsigned short lives;


};
#endif