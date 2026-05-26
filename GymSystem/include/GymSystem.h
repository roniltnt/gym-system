#pragma once

class Member;
class Trainer;
class ClassSession;
class Equipment;

class GymSystem {
private:
    Member** members;
    Trainer** trainers;
    ClassSession** classes;
    Equipment** equipment;
    int numMembers;
    int numTrainers;

public:
    GymSystem();
    ~GymSystem();
    void addMember();
    void deleteMember();
    void addTrainer();
    void deleteTrainer();
    void addClass();
    void cancelClass();
    void addEquipment();
    void printReports();
};
