#include <iostream>
#include "circle.h"
#include "Triangle.h"
#include "style.h"
#include "Student.h"
using namespace std;

int main() {

    // ---- Problem 01: Association ----
    cout << "=== Problem 01 ===" << endl;
    Teacher t1("Imran Ali", 45);
    Student s1("2502941", "Muhammad Hamza Khan", &t1);
    s1.display();

    // ---- Problem 03: Circle (Composition) ----
    cout << "\n=== Problem 03 ===" << endl;
    Circle c(3, 4, 2.5);
    c.print();

    // ---- Problem 05: Triangle (Composition) ----
    cout << "\n=== Problem 05 ===" << endl;
    Triangle obj(1, 0, 0, 1, 0, 0);
    obj.print();

    // ---- Problem 07: Circle with Style (Aggregation) ----
    cout << "\n=== Problem 07 ===" << endl;
    Style* style1 = new Style("Blue", true);
    Circle circle1(4, 3, 4.5);
    circle1.setStyle(style1);
    circle1.print();

    // ---- Problem 08: Triangle with same Style (Aggregation) ----
    cout << "\n=== Problem 08 ===" << endl;
    Triangle triangle1(1, 0, 0, 1, 0, 0);
    triangle1.setStyle(style1);  // same style1 object
    triangle1.print();

    // Changing style via circle1 - triangle1 reflects the same change
    cout << "\n--- After changing style via circle1 ---" << endl;
    circle1.setColor("Red");
    circle1.setFilled(false);
    circle1.print();
    triangle1.print();  // will show Red / not filled too

    // Cleanup
    delete style1;

    return 0;
}