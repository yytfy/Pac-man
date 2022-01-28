#ifndef _PCAMAN_
#define _PCAMAN_
#include<utility>

class pca_man{
public:

    pca_man(int x, int y, int r) : pos({x, y}), rotation(r) { }


    void draw();



private:
    /*
    *   角色的移动方向:
    *   -1 为初始状态原地不动;
    *   0  为向做;
    *   1  为向右;
    *   2  为向上;
    *   3  为向下;
    */
    float rotation;
    /*
    *   角色位置
    */
    std::pair<int, int> pos;
};
#endif