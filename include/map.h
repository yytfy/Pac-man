#include"player.h"
#include"monster.h"
#include"food.h"
#include"game.h"
#include<vector>

using std::vector;

class map{
public:




private:
    vector<vector<block>> blocks;


};

class block{
public:
    block(int size = blockSize) : blockSize(size), reachable(false) {}
    block(int size = blockSize, bool reach) : blockSize(size), reachable(reach) {}
    bool reach() const { return reachable; }
    void setReach(bool r) { reachable = r; }
    void draw();

private:
    int blockSize;
    bool reachable;
    food* f;

};