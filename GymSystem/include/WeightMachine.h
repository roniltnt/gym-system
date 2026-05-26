#pragma once
#include "Machines.h"

class WeightMachine : public Machines {
private:
    int pulleyCount;

public:
    WeightMachine();
    ~WeightMachine();
    void printEquipment() override;
};
