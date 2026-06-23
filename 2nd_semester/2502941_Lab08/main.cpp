#include <iostream>
#include "Complex.h"
using namespace std;
int main()
{
    int button;
    Complex C1;
    Complex C2(5,6);
    Complex C3;
    Complex C4;
    do
    {
        int button;
        cout << "Press 1 to test input and output"<<endl;
        cout <<" PRESS 2 to test == operator between C1 & C2 "<<endl;
        cout << "Press 3 to test == operator between C1 & C3"<<endl;
        cout << "Press 4 to test - operator overloading for C4"<<endl;
        cout <<" press 5 to test postfix C1++ to C4"<<endl;
        cout << "Press 6 to test postfix decrement of C1 to C4"<<endl;
        cout << "Press 7 to test prefix increment of  C1 to C4"<<endl;
        cout << "Press 8 to test prefix decrement of C1 to C4 "<<endl;
        cout << "press 9 tp test Multiplication operator overloading between C1*C2"<<endl;
        cout << "Press 10 to perform division operator overloading between C1 and C2"<<endl;
        cout << "Press 0 key to exit: "<<endl;
        cin>>button;
        switch (button)
        {
        case 1:
         cout << "Input a complex number"<<endl;
         cin >> C1;
         C1.Printoutput();
         break;
        case 2:
        if (C1==C2){
            cout << "C1==C2"<<endl;
        }
        else{
            cout << "C1!=C2"<<endl;
        }
        break;
        case 3:
        if (C1 !=C3){
            cout <<"C1!=C3"<<endl;
        }
        else{
            cout<<"C1==C2"<<endl;
        }
        break;
        case 4:
        C4 = C2 - C3;
        cout <<"C4=C2-C3"<<endl;
        C4.Printoutput();
        break;
        case 5:
        C4 = C1++;
        cout <<"C4=C1++: "<<endl;
        C4.Printoutput();
        break;
        case 6:
        C4=C1--;
        cout << "C4=C1--: "<<endl;
        C4.Printoutput();
        break;
        case 7:
        C4 = ++C1;
        cout <<"C4=++C1: "<<endl;
        C4.Printoutput();
        break;
        case 8:
    C4=--C1;
    cout<<"C4=--C1 :"<<endl;
    C4.Printoutput();
    break;
    case 9:

    C4 = C1*C2;
    cout <<"C4 = C1*C2: "<<endl;
    C4.Printoutput();
    break;
    case 10:
    C4 = C1/C2;
    cout << "C4 = C1/C2: "<<endl;
    C4.Printoutput();
    break;
        default:
        cout << "Press any key to contiunue"<<endl;
            break;
        }
    } while (button!=0);
}
