class map{
public:




private:
    vector<vector<block>> blocks;


};

class block{
public:
    block() : reachable(false) {}
    block(int size) : blockSize(size), reachable(false) {}
    block(int size, bool reach) : blockSize(size), reachable(reach) {}


private:
    int blockSize;
    bool reachable;
    food* f;

};