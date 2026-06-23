#ifndef FACULTY_H
#define FACULTY_H

#include "Person.h"

class Faculty : public person {
private:
    int course_num;
    int three_digits;

public:
    Faculty(char* F, char* L, int A, int c_Count, int three_D);
    ~Faculty();

    void setcoursenum(int num);
    void setthreedigits(int three_D);

    void printFaculty();
};

#endif