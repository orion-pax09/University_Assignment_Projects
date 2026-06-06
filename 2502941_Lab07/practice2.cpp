#include <iostream>
using namespace std;
class customer{
    private:
    string name;
    public:
    customer(){
        name = "";
    }
    customer(const string & N){
        name = N;
    }
    void setname(const string&N){
        name = N;
    }
    string getname()const{
        return name;
    }
};
class Account:protected customer{
    protected:
    long long int acc_num ; 
    long double balance;
    string banKname;
    public:
    Account(const string &name , const string&bankname , long long int accountnum , long double B):customer(name){
        this-> banKname = bankname;
        acc_num = accountnum;
        balance = B;
    }
    void display(){
        cout << "Owner's name: "<<
        customer::getname();
        cout << endl;
        cout << "Bank account: "<<banKname<<endl;
        cout << "Balance: "<<balance<<endl;
        cout << "Account number: "<<acc_num<<endl;
    }
};
class savingsaccount:public Account{
    private:
    double interestrate;
    public:
    savingsaccount(const string&name , const string&bankname , long long int accountnum , long double B , double ir):Account(name , bankname , accountnum , B){
        interestrate = ir;
    }
    void setinterestrate(double ir){
        interestrate = ir;
    }
    double getinterestrate(){
        return interestrate;
    }
    void display(){
        Account::display();
        cout<< "Interest rate: "<<getinterestrate()<<endl;
    }
};
class currentAccount:public Account{
  private:
  int overdraftlimit;
  public:currentAccount(const string&name , const string&bankname , long long int accountnum , long double B , int limit):
  Account(name , bankname , accountnum , B){
    overdraftlimit = limit;
}
 void setlimit(int l){
    overdraftlimit = l;
 }
 void withdraw(int amount){  
    if ( amount > overdraftlimit || amount < 50){
        cout << "Invalid. Enter the amount 50 - "<<overdraftlimit<<" to withdraw"<<endl;
    }
    else if (balance + overdraftlimit >=amount){
        balance -=overdraftlimit;
    }
    else{
        cout << "Insufficient balance"<<endl;
    }
 }
 void display(){
    Account::display();
    cout << "Current balance: "<<balance<<endl;
 }
};
class premiumAccount:public savingsaccount{
    private:
    string conciergecode = "ABC";
    protected:
    int rewardpts;
    public:
    premiumAccount(const string&n , const string&bankname , long long bankaccnum , long double B):
    savingsaccount(n , bankname , bankaccnum , B , 0.0){
    }
    void chewckrewardpts(){
        rewardpts +=10;
    }
    bool checkcode(const string & input){
        return conciergecode == input;
    }
    void display(){
        savingsaccount::display();
        cout << "Rewards points: "<<rewardpts<<endl;
    }
};
int main(){
    currentAccount b ("Muhammad Hamza Khan" , "Meezan Bank" , 3310251666049 , 700000.0 , 25000);
    b.display();

}