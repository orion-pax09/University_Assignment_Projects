#pragma once
#include <iostream>
using namespace std;

class Style {
private:
    char color[10];
    bool isFilled;
public:
    Style();
    Style(const char c[], bool f);
    void setColor(const char c[]);
    void setFilled(bool f);
    void print() const;
    ~Style();
};
