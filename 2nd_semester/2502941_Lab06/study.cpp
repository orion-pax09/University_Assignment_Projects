#include <iostream>
using namespace std;
class BankAccount{
    private:
    int accountnumber;
    double balance;
    static int totalAccounts;
    public:
    BankAccount(){
        accountnumber = 0;
        balance = 300.0;
    }
    static int gettotalaccount(){
        totalAccounts++;
        return totalAccounts;
    }
    int deposit(int& amount){
        balance +=amount;
        return balance;
    }
    int widhtraw(int & amount){
        balance -=amount;
        while (true){
            if (amount > balance){
                cout << "You dont have sufficcient balance"<<endl;
                true;
                break;
            }
            else{
                return balance;
                false;
                continue;
            }
        }
        }
    void getinput(){
            int button;
            int Amount;
        do
        {
            cout << "Enter 1 to deposit amount: "<<endl;
            cout << "Enter 2 to withdraw amount: "<<endl;
            cout << "Enter 3 to exit: "<<endl;
            cout << "Enter the button: ";
            cin>>button;
            if (button==1){
                cout << "Enter the amount: ";
                cin >> Amount;
                deposit(Amount);
            }
            else if (button==2){
                cout << "Enter the amount to withdraw: ";
                cin >> Amount;
                widhtraw(Amount);
            }
            else if (button==3){
                cout << "You exit"<<endl;
                break;
            }
            else{
                cout << "Enter the valid input"<<endl;
            }
        } 
        while (button !=3);
    }
    void display(){
        cout << "Ur current balance: "<<balance<<endl;
        cout << "your Account number: "<<accountnumber<<endl;
    }
};
int BankAccount::totalAccounts = 0;
int main(){
    BankAccount obj1;
    obj1.getinput();
    obj1.display();
    cout <<"Total bank account: " <<BankAccount::gettotalaccount()<<endl;

}