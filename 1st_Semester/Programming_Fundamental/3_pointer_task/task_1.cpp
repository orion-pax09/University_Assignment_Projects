#include <iostream>
using namespace std;

// Swap function using reference
void swapvalue(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

int main()
{
    int num1 = 50;
    int num2 = 70;

    cout << "Before swapping" << endl;
    cout << "Num 1: " << num1 << "  Num 2: " << num2 << endl;

    // Function call (no & needed here)
    swapvalue(num1, num2);

    cout << "After swapping" << endl;
    cout << "Num 1: " << num1 << "  Num 2: " << num2 << endl;

    return 0;
}
