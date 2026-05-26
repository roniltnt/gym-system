#pragma once
#include "Person.h"

class Member;

class Trainer : public Person {
private:
    char* specialty;
    int experienceYears;
    Member** myMembers;
    int numMembers;
    double salary;

public:
    Trainer();
    ~Trainer();
    void printDetails() override;
    void createWorkoutPlan(Member* m);
    void changeWorkoutPlan(Member* m);
    void addMember(Member* m);
    void removeMember(Member* m);
    void teachClass();
};
