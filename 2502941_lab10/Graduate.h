#ifndef GRADUATE_H
#define GRADUATE_H

#include "Student.h"

class Graduate : public Student {
private:
    char* ThesisTopic;

public:
    Graduate(char* F, char* L, int A, char* thesis, float C);
    ~Graduate();

    void setthesistopic(char* T);
    char* getthesisname();

    void printGraduate();
};

#endif