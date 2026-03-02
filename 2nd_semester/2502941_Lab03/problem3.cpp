#include <iostream>
#include <iomanip>
using namespace std;
void print(float*p[] , int n){
    for (int i = 0 ; i < n ; i++){
        cout << "Address of " << i+1 << " : " <<p[i]<< setw(4)<< " and value is : "<< *p[i]<<endl;
    }
}
void sort(float* p[] , int n){
    float insert; // temporary variable to hold elements
    cout << "----------After the sorting by (insertion method)----------"<<endl;
    for (int next = 1 ; next < n ; next++){
        insert = *p[next];
        int moveitem  = next;
        while ((moveitem > 0) && (*p[moveitem - 1] > insert)){
            *p[moveitem] = *p[moveitem -1];
            moveitem--;
        }
        *p[moveitem] = insert;
    }
}
void Main(){
    float a[] = {44.4 , 77.7 , 22.2 , 88.8 , 66.6 , 33.3 , 99.9 , 55.5};
    const float arraysize = 8;
    float* p[8];
    for (int i = 0 ; i < 8 ; i++){
        p[i] = new float (a[i]);
    }
    print(p , 8);
    sort(p , 8);
    print(p , 8);
    for (int i = 0 ;  i < 8 ; i++){
        delete p[i];
    }
}
int main(){
    cout << "---------original array----------"<<endl;
    Main();
}