#pragma once
#include "Equipment.h"

class Machines : public Equipment {
protected:
    char* cableType;

public:
    Machines();
    ~Machines();
    void printEquipment() override;
};
