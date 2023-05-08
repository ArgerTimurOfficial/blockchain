#ifndef TransactionData_h
#define TransactionData_h

struct TransactionData{
    double amount;
    std::string senderKey;
    std::string recieveKey;
    time_t timestamp;
};

#endif /* TransactionData_h */