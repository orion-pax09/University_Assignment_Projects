#include <iostream>
#include <bits/atomic_lockfree_defines.h>
using namespace std;

int main()
{
    double Withholding_Tax;
    double Hourly_wage;
    double Several_Hours_worked;
    double Gross_pay;
    double Net_pay;
    cout << "Enter Hourly wage:" << endl;
    cin >> Hourly_wage;
    cout << "Hours worked:" << endl;
    cin >> Several_Hours_worked;
    cout << "Withholding tax (%)"<<endl;
    cin >> Withholding_Tax;
    Gross_pay = Hourly_wage*Several_Hours_worked;
    Net_pay = Gross_pay * (1 - Withholding_Tax/100);
    cout << "Net pay:"<< Net_pay <<endl;
    return 0;
}






