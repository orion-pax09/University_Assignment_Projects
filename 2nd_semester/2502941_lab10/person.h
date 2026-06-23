#ifndef PERSON_H
#define PERSON_H

#include <iostream>
#include <cstring>
using namespace std;

class person {
private:
    char* fname;
    char* lname;

protected:
    int age;

public:
    person(char* FName, char* LName, int age);
    virtual ~person();

    void setage(int Age);
    void setfirstname(char* FNAME);
    void setlastname(char* LNAME);

    char* getfname();
    char* getlastname();
    int getage();

    void printinformation();
};

#endif