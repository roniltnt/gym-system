#pragma once

class Subscription {
protected:
    double price;

public:
    Subscription();
    virtual ~Subscription();
    virtual double calculatePrice() = 0;
};
