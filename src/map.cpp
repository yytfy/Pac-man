#include"../include/map.h"
#include<iostream>

map::map(unsigned short len, unsigned short wid, unsigned short bs, pair<float, float> pos, unsigned short lives, unsigned short l) 
    :   length(len), width(wid), level(l), blocks({len, vector<block>(wid, bs)}), player(new pca_man({(pos.first+1)*bs, (pos.second+10)*bs}, lives)),
    curPoint(0), foods(), gosts(), blockSize(bs), gostMode(1)
{
    /* block init */
    for(auto& b : blocks[0]) b.setReach(false);
    for(auto& b : blocks[26]) b.setReach(false);
    for(int i=1; i<=8; ++i) {
        blocks[i][0].setReach(false);
        blocks[i][20].setReach(false);
        blocks[17+i][0].setReach(false);
        blocks[17+i][20].setReach(false);
    }
    for(int i=0; i<7; ++i) {
        blocks[6+i][6].setReach(false);
        blocks[6+i][14].setReach(false);
        blocks[24][2+i].setReach(false);
        blocks[24][12+i].setReach(false);
    }
    for(int i=0; i<5; ++i) {
        blocks[9][0+i].setReach(false);
        blocks[9][16+i].setReach(false);
        blocks[17][0+i].setReach(false);
        blocks[17][16+i].setReach(false);
        blocks[12][0+i].setReach(false);
        blocks[12][16+i].setReach(false);
        blocks[14][0+i].setReach(false);
        blocks[14][16+i].setReach(false);
        blocks[6][8+i].setReach(false);
        blocks[7][8+i].setReach(false);
        blocks[16][8+i].setReach(false);
        blocks[17][8+i].setReach(false);
        blocks[21][8+i].setReach(false);
        blocks[22][8+i].setReach(false);
    }
    for(int i=0; i<4; ++i) {
        blocks[1+i][10].setReach(false);
        blocks[14+i][6].setReach(false);
        blocks[14+i][14].setReach(false);
        blocks[11+i][8].setReach(false);
        blocks[11+i][12].setReach(false);
    }
    for(int i=0; i<3; ++i) {
        blocks[2][2+i].setReach(false);
        blocks[2][6+i].setReach(false);
        blocks[2][12+i].setReach(false);
        blocks[2][16+i].setReach(false);
        blocks[4][2+i].setReach(false);
        blocks[4][6+i].setReach(false);
        blocks[4][12+i].setReach(false);
        blocks[4][16+i].setReach(false);
        blocks[6][2+i].setReach(false);
        blocks[7][2+i].setReach(false);
        blocks[6][16+i].setReach(false);
        blocks[7][16+i].setReach(false);
        blocks[19][2+i].setReach(false);
        blocks[19][6+i].setReach(false);
        blocks[19][12+i].setReach(false);
        blocks[19][16+i].setReach(false);
        blocks[20+i][4].setReach(false);
        blocks[20+i][16].setReach(false);
        blocks[21+i][6].setReach(false);
        blocks[21+i][14].setReach(false);
        blocks[14][9+i].setReach(false);
    }
    for(int i=0; i<2; ++i) {
        blocks[10+i][4].setReach(false);
        blocks[10+i][16].setReach(false);
        blocks[15+i][4].setReach(false);
        blocks[15+i][16].setReach(false);
        blocks[8+i][10].setReach(false);
        blocks[9][7+i].setReach(false);
        blocks[9][12+i].setReach(false);
        blocks[18+i][10].setReach(false);
        blocks[21][1+i].setReach(false);
        blocks[22][1+i].setReach(false);
        blocks[21][18+i].setReach(false);
        blocks[22][18+i].setReach(false);
        blocks[23+i][10].setReach(false);
    }
    blocks[3][2].setReach(false);
    blocks[3][4].setReach(false);
    blocks[3][6].setReach(false);
    blocks[3][8].setReach(false);
    blocks[3][12].setReach(false);
    blocks[3][14].setReach(false);
    blocks[3][16].setReach(false);
    blocks[3][18].setReach(false);
    blocks[11][9].setReach(false);
    blocks[11][11].setReach(false);

    pathFinder = AStarMap(blocks);

    /* food init */
    for(int i=0; i<19; ++i) {
        foods.emplace_back(5+1, 1+i+10, bs);
        foods.emplace_back(25+1, 1+i+10, bs);
    }
    for(int i=0; i<12; ++i) {
        foods.emplace_back(6+i+1, 5+10, bs);
        foods.emplace_back(6+i+1, 15+10, bs);
    }
    for(int i=0; i<9; ++i) {
        foods.emplace_back(1+1, 1+i+10, bs);
        foods.emplace_back(1+1, 11+i+10, bs);
        foods.emplace_back(18+1, 1+i+10, bs);
        foods.emplace_back(18+1, 11+i+10, bs);
    }
    for(int i=0; i<5; ++i) {
        foods.emplace_back(19+i+1, 5+10, bs);
        foods.emplace_back(19+i+1, 15+10, bs);
    }
    for(int i=0; i<4; ++i) {
        foods.emplace_back(20+1, 6+i+10, bs);
        foods.emplace_back(20+1, 11+i+10, bs);
        foods.emplace_back(23+1, 1+i+10, bs);
        foods.emplace_back(23+1, 16+i+10, bs);
    }
    for(int i=0; i<3; ++i) {
        foods.emplace_back(2+i+1, 5+10, bs);
        foods.emplace_back(2+i+1, 9+10, bs);
        foods.emplace_back(2+i+1, 11+10, bs);
        foods.emplace_back(2+i+1, 15+10, bs);
        foods.emplace_back(6+i+1, 1+10, bs);
        foods.emplace_back(6+i+1, 7+10, bs);
        foods.emplace_back(6+i+1, 13+10, bs);
        foods.emplace_back(6+i+1, 19+10, bs);
        foods.emplace_back(8+1, 2+i+10, bs);
        foods.emplace_back(8+1, 16+i+10, bs);
        foods.emplace_back(21+i+1, 7+10, bs);
        foods.emplace_back(21+i+1, 13+10, bs);
        foods.emplace_back(20+i+1, 3+10, bs);
        foods.emplace_back(20+i+1, 17+10, bs);
    }
    for(int i=0; i<2; ++i) {
        foods.emplace_back(8+1, 8+i+10, bs);
        foods.emplace_back(8+1, 11+i+10, bs);
        foods.emplace_back(23+1, 8+i+10, bs);
        foods.emplace_back(23+1, 11+i+10, bs);
    }
    foods.emplace_back(2+1, 1+10, bs);
    foods.emplace_back(4+1, 1+10, bs);
    foods.emplace_back(2+1, 19+10, bs);
    foods.emplace_back(4+1, 19+10, bs);
    foods.emplace_back(19+1, 9+10, bs);
    foods.emplace_back(19+1, 11+10, bs);
    foods.emplace_back(19+1, 1+10, bs);
    foods.emplace_back(19+1, 19+10, bs);
    foods.emplace_back(20+1, 2+10, bs);
    foods.emplace_back(20+1, 18+10, bs);
    foods.emplace_back(24+1, 1+10, bs);
    foods.emplace_back(24+1, 19+10, bs);
    foods.emplace_back(24+1, 9+10, bs);
    foods.emplace_back(24+1, 11+10, bs);
    foods.emplace_back(3+1, 1+10, bs, 2);
    foods.emplace_back(3+1, 19+10, bs, 2);
    foods.emplace_back(20+1, 1+10, bs, 2);
    foods.emplace_back(20+1, 19+10, bs, 2);

    /* gost init */
    gosts.emplace_back(pair<float,float>({(10+1.5)*bs, (10+10.5)*bs}), pair<USHORT, USHORT>({10, 10}), 75, 0);
    gosts.emplace_back(pair<float,float>({(13+1.5)*bs, (10+10.5)*bs}), pair<USHORT, USHORT>({13, 10}), 75, 1);
}

