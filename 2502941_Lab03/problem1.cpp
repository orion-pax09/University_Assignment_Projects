#include <iostream>
using namespace std;
int sum_yearly(int *Ptr , int n){
    int sum = 0;
    for (int i = 0 ; i < n ; i ++){
    cout << "Enter the month " << i+1<<": ";
    cin >>Ptr[i];
    }
    cout << "------yearly sum------ " <<endl;
    for (int i = 0 ; i < n ; i++){
        sum += Ptr[i];
    }
    return sum;
}
int average(int*ptr , int size , int sum){
    int count = 0 ;
    for (int i = 0 ; i < size ; i++){
        if (ptr[i]){
            count++;        
        }
    }
    if (count ==0){
        return 0;
    }
    int Average = sum / count;
    return Average;
}
int main(){
    int month;
    cout << "Enter the month: ";
    cin >> month;
    int* ptr = new int [month];
    int SUM = sum_yearly(ptr , month);
    int Average = average(ptr , month , SUM);
    cout << "Yearly sales sum: "<<SUM<<endl;  
    cout << "Average: "<<Average; 
    delete [] ptr;
    ptr = nullptr;
}