#ifndef COMPLEX_H
#define COMPLEX_H

#include <iostream>
using namespace std;

class Complex
{
private:
    int real;
    int imaginary;

public:
    Complex();
    Complex(int r, int img);

    friend ostream& operator<<(ostream& out,const Complex& c);
    friend istream& operator>>(istream& in, Complex& c);

    Complex operator+(const Complex& obj) const;
    Complex operator-(Complex& obj);

    bool operator==(Complex& obj);
    bool operator!=(Complex& obj);

    // Postfix
    Complex operator++(int);
    Complex operator--(int);

    // Prefix
    Complex operator++();
    Complex operator--();

    Complex operator*(Complex& obj);
    Complex operator/(Complex& obj);

    void Printoutput();
};

#endif