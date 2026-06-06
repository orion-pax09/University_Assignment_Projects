#include <iostream>
using namespace std;

// Swap function using pointers
void swapvalue(int *p1, int *p2)
{
    int temp = *p1;
    *p1 = *p2;
    *p2 = temp;
}

int main()
{
    int num1 = 50;
    int num2 = 70;

    cout << "Before swapping" << endl;
    cout << "Num 1: " << num1 << "  Num 2: " << num2 << endl;

    // Pass addresses of variables
    swapvalue(&num1, &num2);

    cout << "After swapping" << endl;
    cout << "Num 1: " << num1 << "  Num 2: " << num2 << endl;

    return 0;
}
