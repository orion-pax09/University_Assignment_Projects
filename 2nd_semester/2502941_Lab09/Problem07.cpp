#include <iostream>
using namespace std;
#include "point.h"
#include "style.h"
class Circle{
    private:
    Point Center;
    float radius;
    Style* st;
    public:
    Circle():Center(0,0) ,  radius(0),st(nullptr){
        cout << "default constructor of circle"<<endl;
    }
    Circle(int x , int y , float r):Center(x,y) , radius(r),st(nullptr){
        cout<<"Circle called"<<endl;
    }
    void setStyle(Style*s){
        st = s;
    }
    void setColor(char c[]){
        if (st!=nullptr){
            st->setColor(c);
        }
    }
    void setfilled(bool f){
        if (st!=nullptr){
            st->setFilled(f);
        }
    }
    void print(){
        cout << "Center"<<endl;
        Center.print();
        cout<<"radius: "<<radius<<endl;
        if (st!=nullptr){
            st->print();
        }
        else{
            cout << "No style"<<endl;
        }
    }
    ~Circle(){
        cout << "~Circle() called"<<endl;
    }
};

int main(){
Circle c(3,4,2.5);
c.print();
Style* style1 = new Style("Blue",true);
Circle circle1(4,3,4.5);
circle1.setStyle(style1);
circle1.print();
}