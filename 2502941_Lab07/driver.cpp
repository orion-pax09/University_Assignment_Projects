#include <iostream>
#include "account.h"

using namespace std;

int main(){
    Bank_Account_system b(773575,437.0);
    b.show();
    b.totalaccount();
    updateNameAndBalance(b , "Muhammad hamza khan" , 6400);
    b.show();
}