/*
Name :- Muhammad Hamza Khan
ROll No:- 2502941
Assignment No 3*
Question no. 1*/
#include <iostream>
using namespace std;
int main(){
    int n;
    cout << "Enter the number of locker:"<<endl;
    cin >> n;
    if (n<0 || n>1000){
        cout << "Enter the number between 1 and 1000"<<endl;
    }
    else{
    int open_count=0;
    for (int locker=1; locker<=n;locker++){
    int visit_count=0;
        for (int student_num=1; student_num <=n; student_num++){
            if (locker%student_num==0){
            visit_count++;
            }
    }
    if(visit_count%2==1){
        open_count++;
    }
}
    cout << "Total Number of locker opened"<<" "<<open_count<< " "<<"lockers"<<endl;
}
}
