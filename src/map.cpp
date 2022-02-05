#include"../include/map.h"

map::map(unsigned short len, unsigned short wid, unsigned short bs, pair<float, float> pos, unsigned short lives, unsigned short l) 
    :   length(len), width(wid), level(l), blocks({len, vector<block>(wid, bs)}), player(new pca_man({(pos.first+1)*bs, (pos.second+10)*bs}, lives)), curPoint(0), foods()
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

    /* food init */
    for(int i=0; i<19; ++i) {
        foods.push_back(food(5+1, 1+i+10, bs));
        foods.push_back(food(25+1, 1+i+10, bs));
    }
    for(int i=0; i<12; ++i) {
        foods.push_back(food(6+i+1, 5+10, bs));
        foods.push_back(food(6+i+1, 15+10, bs));
    }
    for(int i=0; i<9; ++i) {
        foods.push_back(food(1+1, 1+i+10, bs));
        foods.push_back(food(1+1, 11+i+10, bs));
        foods.push_back(food(18+1, 1+i+10, bs));
        foods.push_back(food(18+1, 11+i+10, bs));
    }
    for(int i=0; i<5; ++i) {
        foods.push_back(food(19+i+1, 5+10, bs));
        foods.push_back(food(19+i+1, 15+10, bs));
    }
    for(int i=0; i<4; ++i) {
        foods.push_back(food(20+1, 6+i+10, bs));
        foods.push_back(food(20+1, 11+i+10, bs));
        foods.push_back(food(23+1, 1+i+10, bs));
        foods.push_back(food(23+1, 16+i+10, bs));
    }
    for(int i=0; i<3; ++i) {
        foods.push_back(food(2+i+1, 5+10, bs));
        foods.push_back(food(2+i+1, 9+10, bs));
        foods.push_back(food(2+i+1, 11+10, bs));
        foods.push_back(food(2+i+1, 15+10, bs));
        foods.push_back(food(6+i+1, 1+10, bs));
        foods.push_back(food(6+i+1, 7+10, bs));
        foods.push_back(food(6+i+1, 13+10, bs));
        foods.push_back(food(6+i+1, 19+10, bs));
        foods.push_back(food(8+1, 2+i+10, bs));
        foods.push_back(food(8+1, 16+i+10, bs));
        foods.push_back(food(21+i+1, 7+10, bs));
        foods.push_back(food(21+i+1, 13+10, bs));
        foods.push_back(food(20+i+1, 3+10, bs));
        foods.push_back(food(20+i+1, 17+10, bs));
    }
    for(int i=0; i<2; ++i) {
        foods.push_back(food(8+1, 8+i+10, bs));
        foods.push_back(food(8+1, 11+i+10, bs));
        foods.push_back(food(23+1, 8+i+10, bs));
        foods.push_back(food(23+1, 11+i+10, bs));
    }
    foods.push_back(food(2+1, 1+10, bs));
    foods.push_back(food(4+1, 1+10, bs));
    foods.push_back(food(2+1, 19+10, bs));
    foods.push_back(food(4+1, 19+10, bs));
    foods.push_back(food(19+1, 9+10, bs));
    foods.push_back(food(19+1, 11+10, bs));
    foods.push_back(food(19+1, 1+10, bs));
    foods.push_back(food(19+1, 19+10, bs));
    foods.push_back(food(20+1, 2+10, bs));
    foods.push_back(food(20+1, 18+10, bs));
    foods.push_back(food(24+1, 1+10, bs));
    foods.push_back(food(24+1, 19+10, bs));
    foods.push_back(food(24+1, 9+10, bs));
    foods.push_back(food(24+1, 11+10, bs));
    foods.push_back(food(3+1, 1+10, bs, 2));
    foods.push_back(food(3+1, 19+10, bs, 2));
    foods.push_back(food(20+1, 1+10, bs, 2));
    foods.push_back(food(20+1, 19+10, bs, 2));


}

void map::draw() {
    for(int i=0; i<length; ++i) {
        for(int j=0; j<width; ++j) {
            blocks[i][j].draw(10 + j, i + 1);
        }
    }
    for(auto f : foods) f.draw();
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
}

