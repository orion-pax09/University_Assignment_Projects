#include "Teacher.h"
#include <cstring>
class Teacher{
    private:
    int EmployeeId;
    char*name;
    public:
    Teacher::Teacher() : EmployeeId(0), name(nullptr) {}

Teacher::Teacher(const char* n, int id) : EmployeeId(id), name(nullptr) {
    if (n != nullptr) {
        name = new char[strlen(n) + 1];
        strcpy(name, n);
    }
}

Teacher::Teacher(const Teacher& other) : EmployeeId(other.EmployeeId), name(nullptr) {
    if (other.name != nullptr) {
        name = new char[strlen(other.name) + 1];
        strcpy(name, other.name);
    }
}

void Teacher::display() const {
    cout << "Employee ID: " << EmployeeId << endl;
    cout << "Teacher Name: " << name << endl;
}

Teacher::~Teacher() {
    delete[] name;
    name = nullptr;
}
};
