#ifndef _MAP_
#define _MAP_
#include"player.h"
#include"gost.h"
#include"block.h"
#include<vector>
#include<memory>
#include"gl/glut.h"
#include"tool.hpp"

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
    USHORT blockSize;
    vector<vector<block>> blocks;
    vector<food> foods;
    vector<gost> gosts;
    USHORT length;
    USHORT width;
    USHORT level;
    unsigned int curPoint;
    /*
        0: scatter mode
        1: chase mode
        2: frighten mode
    */
    USHORT gostMode;
    AStarMap pathFinder;
    void drawPoint();
    void BlinkyAction(double t, short px, short py);
    void PinkyAction(double t, short px, short py);

};
#endif