#include <iostream>
using namespace std;
int main(){
int size;
cout << "Enter the number: ";
cin >> size;
int* arr = new int [size];
arr[0] = 1;
arr[1] = 1;
for (int i = 2 ; i < size ; i++ ){
arr[i] = arr [i-1] + arr [i-2];

}
for (int i = 0 ; i < size ; i++ ){
cout << arr[i] <<" ";
}
delete [] arr;
arr = nullptr;
arr = 0;
}

