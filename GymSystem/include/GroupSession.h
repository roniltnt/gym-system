#pragma once
#include "ClassSession.h"

class GroupSession : public ClassSession {
private:
    int maxParticipants;

public:
    GroupSession(Trainer& t);
    ~GroupSession();
    void printClass() override;
};
