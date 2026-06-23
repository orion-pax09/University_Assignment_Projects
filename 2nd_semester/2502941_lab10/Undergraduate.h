#ifndef UNDERGRADUATE_H
#define UNDERGRADUATE_H

#include "Student.h"

class undergraduate : public Student {
private:
    char* FYP_Name;

public:
    undergraduate(char* fname, char* lname, int A, float C, char* fypname);
    ~undergraduate();

    void setfypname(char* fypNAME);
    char* getfyp();

    void printundergraduate();
};

#endif