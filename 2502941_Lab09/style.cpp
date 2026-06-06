#include "Triangle.h"

Triangle::Triangle() : x(0,0), y(0,0), z(0,0), st(nullptr) {
    cout << "Triangle() called" << endl;
}

Triangle::Triangle(int x1, int y1, int x2, int y2, int x3, int y3)
    : x(x1,y1), y(x2,y2), z(x3,y3), st(nullptr) {
    cout << "Triangle() called" << endl;
}

// Aggregation - just store pointer, do not own it
void Triangle::setStyle(Style* s) {
    st = s;
}

void Triangle::setColor(const char c[]) {
    if (st != nullptr) {
        st->setColor(c);
    }
}

void Triangle::setFilled(bool f) {
    if (st != nullptr) {
        st->setFilled(f);
    }
}

void Triangle::print() const {
    cout << "Corner X: "; x.print();
    cout << "Corner Y: "; y.print();
    cout << "Corner Z: "; z.print();
    if (st != nullptr) {
        st->print();
    } else {
        cout << "No style" << endl;
    }
}

// Do NOT delete st — Triangle does not own the Style object
Triangle::~Triangle() {
    cout << "~Triangle() called" << endl;
}