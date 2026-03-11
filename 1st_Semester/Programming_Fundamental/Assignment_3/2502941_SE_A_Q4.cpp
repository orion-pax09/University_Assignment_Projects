/*
Name ;- Muhammad Hamza Khan
ROll No:- 2502941
Assignment No 3
Question no. 4
*/
#include <iostream>
using namespace std;
int main(){
    int town_A;
    cout << "Enter the population of town A: ";
    cin >> town_A;
    int town_b;
    cout << "Enter the population of town B: ";
    cin >> town_b;
    int growth_rateA;
    cout << "Enter the growth rate of Town A: ";
    cin >> growth_rateA;
    int growth_rateB;
    cout << "Enter the growth rate of Town B: ";
    cin >> growth_rateB;
    if (growth_rateA <= growth_rateB){
        cout << "Enter the growth rate of town A greater than B:";
    }
    if ( town_A > town_b){
        cout << "Enter the population of town A less than town B";
    }
    int yeats=0;
    while (town_A <= town_b){
        town_A = town_A + (town_A * growth_rateA / 100);
        town_b = town_b + (town_b * growth_rateB/100);
        yeats++;
    }
    cout << "Population of town A after  "<< yeats<<"years "<<town_A<<endl;
    cout << "Population of town B after  "<< yeats<<"years "<< town_b<<endl;
}