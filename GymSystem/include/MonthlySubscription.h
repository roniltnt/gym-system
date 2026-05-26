#pragma once
#include "Subscription.h"

class MonthlySubscription : public Subscription {
public:
    MonthlySubscription();
    ~MonthlySubscription();
    double calculatePrice() override;
};
