#pragma once
#include "Exercise.h"

class WorkoutPlan {
private:
    char* planName;
    Exercise** exercises;
    int numExercises;

public:
    WorkoutPlan();
    ~WorkoutPlan();
    void addExercise();
    void removeExercise();
};
