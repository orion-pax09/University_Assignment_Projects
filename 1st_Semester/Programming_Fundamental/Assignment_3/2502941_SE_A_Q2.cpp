/*
Name :- Muhammad Hamza Khan
ROll No:- 2502941
Assignment No. 3*
Question no. 2*/
#include <iostream>
using namespace std;
int main(){
    int Loan_Amount;
    float Annual_interest;
    int monthly_payment;
    cout << "Enter the loan amount:"<<endl;
    cin>>Loan_Amount;
    cout << "Enter the annual interest:"<<endl;
    cin>>Annual_interest;
    cout << "Enter the monthly payment:"<<endl;
    cin>>monthly_payment;
    float monthly_rate;
    float interest;
    float principal_amount;
    float current_loan=Loan_Amount;
    int current_month=0;
    monthly_rate= Annual_interest / 100 /12;
    while (Loan_Amount > 0){
        interest = monthly_rate * Loan_Amount;
        principal_amount = monthly_payment - interest;
        if(monthly_payment <= interest){
            cout<< "Monthly payment too low."<<endl;
            break;
        }
        else{
            current_loan = Loan_Amount - principal_amount;
            Loan_Amount = current_loan;
            current_month++;
            if(Loan_Amount <0){
                break;
            } 
        }
    }
        cout << "It will take"<<" "<<current_month <<" "<<"month to clear debt successfully."<<endl; 
}