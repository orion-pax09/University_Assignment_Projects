#ifndef Account_H
#define Account_H
#include <iostream>
using namespace std;
class Bank_Account_system{
    private:
    char*Accountholdername;
    int account_Number;
    double balance;
    static int Totalaccount;
    public:
    Bank_Account_system(int a= 0 , double b= 0);
    void show();
    static int totalaccount();
    friend void updateNameAndBalance(Bank_Account_system &b, const char* newName, double newBalance);
    ~Bank_Account_system();
};
#endif