#pragma once
#include <iostream>
using namespace std;

class Point {
private:
    int x;
    int y;
public:
    Point();
    Point(int X, int Y);
    void print() const;
    ~Point();
};
