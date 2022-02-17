#ifndef _MAP_
#define _MAP_
#include"player.h"
#include"gost.h"
#include"block.h"
#include<vector>
#include<memory>
#include"gl/glut.h"
#include"tool.hpp"
#include<cstdlib>

using namespace std;

class map{
public:
    map(unsigned short len, unsigned short wid, unsigned short bs, pair<float, float> pos, unsigned short lives, unsigned short l = 0);

    unique_ptr<pca_man> player;
    void draw();
    bool reach(short x, short y);
    /*
        游戏状态
        0 : 游戏正常进行
        1 : 食物吃完，本关结束
    */
    USHORT checkState();
    void gameplay(double t);
    double timeCnt;



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
    double gostModeTimeCnt;
    AStarMap pathFinder;
    void drawUI();
    void resetGosts();
    void resetPlayerPos();
    void BlinkyAction(double t, short px, short py);
    void PinkyAction(double t, short px, short py);
    void InkyAction(double t, short px, short py);
    void ClydeAction(double t, short px, short py);
    pair<short, short> randomPath(short x, short y);

};
#endif