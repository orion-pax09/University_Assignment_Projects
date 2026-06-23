#include "Complex.h"

Complex::Complex() : real(0), imaginary(0) {}

Complex::Complex(int r,int img)
{
    real=r;
    imaginary=img;
}

Complex Complex::operator+(const Complex& obj) const
{
    Complex temp;
    temp.real=real+obj.real;
    temp.imaginary=imaginary+obj.imaginary;
    return temp;
}

Complex Complex::operator-(Complex& obj)
{
    Complex temp;
    temp.real=real-obj.real;
    temp.imaginary=imaginary-obj.imaginary;
    return temp;
}

bool Complex::operator==(Complex& obj)
{
    return(real==obj.real && imaginary==obj.imaginary);
}

bool Complex::operator!=(Complex& obj)
{
    return(real!=obj.real || imaginary!=obj.imaginary);
}

Complex Complex::operator++(int)
{
    Complex temp=*this;
    real++;
    imaginary++;
    return temp;
}

Complex Complex::operator--(int)
{
    Complex temp=*this;
    real--;
    imaginary--;
    return temp;
}

Complex Complex::operator++()
{
    ++real;
    ++imaginary;
    return *this;
}

Complex Complex::operator--()
{
    --real;
    --imaginary;
    return *this;
}

Complex Complex::operator*(Complex& obj)
{
    Complex temp;
    temp.real=real*obj.real;
    temp.imaginary=imaginary*obj.imaginary;
    return temp;
}

Complex Complex::operator/(Complex& obj)
{
    Complex temp;
    temp.real=real/obj.real;
    temp.imaginary=imaginary/obj.imaginary;
    return temp;
}

void Complex::Printoutput()
{
    cout<<real<<" + "<<imaginary<<"i"<<endl;
    cout<<"----------------------"<<endl;
}

ostream& operator<<(ostream& out,const Complex& c)
{
    out<<c.real<<" + "<<c.imaginary<<"i";
    return out;
}

istream& operator>>(istream& in,Complex& c)
{
    cout<<"Enter real part: ";
    in>>c.real;

    cout<<"Enter imaginary part: ";
    in>>c.imaginary;

    return in;
}