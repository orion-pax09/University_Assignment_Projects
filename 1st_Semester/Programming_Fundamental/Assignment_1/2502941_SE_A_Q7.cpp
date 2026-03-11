#include <iostream>
#include <iomanip>
using namespace std;
int main() {
    int value;
    int Hours;
    int Minutes;
    int Seconds;
    cout << "Enter a Two-byte Time value:";
    cin >> value;
    Hours=(value >> 12)& ((1<<4)-1);
    cout << Hours << endl;
    Minutes=(value >> 6)& ((1<<6)-1) ;
    cout << Minutes << endl;
    Seconds = value & ((1<<6)-1);
    cout << Seconds << endl;
    cout << Hours << setw(1) << "Hour" << setw(3) << Minutes << setw(2) << "Minutes" << setw(3) << Seconds << setw(2)<< "seconds"<< endl;


return 0;
}

