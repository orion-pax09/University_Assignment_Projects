#include <iostream>
#include "Problem01.cpp"
int main(){
    int array[] ={3,4,5,6,7,8,9};
    BIGGERINT obj1(array , 6);
    BIGGERINT obj2 = obj1;
    obj1.display();
    obj2.display();
}