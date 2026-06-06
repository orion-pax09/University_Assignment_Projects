#include <iostream>
using namespace std;
//exercise 1
int* InputArray(int& size){
cout << "Enter the size of array: ";
cin >> size;
int*array = new int [size];
cout << "Enter the array elements: "<<endl;
for (int i = 0 ; i < size  ; i++){
cin >> array[i];
}
return array;

}
//exercise 2
void OutputArray(int* myArray, const int& size){
for (int i = 0 ; i < size ; i++){
cout << myArray[i]<<" ";
}
cout << endl;
}
//exercise 3
int* CompressArray(int* originalArr, int& size){
    for (int i = 0 ; i < size - 1 ; i++){
        for(int j = 0 ; j < size - i - 1 ; j++){
            if (originalArr[j] < originalArr[j+1]){
            int temp = originalArr[j+1];
            originalArr[j+1] = originalArr[j];
            originalArr[j] = temp;
            }
        }        
    }
    // declare new variable for new index
    int x = 0;
    for (int i = 0 ; i < size-1 ; i++){
       // searching each element which is not duplicated
            if (originalArr[i] != originalArr [i+1]){
                originalArr[x] = originalArr[i];
                x = x+1;
            }
        }
        // if there is duplicated element then reduce size of original array
        originalArr[x]=originalArr[size - 1];
        x++;
        // original size of array = size of new index
        size = x;
        return originalArr;
    }
int main(){
int n;
int* array = InputArray(n);
cout << "Original array"<<endl;
OutputArray(array , n);
int* ptr = CompressArray(array, n);
if (ptr == nullptr ){
    cout << "Sorry did not find anything else"<<endl;
}
cout << "Array after compression"<<endl;
for (int i = 0 ; i < n ; i++){
    cout << array[i] <<" ";
}
cout << endl;
// avoid delete and dangling pointerz
delete [] array;
array = nullptr;
delete ptr;
ptr = nullptr;
}
