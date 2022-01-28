#include"../include/map.h"

map::map(unsigned short len, unsigned short wid, unsigned short bs, unsigned short l) 
    :   length(len), width(wid), level(l), blocks({len, vector<block>(wid, bs)})
{
    /* map init */
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

}

void map::draw() {
    for(int i=0; i<length; ++i) {
        for(int j=0; j<width; ++j) {
            blocks[i][j].draw(10 + j, i + 1);
        }
    }
}




