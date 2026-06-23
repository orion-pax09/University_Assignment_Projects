#include <iostream>
#include <cstring>
using namespace std;
class Bank_Account_system{
    private:
    char*Accountholdername;
    int account_Number;
    double balance;
    static int Totalaccount;
    public:
    Bank_Account_system(int a= 0 , double b= 0): account_Number(a) , balance(b){
        Accountholdername = new char [50];
        strcpy(Accountholdername , "unknown");
        Totalaccount++;
    }  
    void show(){
        cout << "Account holder name: "<<Accountholdername<<endl;
        cout << "Account Number: "<<account_Number<<endl;
        cout << "Account balance: "<<balance<<endl;
    }
    static int totalaccount(){
        return Totalaccount; 
    }
    friend void updateNameAndBalance(Bank_Account_system &b, const char* newName, double newBalance){
        strcpy(b.Accountholdername , newName);
        b.balance = newBalance;
    }
    ~Bank_Account_system(){
        delete [] Accountholdername;
    }
};
int Bank_Account_system::Totalaccount = 0;
int main(){
    Bank_Account_system b(773575,437.0);
    b.show();
    b.totalaccount();
    cout<<"---------------------------------"<<endl;
    updateNameAndBalance(b , "Muhammad hamza khan" , 6400);
    b.show();
    b.totalaccount();
}