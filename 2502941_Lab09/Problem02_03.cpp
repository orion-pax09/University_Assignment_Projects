#include <iostream>
using namespace std;
#include "point.h"
#include "circle.h"
class Point{
    private:
    int x;
    int y;
    public:
    Point():x(0) , y(0){cout << "Default constructor of point called"<<endl;};
    Point(int X , int Y):x(0) , y(0){
        if (X !=0){
            cout << "Allocating x"<<endl;
            x = X;
            cout << "X has been allocated"<<endl;
        }
        if (Y!=0){
            cout << "Allocating y"<<endl;
            y = Y;
            cout<< "y has been allocated"<<endl;
        }
    }
    void print(){
        cout << "( "<<x<<" , "<<y<<" )"<<endl;
    }
    ~Point(){
        cout<<"~Point() called"<<endl;
    }
};

class Circle{
    private:
    Point Center;
    float radius;
    public:
    Circle():Center(0,0) ,  radius(0){cout << "default constructor of circle"<<endl;};
    Circle(int x , int y , float r):Center(x,y) , radius(r){
        cout<<"Circle called"<<endl;
    }
    void print(){
        cout << "Center: ";
        Center.print();
        cout << "radius: "<<radius<<endl;
    }
    ~Circle(){
        cout << "~Circle() called"<<endl;
    }
};
    int main(){
        Circle c(3,4,2.5);
        c.print();
    }

