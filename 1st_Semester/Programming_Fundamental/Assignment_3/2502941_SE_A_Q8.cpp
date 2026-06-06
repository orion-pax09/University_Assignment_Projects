/*
Name ;- Muhammad Hamza Khan
ROll No:- 2502941
Assignment No. 3
Question No. 8
*/
#include <iostream>
using namespace std;
int main(){
    int apartment_unit=50;
    int rent;
    cout << "Enter the current charges to occupy: "<<endl;
    cin>> rent;
    int increase_rent;
    cout << "Enter the amount to increase rent charges: "<<endl;
    cin >> increase_rent;
    int maintain;
    cout << "Enter the amount to maintain a rented unit: "<<endl;
    cin >> maintain;
    int new_profit = -1;
    int current_unit=0;
    for (int i = 0 ; i <=apartment_unit;i++){
        int remaining_unit = apartment_unit - i;
        double total_charges= rent + ( increase_rent * i) ;
        double profit = remaining_unit * (total_charges - maintain);
        if (profit > new_profit){
            new_profit = profit;
            current_unit = remaining_unit;
        }
        cout << "--------------------------------"<<endl;
        cout << i << endl;
        cout <<"Total rent charges: "<< total_charges <<endl;
        cout << "New profit earned : $"<<new_profit<<endl;
        cout << "Remaining apartment units: "<<current_unit<<endl;

    }
}