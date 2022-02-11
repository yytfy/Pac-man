#ifndef _TOOL_
#define _TOOL_
#include"block.h"
#include<vector>
#include<utility>
#include<unordered_set>
#include<iostream>

class AStarPoint {
public:
    USHORT x, y;
    bool canReach;
    AStarPoint* pre;
    USHORT f;
    USHORT g;
    AStarPoint(USHORT xi=0, USHORT yi=0, bool r=true) : x(xi), y(yi), canReach(r), g(0), pre(nullptr) { }
};

class AStarMap {
public:
    AStarMap() = default;
    AStarMap(const std::vector<std::vector<block>>& map)
    : aMap({map.size(), std::vector<AStarPoint>(map[0].size())})
    {
        for(int i=0; i<map.size(); ++i) {
            for(int j=0; j<map[0].size(); ++j) {
                aMap[i][j].x = i;
                aMap[i][j].y = j;
                aMap[i][j].canReach = map[i][j].reach();
            }

        }
    }

    std::pair<USHORT, USHORT> searchNextPos(USHORT x1, USHORT y1, USHORT x2, USHORT y2) {
        aMap[x1][y1].f = getEvaluate(x1, y1, x2, y2); 
        unordered_set<AStarPoint*> openSet{&aMap[x1][y1]}, closedSet;

        while(openSet.size() > 0) {
            AStarPoint* minPoint = getMinPoint(openSet);
            if(minPoint->x == x2 && minPoint->y == y2) {
                AStarPoint* curPoint = minPoint;
                while(curPoint->pre && (curPoint->x != x1 || curPoint->y != y1)) {
                    curPoint = curPoint->pre;
                }
                return {curPoint->x, curPoint->y};
            }
            openSet.erase(minPoint);
            closedSet.emplace(minPoint);

            vector<AStarPoint*> neighbors = getNeighbors(minPoint);
            for(auto neighbor : neighbors) {
                if(closedSet.count(neighbor)) continue;
                int g = minPoint->g + 10;
                if(!openSet.count(neighbor) || g < neighbor->g) {
                    neighbor->g = g;
                    neighbor->f = g + getEvaluate(neighbor->x, neighbor->y, x2, y2);
                    neighbor->pre = minPoint;
                    if(!openSet.count(neighbor)) openSet.emplace(neighbor);
                }
            }


        }

        return make_pair<USHORT, USHORT>(-1, -1);
    }


    vector<AStarPoint*> getNeighbors(AStarPoint* p) {
        vector<AStarPoint*> neighbors;
        // ↑
        if(p->x-1 >= 0 && aMap[p->x-1][p->y].canReach) neighbors.emplace_back(&aMap[p->x-1][p->y]);
        // ↓
        if(p->x+1 < aMap.size() && aMap[p->x+1][p->y].canReach) neighbors.emplace_back(&aMap[p->x+1][p->y]);
        // ←
        if(p->y-1 >= 0 && aMap[p->x][p->y-1].canReach) neighbors.emplace_back(&aMap[p->x][p->y-1]);
        // →
        if(p->y+1 < aMap[0].size() && aMap[p->x][p->y+1].canReach) neighbors.emplace_back(&aMap[p->x][p->y+1]);
        return neighbors;
    }

    AStarPoint* getMinPoint(const unordered_set<AStarPoint*>& openSet) {
        USHORT num = 0xffff;
        AStarPoint* minP = nullptr;
        for(auto p : openSet) {
            if(p->f < num) {
                minP = p;
                num = p->f;
            }
        }
        return minP;
    }
    
    USHORT getEvaluate(USHORT x1, USHORT y1, USHORT x2, USHORT y2) {
        return (abs(x1 - x2) + abs(y1 - y2)) * H_weight;
    }

    void reset() {
        for(auto& row : aMap) {
            for(auto& p :row) {
                p.pre = nullptr;
            }
        }
    }

private:
    std::vector<std::vector<AStarPoint>> aMap;
    USHORT H_weight = 10;

};



#endif