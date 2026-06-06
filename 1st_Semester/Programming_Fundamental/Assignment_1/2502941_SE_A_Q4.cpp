#include <iostream>
#include <cmath>
using namespace std;
int main() {
    int a;
    int i;
    int b;
    const int u=3,p=4;
    cout << "Enter the value of a:";
    cin >> a;
    cout << "Enter the value of b:";
    cin >> b;
    cout << "Enter the value of i:";
    cin >> i;
    double numerator= sqrt(u*(pow(i,a/b)* pow(i,2)-1));
    double denominator=  sqrt(p*i-2) + sqrt(p*i - 1);
    cout << "Result:"<< numerator/denominator << endl;
    return 0;
}