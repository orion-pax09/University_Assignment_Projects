#include <iostream>
using namespace std;
class Box{
    private:
    double length ; 
    double breadth ; 
    double height;
    static int objectcount;
    public:
    Box(){
        length = 0.0;
        breadth = 0.0;
        height = 0.0;
        objectcount++;
    }
    Box(double l , double b , double h){
        length = l;
        breadth = b ;
        height = h;
        objectcount++;
    }
    void setlength(double l){
        length = l;
    }
    double getlength(){
        return length;
    }
    void setbreadth(double b){
        breadth = b;
    }
    double getbreadth(){
        return breadth;
    }
    void setheight(double h){
        height = h;
    }
    double getheigth(){
        return height;
    }
    
    static int getcount(){
        return objectcount;
    }
    double volume(){
        return length*breadth*height;
    }
    double Area(){
        return length*breadth;
    }
    void display(){
        cout << "Length: "<<length<<endl;
        
        cout << "breadth: "<<breadth<<endl;
        
        cout << "height: "<<height<<endl;

        cout << "Area: "<<Area()<<endl;

        cout << "Volume: "<<volume()<<endl;
        cout <<"----------------------------------"<<endl;
    }

};
int Box::objectcount = 0;

double print_Surface_Area(Box&b){
    double l = b.getlength();
    double h = b.getheigth();
    double B = b.getbreadth();
    double SA = 2*l*B*h;
    return SA;
}
double double_data_members(double&length , double&breath , double&height){
    length = length*2;
    breath = breath*2;
    height=height*2;
    return length , breath , height;
}
int main(){

    cout << "========Constructor calling========"<<endl;
    Box b1(3.2 , 5.6 , 7.8);
    b1.display();
    b1.getcount();

    Box b2(8.9 , 4.6 , 7.6);
    b2.display();
    b2.getcount();
    b1.setbreadth(4.3);
    b1.setlength(7.6);
    b1.setheight(7.6);

    cout << "======== Setter & Getters========"<<endl;

    cout << "b1 Length  : " << b1.getlength()  << endl;
    cout << "b1 Breadth : " << b1.getbreadth() << endl;
    cout << "b1 Height  : " << b1.getheigth()  << endl;

    b1.setbreadth(4.3);
    b1.setlength(7.6);
    b1.setheight(7.6);

    cout << "b2 Length  : " << b2.getlength()  << endl;
    cout << "b2 Breadth : " << b2.getbreadth() << endl;
    cout << "b2 Height  : " << b2.getheigth()  << endl;

    cout << "========Non-Member Fucntions========"<<endl;
    double b = b1.getlength();
    double l = b1.getlength();
    double h = b1.getheigth();

    cout << "Surface Area: "<<print_Surface_Area(b1)<<endl;
    double_data_members(l , b , h);
    cout << "Length of b1: "<< l<<endl;
    cout << "Breadth of b1: "<<b<<endl;
    cout << "Height of b1: "<<h<<endl;
}