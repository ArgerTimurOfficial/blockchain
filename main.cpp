#include <bits/stdc++.h>

#include "Block.h"
#include "Blockchain.h"
#include "TransactionData.h"

using namespace std;

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