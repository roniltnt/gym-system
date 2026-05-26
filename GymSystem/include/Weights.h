#pragma once
#include "Equipment.h"

class Weights : public Equipment {
protected:
    double weightKG;

public:
    Weights();
    ~Weights();
    void printEquipment() override;
};
