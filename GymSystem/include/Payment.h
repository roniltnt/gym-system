#pragma once

class Payment {
private:
    double amount;
    char* date;
    int transactionId;

public:
    Payment();
    ~Payment();
    double getAmount();
    char* getDate();
    int getTransactionId();
};