void map::draw() {
    glEnable(GL_POINT_SMOOTH);
    glHint(GL_POINT_SMOOTH_HINT,GL_NICEST);
    for(int i=0; i<length; ++i) {
        for(int j=0; j<width; ++j) {
            blocks[i][j].draw(10 + j, i + 1);
        }
    }
    for(auto f : foods) f.draw();
    for(auto g : gosts) g.draw();
    player->draw();
    drawPoint();
}

void map::drawPoint() {
    glColor3f(1.0f, 0.0f, 0.0f);
    int p = curPoint;
    for(int i=0; i<7; ++i) {
        glRasterPos2f(930-25*i, 100);
        char num = p % 10 + '0';
        p /= 10;
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, num);
    }
}

/*
    game state
    0 : game normal running
    1 : foods are eat out, this level finished.
*/
USHORT map::checkState() {
    if(foods.empty()) return 1;

    else return 0;
}

void map::gameplay(double t) {
    /* check eat food */
    for(auto i=foods.begin(); i!=foods.end(); ++i) {
        const pair<int, int>& fPos = i->getPos();
        int x = player->pos.first - fPos.first;
        int y = player->pos.second - fPos.second;
        if(sqrt(x*x + y*y) < 8) {
            curPoint += i->getPoint();
            foods.erase(i);
            break;
        }
    }
    USHORT px = player->pos.first / blockSize - 1.5, py = player->pos.second / blockSize - 10.5;
    BlinkyAction(t, px, py);
    PinkyAction(t, px, py);
    

}

