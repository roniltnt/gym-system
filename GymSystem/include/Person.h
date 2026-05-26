#pragma once

class Person {
protected:
    char* name;
    int id;
    char* phone;
    char* address;

public:
    Person();
    virtual ~Person();
    virtual void printDetails() = 0;
};
