#ifndef _MAP_
#define _MAP_
#include"player.h"
#include"monster.h"
#include"block.h"
#include<vector>
#include<memory>
#include"gl/glut.h"

using namespace std;

class map{
public:
    map(unsigned short len, unsigned short wid, unsigned short bs, pair<float, float> pos, unsigned short lives, unsigned short l = 0);

    unique_ptr<pca_man> player;
    void draw();
    bool reach(int x, int y) { return blocks[x][y].reach(); }
    /*
        游戏状态
        0 : 游戏正常进行
        1 : 食物吃完，本关结束
    */
    USHORT checkState();
    void gameplay(double t);



private:
    vector<vector<block>> blocks;
    vector<food> foods;
    vector<monster> monsters;
    unsigned short length;
    unsigned short width;
    unsigned short level;
    unsigned int curPoint;
    /*
        0: chase mode
        1: scatter mode
        2: frighten mode
    */
    USHORT gostMode;
    void drawPoint();

};
#endif