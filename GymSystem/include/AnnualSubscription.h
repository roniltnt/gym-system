#pragma once
#include "Subscription.h"

class AnnualSubscription : public Subscription {
public:
    AnnualSubscription();
    ~AnnualSubscription();
    double calculatePrice() override;
};
