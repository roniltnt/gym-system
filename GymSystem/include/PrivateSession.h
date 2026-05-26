#pragma once
#include "ClassSession.h"

class PrivateSession : public ClassSession {
private:
    char* focusArea;

public:
    PrivateSession(Trainer& t);
    ~PrivateSession();
    void printClass() override;
};