void map::BlinkyAction(double t, short px, short py) {
    USHORT x = gosts[0].pos.first / blockSize - 1.5, y = gosts[0].pos.second / blockSize - 10.5;
    if(gostMode == 1) {
        bool newPos = false;
        if(gosts[0].rotation == -1) {
            gosts[0].pos.first -= t * gosts[0].speed;
            float target = (gosts[0].targetPos.first + 1.5) * blockSize;
            float rx = (1.5 + x) * blockSize;
            if(!reach(x-1, y) && gosts[0].pos.first < rx) {
                gosts[0].pos.first = rx;
                newPos = true;
            }
            else if(gosts[0].pos.first <= target) {
                gosts[0].pos.first = target;
                newPos = true;
            }
        }
        else if(gosts[0].rotation == 1) {
            gosts[0].pos.first += t * gosts[0].speed;
            float target = (gosts[0].targetPos.first + 1.5) * blockSize;
            float rx = (1.5 + x) * blockSize;
            if(!reach(x+1, y) && gosts[0].pos.first > rx) {
                gosts[0].pos.first = rx;
                newPos = true;
            }
            else if(gosts[0].pos.first >= target) {
                gosts[0].pos.first = target;
                newPos = true;
            }
        }
        else if(gosts[0].rotation == 2) {
            gosts[0].pos.second -= t * gosts[0].speed;
            float target = (gosts[0].targetPos.second + 10.5) * blockSize;
            float ry = (10.5 + y) * blockSize;
            if(!reach(x, y-1) && gosts[0].pos.second < (10.5 + y) * blockSize) {
                gosts[0].pos.second = ry;
                newPos = true;
            }
            else if(gosts[0].pos.second <= target) {
                
                gosts[0].pos.second = target;
                newPos = true;
            }
        }
        else if(gosts[0].rotation == 0) {
            gosts[0].pos.second += t * gosts[0].speed;
            float target = (gosts[0].targetPos.second + 10.5) * blockSize;
            float ry = (10.5 + y) * blockSize;
            if(!reach(x, y+1) && gosts[0].pos.second > ry) {
                gosts[0].pos.second = ry;
                newPos = true;
            }
            else if(gosts[0].pos.second >= target) {
                gosts[0].pos.second = target;
                newPos = true;
            }
        }
        if(newPos) {
            x = gosts[0].pos.first / blockSize - 1.5;
            y = gosts[0].pos.second / blockSize - 10.5;
            gosts[0].targetPos = pathFinder.searchNextPos(x, y, px, py);
            if(gosts[0].targetPos.first < x) gosts[0].rotation = -1;
            else if(gosts[0].targetPos.first > x) gosts[0].rotation = 1;
            else if(gosts[0].targetPos.second < y) gosts[0].rotation = 2;
            else gosts[0].rotation = 0;
        }
    }
}

