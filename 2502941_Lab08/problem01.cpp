#include <iostream>
using namespace std;
class Month{
    private:
    string month[12]={"January" , "February" , "March" , "April" , "May",
    "june","July","August","September","October","November","December"};
    int monthCount;
    string name;
    public:
    Month(){
        monthCount = 1;
        name = month[0];
    }
    Month(string n){
        for (int i = 0 ; i < 12 ; i++){
            if(month[i]==n){
                monthCount = i + 1;
                name = month[i];
                break;
            }
        }
    }
    Month&operator++(){
        ++monthCount;
        if (monthCount > 12){
            monthCount = 1;
        }
        name = month[monthCount-1];
        return*this;
    }
    Month operator++(int dummy){
        Month temp = *this;
        monthCount++;
        if (monthCount>12){
            monthCount=1;
        }
        name = month[monthCount-1];
        return temp;
    }
    Month&operator--(){
        --monthCount;
        if (monthCount<1){
            monthCount=12;
        }
        name = month[monthCount-1];
        return*this;
    }
    Month operator--(int dummy){
        Month temp = *this; 
        monthCount--;
        if (monthCount<1){
            monthCount = 12;
        }
        name = month[monthCount-1];
        return temp;
    }
    void display(){
        cout << "Month: "<<name<<endl;
        cout << "Month number: "<<monthCount<<endl;
    }
};
int main(){
  Month m1;  
  m1.display();
  Month m2("March");
  m2.display();
  m2++;
  m2.display();
  m2--;
  m2.display();
  --m2;
  m2.display();
  Month m4("January");
  m4.display();
  m4--;
  m4.display();
  --m4;
  m4.display();
}