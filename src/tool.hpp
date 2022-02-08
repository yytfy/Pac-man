#ifndef _TOOL_
#define _TOOL_
#include"../include/block.h"
#include<vector>
#include<utility>
#include<unordered_set>

class AStarPoint {
public:
    USHORT x, y;
    bool canReach;
    AStarPoint* pre;
    USHORT h;
    USHORT g;
    AStarPoint(USHORT xi=0, USHORT yi=0, bool r=true) : x(xi), y(yi), canReach(r) { }
};

class AStartMap {
public:
    AStartMap(const std::vector<std::vector<block>>& map)
    : aMap({map.size(), std::vector<AStarPoint>(map[0].size())})
    {
        for(int i=0; i<map.size(); ++i) {
            for(int j=0; j<map[0].size(); ++j) {
                aMap[i][j].x = i;
                aMap[i][j].y = j;
                aMap.canReach = map[i][j].reach();
            }

        }
    }

    std::pair<USHORT, USHORT> searchNextPos(USHORT x1, USHORT y1, USHORT x2, USHORT y2) {
        aMap[x1][y1]->h = getEvaluate(x1, y1, x2, y2); 
        unordered_set<AStarPoint*> openSet{&aMap[x1][y1]}, closedSet;

        while(openSet.size() > 0) {
            AStarPoint& minPoint = getMinPoint(openSet);
        }

        return make_pair<USHORT, USHORT>(-1, -1);
    }

    AStarPoint& getMinPoint(const unordered_set<AStarPoint*>& openSet) {
        u_short num = 0xffff;
        AStarPoint* minP = nullptr;
        for(auto p : openSet) {
            if(p->h < num) {
                minP = p;
                num = p->h;
            }
        }
        return *minP;
    }
    
    u_short getEvaluate(USHORT x1, USHORT y1, USHORT x2, USHORT y2) {
        return (abs(x1 - x2) + abs(y1 - y2)) * H_weight;
    }

    void reset() {
        for(const auto& row : aMap) {
            for(const auto& p :row) {
                p.pre = nullptr;
            }
        }
    }

private:
    std::vector<std::vector<AStarPoint>> aMap;
    u_short H_weight = 10;

};



#endif