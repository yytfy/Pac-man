#include"../include/block.h"

void block::draw(int x, int y) {
    if(!reachable) {
        glColor3f(0.0f, 0.0f, 1.0f);
        glRectf(x * bs, y * bs, (x + 1) * bs, (y + 1) * bs);
    }
}