void map::PinkyAction(double t, short px, short py) {
    USHORT x = gosts[1].pos.first / blockSize - 1.5, y = gosts[1].pos.second / blockSize - 10.5;
    if(gostMode == 1) {
        bool newPos = false;
        if(gosts[1].rotation == -1) {
            gosts[1].pos.first -= t * gosts[1].speed;
            float target = (gosts[1].targetPos.first + 1.5) * blockSize;
            float rx = (1.5 + x) * blockSize;
            if(!reach(x-1, y) && gosts[1].pos.first < rx) {
                gosts[1].pos.first = rx;
                newPos = true;
            }
            else if(gosts[1].pos.first <= target) {
                gosts[1].pos.first = target;
                newPos = true;
            }
        }
        else if(gosts[1].rotation == 1) {
            gosts[1].pos.first += t * gosts[1].speed;
            float target = (gosts[1].targetPos.first + 1.5) * blockSize;
            float rx = (1.5 + x) * blockSize;
            if(!reach(x+1, y) && gosts[1].pos.first > rx) {
                gosts[1].pos.first = rx;
                newPos = true;
            }
            else if(gosts[1].pos.first >= target) {
                gosts[1].pos.first = target;
                newPos = true;
            }
        }
        else if(gosts[1].rotation == 2) {
            gosts[1].pos.second -= t * gosts[1].speed;
            float target = (gosts[1].targetPos.second + 10.5) * blockSize;
            float ry = (10.5 + y) * blockSize;
            if(!reach(x, y-1) && gosts[1].pos.second < (10.5 + y) * blockSize) {
                gosts[1].pos.second = ry;
                newPos = true;
            }
            else if(gosts[1].pos.second <= target) {
                gosts[1].pos.second = target;
                newPos = true;
            }
        }
        else if(gosts[1].rotation == 0) {
            gosts[1].pos.second += t * gosts[1].speed;
            float target = (gosts[1].targetPos.second + 10.5) * blockSize;
            float ry = (10.5 + y) * blockSize;
            if(!reach(x, y+1) && gosts[1].pos.second > ry) {
                gosts[1].pos.second = ry;
                newPos = true;
            }
            else if(gosts[1].pos.second >= target) {
                gosts[1].pos.second = target;
                newPos = true;
            }
        }

        if(newPos) {
            if(player->rotation == 2) {
                py -= 4;
                while(py < 0 || !blocks[px][py].reach()) py++;
            }
            else if(player->rotation == 0) {
                py += 4;
                while(py >= blocks[0].size() || !blocks[px][py].reach()) py--;
            }
            else if(player->rotation == -1) {
                px -= 4;
                while(px < 0 || !blocks[px][py].reach()) px++;
            }
            else {
                px += 4;
                while(px >= blocks.size() || !blocks[px][py].reach()) px--;
            }
            gosts[1].targetPos = pathFinder.searchNextPos(x, y, px, py);
            if(gosts[1].targetPos.first < x) gosts[1].rotation = -1;
            else if(gosts[1].targetPos.first > x) gosts[1].rotation = 1;
            else if(gosts[1].targetPos.second < y) gosts[1].rotation = 2;
            else gosts[1].rotation = 0;
        }
    }
}




