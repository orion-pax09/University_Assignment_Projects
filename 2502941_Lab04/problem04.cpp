#include <iostream>
#include <cmath>
using namespace std;
class POINT
{
private:
float X;
float Y;
float Z;
public:

////setter function for data members

void setPOINT (float m, float n, float o){
    if (m > 0 && n > 0 && o > 0){
        X = m;
        Y = n;
        Z = o;
        
    }
    else{
        cout << "X,Y,Z must be positive." << endl;
    }
};

void setX(float x){
    if (x<10){
        X = x;
    }
    else{
        cout << "X must be less than 10." << endl;
    }
};

void setY(float y){
    if (y<10){
        Y = y;
    }
    else{
        cout << "Y must be less than 10." << endl;
    }
};

////getter function

void getPOINT(float& x, float& y, float& z) const {
    x = X;
    y = Y;
    z = Z;
};

float getX() const{
    return X;
};

float getY() const{
    return Y;
};

//Public Member Functions

////member function to take input

void input (){
    cout << "Enter the X coordinate: ";
    cin >> X;
    cout << "Enter the Y coordinate: ";
    cin >> Y;
    cout << "Enter the Z coordinate: ";
    cin >> Z;
};

////member function output

void output(){
    if ( X>0 && Y > 0 && Z > 0){
        cout << "This point is within the rectangle"<<endl;
        cout << "X value: "<<X<<endl;
        cout << "Y value: "<<Y<<endl;
        cout << "Z value: "<<Z<<endl;
    }
    else{
        cout << "This point is outside the point of rectanlge"<<endl;
        cout << "X value: "<<X<<endl;
        cout << "Y value: "<<Y<<endl;
        cout << "Z value: "<<Z<<endl;
    }
}

////member function to calculate distance between two points

float Calculate_Distance (const POINT&p1 , const POINT&p2){
    float distance = sqrt(
        pow(p2.X - p1.X,2)+ 
        pow(p2.Y - p1.Y,2) +
        pow(p2.Z - p1.Z,2)
    );
    return distance;

};
// Print the point
void printPoint (const POINT&p1 , const POINT&p2){
    cout << "X value is: "<<p1.getX()<<endl;
    cout << "Y value is: "<<p2.getY()<<endl;
};
//Calculate and return closest point
POINT find_closest (const POINT&p1 , POINT&p2){
    float d1 = Calculate_Distance(p1 , p2);
    float d2= Calculate_Distance(p2,p1);
    if (d1 > d2){
        return p2;
    }
    else{
        return p1;
    }
};
};
int main(){
POINT p, P1, P2;

// Input values for each point
cout << "Enter main point:\n";
p.input();

cout << "Enter first point:\n";
P1.input();

cout << "Enter second point:\n";
P2.input();

// Display all points
p.output();
P1.output();
P2.output();

// Calculate distance
float distance = P1.Calculate_Distance(P1,P2);
cout << "Distance between P1 and P2: " << distance << endl;

// Find closest point to main point
POINT closest = p.find_closest(P1, P2);
cout << "Closest point to main point is: "<<endl;
closest.output();
}
