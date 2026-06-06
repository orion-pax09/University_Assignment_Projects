#ifndef STUDENT_H
#define STUDENT_H

#include "Person.h"

class Student : public person {
protected:
    float cgpa;

public:
    Student(char* F, char* L, int A, float C);
    virtual ~Student();

    void setcgpa(float C);
    float getcgpa();

    void printStudent();
};

#endif