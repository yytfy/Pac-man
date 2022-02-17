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

    void draw();
    
    std::pair<float, float> pos;
    float speed;
    /*
    *   move direction:
    *   2  left;
    *   0  right;
    *   -1  top;
    *   1  buttom;
    *   init rotation : 0
    */
    float rotation;
    short lives;

private:
    
    /*
    *   position
    */
    


};
#endif