/*Name:-
Muhammad Hamza Khan*/
/*Roll Number:- 
2502941*/
/*Program:-
SE_A*/
/*Question no. :
252941_SE_A_Q1.cpp*/
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;
int main(){
    int number_1;     /*Users will enter first squares number*/
   
    int number_2;     /*Users will enter second squares number*/
   
    string ColorA;   /* ColorA will be declared as variable for different number of each squares when users enter first squares numbers 
                      and it keeps getting updates when new color is entered for each square's number*/
   
    string ColorB;   /* ColorB will be declared as variable for different number of each squares when users enter second squares numbers
                      and it keeps getting updated when new color is entered for each square's number*/

    
    /*We make rows and coloumn table to make square which has different color for each different blocks inside squares */
    cout << setw(2)<< "1"<<setw(2)<<" "<<setw(2)<<"2"<<" "<<setw(2)<<"3"<<setw(5)<<"4"
    <<setw(2)<<" "<<setw(2)<<"5"<<" "<<setw(2)<<"6"<<endl<<setw(2)
    <<"7"<<" "<<setw(3)<<"8"<<" "<<setw(2)<<"9"<<setw(3)
    <<" "<<setw(1)<<"10"<<setw(2)<<" "<<"11"<<setw(2)
    <<" "<<"12"<<setw(2)<<endl<<"13"<<setw(2)
    <<" "<<"14"<<setw(2)<<" "<<"15"<<setw(2)<<" "<<"16"<<setw(2)
    <<" "<<"17"<<setw(2)<<" "<<"18"<<setw(2)<<endl<<"19"<<setw(2)
    <<" "<<"20"<<setw(2)<<" "<<"21"<<setw(2)<<" "<<"22"<<setw(2)<<" "<<"23"
    <<setw(2)<<" "<<"24"<<setw(2)<<endl<<"25"<<setw(2)<<" "<<"26"<<setw(2)
    <<" "<<"27"<<setw(2)<<" "<<"28"<<setw(2)<<" "<<"29"<<setw(2)<<" "<<"30"
    <<setw(2)<<endl<<"31"<<setw(2)<<" "<<"32"<<setw(2)<<" "
    <<"33"<<setw(2)<<" "<<"34"<<setw(2)<<" "<<"35"<<setw(2)<<" "<<"36"<<setw(2)<<endl;
    
    cout << "Enter the first square number(1-36):";
    cin >> number_1;
    cout << "Enter the second square number(1-36):";
    cin >> number_2;
    
    /*Users should only enter the numbers between 1 and 36*/
    if (number_1 > 36 || number_2>36)
    {
        cout << "Invalid input.Enter the number between 1 and 36";
    }
    else{
        switch(number_1){
            case 1: 
            case 6:
            case 7:
            case 12:
            case 17:
            case 20:
            case 28:
            case 33:
            ColorA = "Green";
            break;
            case 2:
            case 11:
            case 13:
            case 18:
            case 19:
            case 24:
            case 29:
            case 32:
            ColorA ="Red";
            break;
            case 3:
            case 10:
            case 14:
            case 23:
            case 25:
            case 30:
            case 31:
            case 36:
            ColorA ="Blue";
            break;
            case 4:
            case 9:
            case 15:
            case 22:
            case 26:
            case 35:
            ColorA="Orange";
            break;
            case 5:
            case 8:
            case 16:
            case 21:
            case 27:
            case 34:
            ColorA="Grey";
            break;
            default:
            break;}
        switch (number_2)
            {case 1: 
            case 6:
            case 7:
            case 12:
            case 17:
            case 20:
            case 28:
            case 33:
            ColorB= "Green";
            break;
            case 2:
            case 11:
            case 13:
            case 18:
            case 19:
            case 24:
            case 29:
            case 32:
            ColorB="Red";
            break;
            case 3:
            case 10:
            case 14:
            case 23:
            case 25:
            case 30:
            case 31:
            case 36:
            ColorB ="Blue";
            break;
            case 4:
            case 9:
            case 15:
            case 22:
            case 26:
            case 35:
            ColorB= "Orange";
            break;
            case 5:
            case 8:
            case 16:
            case 21:
            case 27:
            case 34:
            ColorB ="Grey";
            break;
            default:
                break;
            }

            /*If any colors from first square number is as same as any colors from B then output will show that they have same color*/
            
            if (ColorA==ColorB)
            {
            cout << "Colors are matching"<<endl<<number_1<<"'s color is:"<<ColorA <<endl<< number_2<<"'s Color is:"<< ColorB;
                
            }
        else{
            cout << "Colors are not matching"<<endl<<number_1<<"'s color is:"<<ColorA <<endl<< number_2<<"'s Color is:"<< ColorB;

                }

    }

}