#pragma once
#include "Person.h"
#include "Subscription.h"
#include "WorkoutPlan.h"
#include "Payment.h"

class Member : public Person {
private:
    Subscription* subscription;
    WorkoutPlan workoutPlan;
    Payment** payments;
    int numPayments;
    char* joinDate;

public:
    Member();
    ~Member();
    void printDetails() override;
    void pay();
    void getWorkoutPlan();
};
