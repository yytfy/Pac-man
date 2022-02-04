#include"gl/glut.h"

class food{
public:
    food(USHORT t=1);
    void draw(int x, int y, USHORT blockSize);

private:
    /*
        food type
        1 : normal 10 point
        2 : big    50 point, pca_man can be stronger for a while so that it can eat monsters.
    */
    unsigned short type;
    unsigned short point;
};