#include"../include/map.h"

map::map(unsigned short len, unsigned short wid, unsigned short bs, pair<float, float> pos, unsigned short lives, unsigned short l) 
    :   length(len), width(wid), level(l), blocks({len, vector<block>(wid, bs)}), player(new pca_man({(pos.first+1)*bs, (pos.second+10)*bs}, lives)), curPoint(0)
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
        blocks[5][1+i].setFood(new food(1));
        blocks[25][1+i].setFood(new food(1));
    }
    for(int i=0; i<12; ++i) {
        blocks[6+i][5].setFood(new food(1));
        blocks[6+i][15].setFood(new food(1));
    }
    for(int i=0; i<9; ++i) {
        blocks[1][1+i].setFood(new food(1));
        blocks[1][11+i].setFood(new food(1));
        blocks[18][1+i].setFood(new food(1));
        blocks[18][11+i].setFood(new food(1));
    }
    for(int i=0; i<5; ++i) {
        blocks[19+i][5].setFood(new food(1));
        blocks[19+i][15].setFood(new food(1));
    }
    for(int i=0; i<4; ++i) {
        blocks[20][6+i].setFood(new food(1));
        blocks[20][11+i].setFood(new food(1));
        blocks[23][1+i].setFood(new food(1));
        blocks[23][16+i].setFood(new food(1));
    }
    for(int i=0; i<3; ++i) {
        blocks[2+i][5].setFood(new food(1));
        blocks[2+i][9].setFood(new food(1));
        blocks[2+i][11].setFood(new food(1));
        blocks[2+i][15].setFood(new food(1));
        blocks[6+i][1].setFood(new food(1));
        blocks[6+i][7].setFood(new food(1));
        blocks[6+i][13].setFood(new food(1));
        blocks[6+i][19].setFood(new food(1));
        blocks[8][2+i].setFood(new food(1));
        blocks[8][16+i].setFood(new food(1));
        blocks[21+i][7].setFood(new food(1));
        blocks[21+i][13].setFood(new food(1));
        blocks[20+i][3].setFood(new food(1));
        blocks[20+i][17].setFood(new food(1));
    }
    for(int i=0; i<2; ++i) {
        blocks[8][8+i].setFood(new food(1));
        blocks[8][11+i].setFood(new food(1));
        blocks[23][8+i].setFood(new food(1));
        blocks[23][11+i].setFood(new food(1));
    }
    blocks[2][1].setFood(new food(1));
    blocks[4][1].setFood(new food(1));
    blocks[2][19].setFood(new food(1));
    blocks[4][19].setFood(new food(1));
    blocks[19][9].setFood(new food(1));
    blocks[19][11].setFood(new food(1));
    blocks[19][1].setFood(new food(1));
    blocks[19][19].setFood(new food(1));
    blocks[20][2].setFood(new food(1));
    blocks[20][18].setFood(new food(1));
    blocks[24][1].setFood(new food(1));
    blocks[24][19].setFood(new food(1));
    blocks[24][9].setFood(new food(1));
    blocks[24][11].setFood(new food(1));
    blocks[3][1].setFood(new food(2));
    blocks[3][19].setFood(new food(2));
    blocks[20][1].setFood(new food(2));
    blocks[20][19].setFood(new food(2));


}

void map::draw() {
    for(int i=0; i<length; ++i) {
        for(int j=0; j<width; ++j) {
            blocks[i][j].draw(10 + j, i + 1);
        }
    }
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




