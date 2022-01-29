#ifndef _PCAMAN_
#define _PCAMAN_
#include<utility>

using namespace std;

class pca_man{
public:

    pca_man(pair<float, float> p, unsigned short l) : pos(p), lives(l), rotation(0) { }


    void draw();
    void setRotation(float r) { rotation = r; }


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
    std::pair<float, float> pos;
    float speed;
    unsigned short lives;


};
#endif