#include <iostream>
using namespace std;
int main(){
int n;
cout << "Enter the array size: ";
cin >> n;
float* arr = new float [n];
float max = arr[0];
for (int i = 0 ; i < n ; i++){
cin >> arr[i];
}
for (int i = 0 ; i < n ; i++){
cout << arr[i] << " | ";
}
// to find maximum value
cout << endl;
for (int i = 0 ; i < n ; i++){
if (max < arr[i]){
max = arr[i];
}
}
// to find second maximum value
float second_max=arr[0];
int index = 0;
for (int i = 0 ; i < n ; i++){
if (second_max < arr[i] && arr[i] != max){
second_max = arr[i];
index = i;
}
}
cout << "Second Largest element is: "<<second_max<<endl;
cout << "Index of second largest element is: "<< index<<endl;
delete [] arr;
arr = nullptr;
arr = 0;
}