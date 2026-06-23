#include <iostream>
using namespace std;
class Shape{
    public:
    virtual void draw()=0;
    virtual ~Shape(){
        cout << "Shape destoryed"<<endl;
    }
};
class Circle:public Shape{
    private:
    int radius;
    public:
    Circle(int r):radius(r){
    }
    void draw() override{
        float area = 3.14 * radius * radius;
        cout << "Draw Circle of area "<<area<<endl;
    }
    ~Circle(){
        cout << "~Circle() called"<<endl;
    }
};
class Square:public Shape{
    private:
    int length;
    public:
    Square(int l):length(l){
    }
    void draw() override{
        cout << "draw the square of area "<<length*length<<endl;
    }
    ~Square(){
    cout << "~Square() called"<<endl;
    }
};
class Triangle:public Shape{
    private:
    int base;
    int height;
    public:
    Triangle(int b , int h):base(b) , height(h){
    }
    void draw() override{
        float area = 0.5 * base * height;
        cout << "Draw the height and base triangle of area "<< area <<endl;
    }
    ~Triangle(){
        cout << "~Triangle() called"<<endl;
    }
};

int main(){
    Shape*p[20];
    int n;
    cout << "Enter the number of shapes: "<<endl;
    cin >> n;
    for (int i = 0 ; i < n ; i++){
        int choice;
        cout << "Enter the choice: "<<endl;
        cout << "Enter 1 for circle"<<endl;
        cout << "Enter 2 for square"<<endl;
        cout << "Enter 3 for triangle"<<endl;
        cin >> choice;
        switch (choice)
        {
        case 1:{
        int r;
        cout << "Enter the radius :"<<endl;
        cin >> r;
        p[i] = new Circle(r);
        break;
        }
        case 2:{
        int L;
        cout << "Enter the side square meter of length"<<endl;
        cin >> L;
        p[i] = new Square (L);
        break;
        }
        case 3:{
        int H ; int B;
        cout << "Enter the base: "<<endl;
        cin >> B;
        cout << "ENter the height: "<<endl;
        cin >> H;
        p[i] = new Triangle (B,H);
        break;
        }
        default:{
        cout << "Invalid. Enter 1-3"<<endl;
        i--;
            break;
        }
        }
    }
    for (int i = 0 ; i < n ; i ++){
        p[i]->draw();
    }
    cout << "==========Deleting objects=========="<<endl;
    for (int i = 0 ; i < n ; i++){
        delete p[i];
    }
}