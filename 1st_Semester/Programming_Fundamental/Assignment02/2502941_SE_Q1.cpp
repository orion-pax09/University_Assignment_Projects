/*Name:-
Muhammad Hamza Khan*/
/*Program:-
SE_A*/
/*Roll Number:- 
2502941*/

/*Question no. :
252941_SE_A_Q1.cpp*/
#include <iostream>
using namespace std;
int main(){
    /*Declaring 3 variable for entering 3 number*/
    int a,b,c;
    cout << "Enter the value for a"<<endl;
    cin >> a;
    cout << "Enter the value for b"<<endl;
    cin >> b;
    cout << "Enter the value for c"<<endl;
    cin >> c;
    /*Using nested ternary operation to find largest for 3*/
    int result1 = ( a > b ) ?  (( a > c ) ? a : c ) : (( b > c ) ? b : c);
    cout << "Largest for entering 3 number is:"<< result1<<endl;
    cout << "-------------------------------------------------------"<<endl;
    int d,e,f,g;
    cout << "Enter the value for d"<<endl;
    cin >> d;
    cout << "Enter the value for e"<<endl;
    cin >> e;
    cout << "Enter the value for f"<<endl;
    cin >> f;
    cout << "Enter the value for g"<<endl;
    cin >> g;
    /*int result2 = (d>e && d>f&& d>g)? d : (e>f && e>g)? e :  (f>g)? f : g;*/
    int result2 = (d>e)?((d>f)? ((d>g)? d:g): ((f>g)?f:g)):((e>f)?((e>g)?e:g):((f>g)?f:g));
    cout << "Largest for entering 4 number is:"<< result2<<endl;
    return 0;
}
