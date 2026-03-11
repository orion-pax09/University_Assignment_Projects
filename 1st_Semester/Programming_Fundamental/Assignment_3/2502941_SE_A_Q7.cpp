/*
Name ;- Muhammad Hamza Khan
ROll No:- 2502941
Assignment No 3
Question no. 7
*/
#include <iostream>
#include <math.h>
#include <iomanip>
using namespace std;

int main(){
    double pi = 3.14;
    double r;
    cout << "Enter the radius (r):"<<endl;
    cin >> r;
    double max_volume=0;
    double x=0;
    int steps=0;
    int max_x=0;
    double circumeference = 2 * 3.14 * r;
    while (x <= circumeference)
    {
        double new_cut_circum= circumeference - x;
        double R = new_cut_circum /( 2 * 3.14);
        double height = pow((r*r)-(R*R),0.5);
        double volume = (1.0/3.0) * 3.14 * R * R * height;
        steps +=1;
        if (volume > max_volume){
            max_volume = volume;
            max_x = x;
        }
        x += 0.0254;
    }
        cout << fixed << setprecision(2)<< "Maximum volume: " << max_volume<<" m^3" << endl;
        cout << fixed << setprecision(2)<< "Maximum x part of arc length: " << max_x <<" m" <<endl;
        cout << "It took: "<< steps<<endl;
}