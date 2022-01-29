#ifndef _MAP_
#define _MAP_
#include"player.h"
#include"monster.h"
#include"block.h"
#include<vector>
#include<memory>

using namespace std;

class map{
public:
    map(unsigned short len, unsigned short wid, unsigned short bs, pair<float, float> pos, unsigned short lives, unsigned short l = 0);

    unique_ptr<pca_man> character;
    void draw();



private:
    vector<vector<block>> blocks;
    unsigned short length;
    unsigned short width;
    unsigned short level;
    unsigned int curPoint;
    



};
#endif