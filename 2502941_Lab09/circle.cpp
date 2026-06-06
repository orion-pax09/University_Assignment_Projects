#include "Circle.h"

Circle::Circle() : center(0, 0), radius(0) {
    cout << "Circle() called" << endl;
}

Circle::Circle(int x, int y, float r) : center(x, y), radius(r) {
    cout << "Circle() called" << endl;
}

void Circle::print() const {
    cout << "Center: ";
    center.print();
    cout << "Radius: " << radius << endl;
}

Circle::~Circle() {
    cout << "~Circle() called" << endl;
}