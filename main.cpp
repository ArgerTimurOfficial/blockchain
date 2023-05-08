#include <bits/stdc++.h>

using namespace std;

struct TransactionData{
    double amount;
    string senderKey;
    string recieveKey;
    time_t timestamp;
};

class Block{
    private:
        int index;
        size_t blockHash;
        size_t previousHash;
        size_t generateHash();

    public:
        Block(int idx, TransactionData d, size_t prevHash);
        size_t getHash();
        size_t getPreviousHash();
        TransactionData data;

        bool isHashValid();
};

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

int main(){
    Blockchain AwesomeCoin;

    //TEST 1
    TransactionData data1;
    time_t data1Time;
    data1.amount = 1.5;
    data1.recieveKey = "Joe";
    data1.senderKey = "Sally";
    data1.timestamp = time(&data1Time);

    AwesomeCoin.addBlock(data1);

    cout << "Transaction {" << endl;
    cout << "\tAmount: " << data1.amount << endl
        <<  "\tFrom: " << data1.senderKey << endl
        << "\tTo: " << data1.recieveKey << endl
        << "\tTimestamp: " << data1.timestamp << endl
        << "\tValidity of the chain: " << AwesomeCoin.isChainValid() << endl;
    cout << "}" << endl;
    
    //TEST 2
    TransactionData data2;
    time_t data2Time;
    data2.amount = 0.0003;
    data2.recieveKey = "Martha";
    data2.senderKey = "Fred";
    data2.timestamp = time(&data2Time);

    AwesomeCoin.addBlock(data2);

    cout << "Transaction {" << endl;
    cout << "\tAmount: " << data2.amount << endl
        <<  "\tFrom: " << data2.senderKey << endl
        << "\tTo: " << data2.recieveKey << endl
        << "\tTimestamp: " << data2.timestamp << endl
        << "\tValidity of the chain: " << AwesomeCoin.isChainValid() << endl;
    cout << "}" << endl;
    
    //TEST 3
    Block *hackBlock = AwesomeCoin.getLatestBlock();
    hackBlock -> data.amount = 10000;
    hackBlock -> data.recieveKey = "Jon";
    
    cout << "Transaction {" << endl;
    cout << "\tAmount: " << hackBlock -> data.amount << endl
        <<  "\tFrom: " << hackBlock -> data.senderKey << endl
        << "\tTo: " << hackBlock -> data.recieveKey << endl
        << "\tTimestamp: " << hackBlock -> data.timestamp << endl
        << "\tValidity of the chain: " << AwesomeCoin.isChainValid() << endl;
    cout << "}" << endl;
}