/*
Name ;- Muhammad Hamza Khan
ROll No:- 2502941
Assignment No. 3
Question No. 10
*/
#include <iostream>
using namespace std;
int main(){
    int month;
    cout << "Enter the number of month: ";
    cin>> month;
    if (month <=2){
        cout << "Rabbit total pairs: "<<1<<endl;
    }
    long long first_pair=1;
    long long second_Pair =1;
    long long total_Pair=0;
    int n=3;
    while ( n <= month){
        total_Pair = first_pair + second_Pair;
        first_pair = second_Pair;
        second_Pair = total_Pair;
        n++;
    }
    cout << "Rabbit total pairs: "<<second_Pair<<endl;
}