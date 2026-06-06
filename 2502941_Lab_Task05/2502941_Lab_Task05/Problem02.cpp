#include <iostream>
using namespace std;
class Box{
    private:
    int length ; 
    int breadth ; 
    int height ;
    static int objectcount;
    public:
    static int Objectcount(){
        return objectcount;
    }
    Box(){
        length = 0;
        breadth = 0;
        height = 0;
        objectcount++;
    }
    Box(const int& length , const int& breadth , const int& height){
        this->length = length;
        this->breadth = breadth;
        this->height = height;
        objectcount++;
    }
    // we set setter and getter in case if we want to update value 
    void setLength(int length){
        this -> length = length;
    }
    void setBreadth (int breadth){
        this -> breadth = breadth;
    }
    void setheight(int height){
        this -> height = height;
    }
    int getlength(){
        return length;
    }
    int getbreadth(){
        return breadth;
    }
    int getheight(){
        return height;
    }
    double Area(){
        return length * breadth;
    }
    double volume(){
        return length * breadth * height;
    }   
};
int Box::objectcount = 0;
int main(){
    Box obj1(4,5,6);
    cout << "Object is: (default constructor) "<<obj1.getlength()<<endl;
    obj1.setLength(5);
    cout << "updated length: (Calling setter and getter function): "<<obj1.getlength()<<endl;
    Box obj2(5,6,7);
    Box obj3(9,7,6);
    cout << "The total number of object called is: "<<Box::Objectcount()<<endl;
}