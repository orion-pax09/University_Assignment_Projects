#include  <iostream>
#include <cctype>
using namespace std;
int main()
{
    char letter;
    cout << "Enter the letter:"<< endl;
    cin >> letter;
    char lower= tolower(letter);
    cout << lower << endl;
    return 0;
}
