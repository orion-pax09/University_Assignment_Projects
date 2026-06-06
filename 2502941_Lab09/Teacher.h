#pragma once
#include <iostream>
using namespace std;

class Teacher {
private:
    int EmployeeId;
    char* name;
public:
    Teacher();
    Teacher(const char* n, int id);
    Teacher(const Teacher& other);
    void display() const;
    ~Teacher();
};
