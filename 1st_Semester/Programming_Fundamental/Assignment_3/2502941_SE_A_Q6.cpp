/*
Name ;- Muhammad Hamza Khan
ROll No:- 2502941
Assignment No 3
Question no. 6
*/
#include <iostream>
using namespace std;
int main(){
    int n1,n2;
    cout << "Enter the number 1:"<<endl;
    cin>>n1;
    cout << "Enter the number 2:"<<endl;
    cin >> n2;
    int six_task=0;
    int i = n1;

                if(n1>n2){
        cout << "Invalid.Enter the number 2 greater than number 1"<<endl;
    }
    else{
    cout << "-------------------task A--------------------------"<<endl;

    while (i <= n2){

        if (i%2==1)
        {
        cout << i <<endl;
    }
    i++;
    }
    cout << "--------------------task B------------------------"<<endl;
    int m=n1;
    int sum1=0;
    while (m<n2){
        if (m%2==1){
            sum1= sum1 + m ;
        }
        m++;
    }
    cout << "Sum of odd  number from"<<" "<<n1<<" "<< "to"<<" " << n2<<" "<<"is "<<" "<<sum1 <<endl;   


    cout << "--------------------task C------------------------"<<endl;
    int k = n1;
    int sum=0;
    while (k < n2){
        if (k%2==0){
        sum = sum + k;
    }
    k++;
}
    cout << "Sum of even number from"<<" "<<n1<<" "<< "to"<<" " << n2<<" "<<"is "<<" "<<sum <<endl;   
    cout << "--------------------task D------------------------"<<endl;
    int z= n1;
    int square;
    while(z<=n2){
    cout <<"Square of"<<" "<< z <<" " <<"is"<<" "<< z*z<<endl;
    z++;
}
    cout << "--------------------task E------------------------"<<endl;
    int sum3=0;
    int n=n1;
    while (n<n2){
        if (n%2==1){
            sum3= sum3 + (n*n) ;
        }
        n++;
    }
    cout << "Sum of  square of odd  number from"<<" "<<n1<<" "<< "to"<<" " << n2<<" "<<"is "<<" "<<sum3 <<endl;   
    cout << "--------------------task F------------------------"<<endl;
    int asciicode=n1;
    while(asciicode<n2){
        if(asciicode>=65 && asciicode <=90){
        cout << char(asciicode)<<endl;
        }
        else{
            cout << "No upper case letter in this range for"<<" "<<asciicode<<endl;
        }
        asciicode++;

    }
}

}
