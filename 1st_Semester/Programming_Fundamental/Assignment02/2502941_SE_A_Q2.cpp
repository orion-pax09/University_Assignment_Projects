/*Name:-
Muhammad Hamza Khan*/
/*Roll Number:- 
2502941*/
/*Program:-
SE_A*/
/*Question no. :
252941_SE_A_Q1.cpp*/
#include <iostream>
using namespace std;
int main(){
    /*Declaring variable for month*/
int month;
    /*Declaring variable for day*/
int day;
cout << "Enter the day:"<<endl;
cin >>day;
/*Ensure that users only enter days between 1 and 31*/

if (day<1 || day >31){
    cout << "Enter the day between 1 and 31"<<endl;
    return 0;
}
cout << "1.Janruary"<<endl;
cout << "2.February"<<endl;
cout << "3.March"<<endl;
cout << "4.April"<<endl;
cout << "5.May"<<endl;
cout << "6.June"<<endl;
cout << "7.July"<<endl;
cout << "8.August"<<endl;
cout << "9.September"<<endl;
cout << "10.October"<<endl;
cout << "11.November"<<endl;
cout << "12.December"<<endl;
cout << "Enter the month in number from 1 to 12:"<<endl;
cin >>month;
/*Ensure that users only enter month between 1 and 12*/
if (month<1 || month > 12){
    cout << "Invalid input. Enter the month between 1 and 12.";
}
/*Ensure that users enters days between 1 and 28 for february*/
if (month == 2 && day > 28){
        cout << "February does not have day greater than 28.";
        return 0;
    }
else{
    /*Use double bracket to control number of days for a specific month */
    if ((month==12 && day >15)|| (month == 1&& day <31) || (month ==2 && day < 28) || (month ==3 && day <=15)){
    cout << "It is Winter";
    }
    else if ((month==3 && day>=16) || month == 4 || month ==5 || (month ==6 && day <= 15)){
    cout << "It is Spring";
    }
    else if ((month==6 && day>=16) || month == 7 || month ==8 || (month ==9 && day <= 15)){
    cout << "It is Summer";
    }
    else if ((month==9 && day>=16) || month == 10 || month ==11 || (month ==12 && day <= 15)){
    cout << "It is Fall";
    }
    else {
        cout << "Invalid Input.";
    }
    return 0;
}
}
