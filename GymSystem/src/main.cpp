#include <iostream>
#include "../include/GymSystem.h"
#include "../include/Member.h"
#include "../include/Trainer.h"
#include "../include/GroupSession.h"
#include "../include/PrivateSession.h"
#include "../include/weights.h"
#include "../include/machines.h"
#include "../include/weightMachine.h"
#include "../include/MonthlySubscription.h"
#include "../include/AnnualSubscription.h"
#include "../include/Payment.h"

using namespace std;

int main() {
    cout << "===== Starting GymSystem Demonstration =====" << endl << endl;

    GymSystem gym;

    Trainer* trainer1 = new Trainer((char*)"John Doe", 111222, (char*)"050-1111111", (char*)"Tel Aviv", (char*)"Bodybuilding", 5, 8000.0);
    Trainer* trainer2 = new Trainer((char*)"Jane Smith", 333444, (char*)"052-2222222", (char*)"Petah Tikva", (char*)"Rehabilitation", 8, 9500.0);

    Member* member1 = new Member((char*)"Alice Green", 555666, (char*)"054-3333333", (char*)"Petah Tikva", (char*)"01/01/2026");
    Member* member2 = new Member((char*)"Bob Blue", 777888, (char*)"053-4444444", (char*)"Herzliya", (char*)"15/02/2026");

    Subscription* sub1 = new MonthlySubscription(250.0, 3); 
    Subscription* sub2 = new AnnualSubscription(200.0, 15.0); 

    member1->pay(); 
    member2->pay();

    trainer1->addMember(member1);
    trainer1->addMember(member2);

    trainer1->createWorkoutPlan(member1);
    trainer1->changeWorkoutPlan(member1);

    weights* dumbbell = new weights((char*)"Dumbbell", (char*)"Biceps", true, 12.5);
    machines* smithMachine = new machines((char*)"Smith Machine", (char*)"Chest", true, (char*)"Steel Cable");
    weightMachine* cableCross = new weightMachine((char*)"Cable Crossover", (char*)"Full Body", true, 50.0, (char*)"Nylon", 4);

    GroupSession* groupClass = new GroupSession((char*)"Spinning Extreme", *trainer1, 20);
    PrivateSession* privateClass = new PrivateSession((char*)"Personal Core", *trainer2, (char*)"Post-Injury", true);

    groupClass->addParticipant(); 
    privateClass->addParticipant();

    gym.addTrainer();  
    gym.addMember();
    gym.addClass();
    gym.addEquipment();

    cout << "--- Printing Person Details (Polymorphism) ---" << endl;
    Person* p1 = trainer1;
    Person* p2 = member1;
    p1->printDetails(); 
    p2->printDetails(); 

    cout << "\n--- Printing Class Session Details ---" << endl;
    groupClass->printClass();
    privateClass->printClass();

    cout << "\n--- Printing Equipment Details (Multiple Inheritance) ---" << endl;
    cableCross->printEquipment();

    cout << "\n--- Printing Gym Management System General Reports ---" << endl;
    gym.printReports();

    delete trainer1;
    delete trainer2;
    delete member1;
    delete member2;
    delete sub1;
    delete sub2;
    delete dumbbell;
    delete smithMachine;
    delete cableCross;
    delete groupClass;
    delete privateClass;

    cout << "\n===== GymSystem Demonstration Ended Cleanly =====" << endl;
    return 0;
}
