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



private:
    vector<vector<block>> blocks;
    unsigned short length;
    unsigned short width;
    unsigned short level;
    unsigned int curPoint;
    void drawPoint();

};
#endif