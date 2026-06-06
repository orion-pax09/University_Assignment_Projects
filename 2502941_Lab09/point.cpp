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