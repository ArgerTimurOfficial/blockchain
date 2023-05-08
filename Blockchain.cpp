#include <bits/stdc++.h>

#include "TransactionData.h"
#include "Block.h"
#include "Blockchain.h"

Blockchain::Blockchain(){
    Block genesis = createGenesisBlock();
    chain.push_back(genesis);
}

Block Blockchain::createGenesisBlock(){
    time_t current;
    TransactionData d;
    d.amount = 0;
    d.recieveKey = "None";
    d.senderKey = "None";
    d.timestamp = time(&current);

    hash<int> hash1;
    Block genesis(0, d, hash1(0));
    return genesis;
}

Block *Blockchain::getLatestBlock(){
    return &chain.back();
}

void Blockchain::addBlock(TransactionData d){
    int index = (int)chain.size() - 1;
    Block newBlock(index, d, getLatestBlock() -> getHash());
}

bool Blockchain::isChainValid(){
    vector<Block>::iterator it;
    int chainLen = (int)chain.size();

    for(it = chain.begin(); it != chain.end(); ++it){
        Block currentBlock = *it;
        if(!currentBlock.isHashValid()){
            return false;
        } if(chainLen > 1){
            Block previousBlock = *(it - 1);
            if(currentBlock.getPreviousHash() != previousBlock.getHash()){
                return false;
            }
        }
    }
    return true;
}