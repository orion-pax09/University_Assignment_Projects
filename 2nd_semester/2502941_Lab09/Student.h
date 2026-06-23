#pragma once
#include "Teacher.h"

class Student {
private:
    char* rollNumber;
    char* name;
    Teacher* teacherList;  
public:
    Student();
    Student(const char* rollid, const char* n, Teacher* list);
    Student(const Student& other);
    void display() const;
    ~Student();
};
