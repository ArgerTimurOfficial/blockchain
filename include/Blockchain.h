#ifndef Blockchain_h
#define Blockchain_h

#include <vector>

using namespace std;

class Blockchain{
    private:
        Block createGenesisBlock();

    public:
        vector<Block> chain;
        Blockchain();

        void addBlock(TransactionData data);
        bool isChainValid();

        Block *getLatestBlock();
};

#endif /* Blockchain_h */