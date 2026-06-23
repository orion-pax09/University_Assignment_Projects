#pragma once
#include "Point.h"
#include "Style.h"

class Circle {
private:
    Point center;
    float radius;
    Style* st;
public:
    Circle();
    Circle(int x, int y, float r);
    void setStyle(Style* s);
    void setColor(const char c[]);
    void setFilled(bool f);
    void print() const;
    ~Circle();
};
