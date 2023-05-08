#include <bits/stdc++.h>

#include "Block.h"
#include "TransactionData.h"

Block::Block(int idx, TransactionData d, size_t prevHash){
    index = idx;
    data = d;
    previousHash = prevHash;
    blockHash = generateHash();
}

size_t Block::generateHash(){
    hash<string> hash1;
    hash<size_t> hash2;
    hash<size_t> finalHash;

    string toHash = to_string(data.amount) + data.recieveKey + data.senderKey + to_string(data.timestamp);

    return finalHash(hash1(toHash) + hash2(previousHash));
}

size_t Block::getHash(){
    return blockHash;
}

size_t Block::getPreviousHash(){
    return previousHash;
}

bool Block::isHashValid(){
    return generateHash() == blockHash;
}