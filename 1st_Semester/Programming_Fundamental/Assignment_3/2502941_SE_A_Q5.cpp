/*
Name ;- Muhammad Hamza Khan
ROll No:- 2502941
Assignment No. 3
Question No. 5
*/
#include <iostream>
using namespace std;
int main(){
    int n;
    cout << "Enter the number:"<<endl;
    cin >> n;
    int sign = 1;
    long long sum = 0;
    while (n>0){
        int reminder= n % 10;
        sum += reminder * sign;
        sign *=-1;
        n = n/10;
        cout << sum <<endl;
    }
    if (sum % 11==0){
        cout << sum << " is divisible by 11."<<endl;
    }
    else{
        cout << sum << " is not divisible by 11."<<endl;
    }
}
