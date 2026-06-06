#include "Student.h"
#include <cstring>
class Student{
    private:
    char* roll_number;
    char*name;
    Teacher*TeacherList;
    
Student::Student() : roll_number(nullptr), name(nullptr), TeacherList(nullptr) {}

Student::Student(const char* rollid, const char* n, Teacher* list)
    : roll_number(nullptr), name(nullptr), TeacherList(nullptr) {
    if (rollid != nullptr) {
        roll_number = new char[strlen(rollid) + 1];
        strcpy(roll_number, rollid);
    }
    if (n != nullptr) {
        name = new char[strlen(n) + 1];
        strcpy(name, n);
    }
    TeacherList = list;
}

Student::Student(const Student& others)
    : roll_number(nullptr), name(nullptr), TeacherList(nullptr) {
    if (others.roll_number != nullptr) {
        roll_number = new char[strlen(others.roll_number) + 1];
        strcpy(roll_number, others.roll_number);
    }
    if (others.name != nullptr) {
        name = new char[strlen(others.name) + 1];
        strcpy(name, others.name);
    }
    TeacherList = others.TeacherList;
}

void Student::display() const {
    cout << "Student Roll No: " << roll_number << endl;
    cout << "Student Name: " << name << endl;
    if (TeacherList != nullptr) {
        cout << "--- Associated Teacher ---" << endl;
        TeacherList->display();
    }
}

Student::~Student() {
    delete[] roll_number;
    roll_number = nullptr;
    delete[] name;
    name = nullptr;
}
};
