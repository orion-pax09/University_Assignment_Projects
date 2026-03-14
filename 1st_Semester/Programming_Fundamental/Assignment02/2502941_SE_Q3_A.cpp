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
    /*Input for harndess of steel*/
    int input1;
    /*Input for carbon content*/
    float input2;
    /*Input for force limit of steel before breaking*/
    int input3;
    cout << "(i) How hardness the steel is:";
    cin >> input1;
    cout << "(ii) How much carbon it has?";
    cin >>input2;
    cout << "(iii) How much force it can handle before breaking:";
    cin >> input3;
    int hardness=50;
    float carbon_content=0.7;
    int tensile_Strength=5600;
    int grade1=10;
    int grade2=9;
    int grade3=8;
    int grade4=7;
    int grade5=6;
    int grade6=5;
    /*If all conditions are true*/
    if (input1>50 && input2<0.7 && input3>5600){
        cout << "All three condition are true"<<endl;
        cout<< "Grade:"<<" "<<grade1;
    }
    /*If only 1 and 2 condition are true*/
    else if (input1>50 && input2<0.7 && input3<5600){
        cout << "Only (i) and (ii) condition are true"<<endl;
        cout<< "Grade:"<<" "<<grade2;
    }
    /*If onlt i and iii condition are true*/
    else if (input1>50 && input2>0.7 && input3>5600){
        cout << "Only (i) and (iii) condition are true"<<endl;
        cout<< "Grade:"<<" "<<grade4;
    }
    /*If both 2 and 3 condition are true*/
    else if (input1<50 && input2<0.7 && input3>5600){
        cout << "Only (ii) and (iii) condition are true"<<endl;
        cout<< "Grade:"<<" "<<grade3;
    }
    /*For only one true condition*/
    else if (input1>50 && input2>0.7 && input3<5600 ||input1<50 && input2>0.7 && input3>5600 || input1<50 && input2<0.7 && input3<5600){
        cout << "Only one condition meets true"<<endl;
        cout<< "Grade:"<<" "<<grade5;
    }
    /*If none of condition is true*/
    else if (input1<50 && input2>0.7 && input3<5600){
        cout << "None of condition is true"<<endl;
        cout<< "Grade:"<<" "<<grade6;
    }
    /*Invalid for entering wrong input*/
    else{
        cout << "Invalid input";
    }
    return 0;
}





