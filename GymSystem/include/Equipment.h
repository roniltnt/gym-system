#pragma once

class Equipment {
protected:
    char* name;
    char* muscleGroup;
    bool isAvailable;

public:
    Equipment();
    virtual ~Equipment();
    virtual void printEquipment();
};
