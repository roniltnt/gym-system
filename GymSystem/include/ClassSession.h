#pragma once

class Trainer;
class Member;

class ClassSession {
protected:
    char* className;
    Trainer& trainer;
    Member** participants;
    int numParticipants;

public:
    ClassSession(Trainer& t);
    virtual ~ClassSession();
    void addParticipant();
    virtual void printClass() = 0;
};
