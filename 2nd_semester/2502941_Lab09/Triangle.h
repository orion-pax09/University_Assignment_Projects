#pragma once
#include "Point.h"
#include "Style.h"

class Triangle {
private:
    Point x;
    Point y;
    Point z;
    Style* st;
public:
    Triangle();
    Triangle(int x1, int y1, int x2, int y2, int x3, int y3);
    void setStyle(Style* s);
    void setColor(const char c[]);
    void setFilled(bool f);
    void print() const;
    ~Triangle();
};
