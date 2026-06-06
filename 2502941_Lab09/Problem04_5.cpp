#include <iostream>
#include "style.h"

using namespace std;

class Point {
private:
    int x;
    int y;

public:
    Point() : x(0), y(0) {
        cout << "Default constructor of Point called" << endl;
    }

    Point(int X, int Y) : x(X), y(Y) {

        if (X != 0) {
            cout << "Allocating x" << endl;
            x = X;
            cout << "x has been allocated" << endl;
        }

        if (Y != 0) {
            cout << "Allocating y" << endl;
            y = Y;
            cout << "y has been allocated" << endl;
        }
    }

    void print() {
        cout << "( " << x << " , " << y << " )" << endl;
    }

    ~Point() {
        cout << "~Point() called" << endl;
    }
};

class Triangle {
private:
    Point x;
    Point y;
    Point z;
    Style* st;

public:

    Triangle()
        : x(0,0), y(0,0), z(0,0), st(nullptr) {

        cout << "Default Triangle constructor called" << endl;
    }

    Triangle(
        int x1, int y1,
        int x2, int y2,
        int x3, int y3
    )
        : x(x1,y1), y(x2,y2), z(x3,y3), st(nullptr) {

        cout << "Triangle constructor called" << endl;
    }

    void setStyle(Style* s) {
        st = s;
    }

    void setColor(const char c[]) {

        if (st != nullptr) {
            st->setColor(c);
        }
    }

    void setFilled(bool f) {

        if (st != nullptr) {
            st->setFilled(f);
        }
    }

    void print() {

        cout << "X value: ";
        x.print();

        cout << "Y value: ";
        y.print();

        cout << "Z value: ";
        z.print();

        if (st != nullptr) {
            st->print();
        }
        else {
            cout << "No style" << endl;
        }
    }

    ~Triangle() {
        cout << "~Triangle() called" << endl;
    }
};

int main() {

    Style* st = new Style("blue", true);

    Triangle t1(1,0,0,1,0,0);

    t1.setStyle(st);

    t1.print();

    delete st;

    return 0;
}