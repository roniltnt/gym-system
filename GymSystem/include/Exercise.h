#pragma once

class Exercise {
private:
    char* name;
    char* description;

public:
    Exercise();
    ~Exercise();
    char* getName();
    char* getDescription();
};
