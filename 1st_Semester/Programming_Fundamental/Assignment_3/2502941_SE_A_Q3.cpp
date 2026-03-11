/*
Name :- Muhammad Hamza Khan
ROll No:- 2502941
Assignment No 3*
Question no.3*/
#include <iostream>
using namespace std;
int main(){
int x;
cout << "Enter the number of x:"<<endl;
cin >> x;
int update=0;
int count=0;
while(x!=1){
    if(x%2==0){
        update=x/2;
    }
    else{
        update= (3*x)+1;
    }
    count++;
    x=update;
    cout << x <<endl;
}
    cout << "It took"<< " "<<count <<" "<< "steps to become 1"<<endl;
}