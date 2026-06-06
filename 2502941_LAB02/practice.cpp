#include <iostream>
using namespace std;
int* inputarray(int&size){
    int*array = new int [size];
    cout << "Enter the elements: ";
    for (int i = 0 ; i < size ; i++){
        cin >> array[i];
    }
    return array;
}
void OutputArray(int*myArray , const int&size){
    for (int i = 0 ; i < size ; i++){
        cout <<myArray[i]<<" "; 
    }
    cout << endl;
}
int*CompressArray(int*originalArr , int&size){
    for (int i = 0 ; i < size - i - 1 ; i++){
        for (int j = 0 ; j < size-1 ; j++){
            if (originalArr[j]>originalArr[j+1]){
                swap(originalArr[j] , originalArr[j+1]);
            }
        }
        int k = 0;
        int*newarray = new int [size];
        newarray[k++] = originalArr[0];
        for (int i = 0 ; i < size-1 ; i++){
            if (originalArr[i]!=originalArr[i+1]){
                newarray[k++] = originalArr[i];
            }
        }
        size = k ;
        return newarray;
    }
}
int main(){
    int n;
    cout << "enter the size of array: ";cin>>n;
    int*ptr = inputarray(n);
    OutputArray(ptr , n);
    int*compression = CompressArray(ptr , n);

    OutputArray(compression , n);
}