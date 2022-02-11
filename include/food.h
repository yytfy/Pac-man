#include"gl/glut.h"
#include<utility>

using namespace std;

class food{
public:
    food(int x, int y, USHORT blockSize, USHORT t=1);
    void draw();
    USHORT getPoint() const { return point; }
    const pair<int, int>& getPos() const { return pos; }

private:
    /*
        food type
        1 : normal 10 point
        2 : big    50 point, pca_man can be stronger for a while so that it can eat gosts.
    */
    unsigned short type;
    unsigned short point;
    pair<int, int> pos;
};