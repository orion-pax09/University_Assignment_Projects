#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

long long int binary_to_decimal(string num) {
    long long sum = 0;
    int power = 0;
    for (int i = num.size() - 1; i >= 0; i--) {
        long long int digit = num[i] - '0';
        sum += digit * pow(2, power);
        power++;
    }
    return sum;
}


vector<int> decimal_to_binary(int num) {
    vector<int> ans;
    while(num > 0){
    int reminder = num%2;
    ans.push_back(reminder);
    num /=2;
    reverse(ans.begin() , ans.end());
    }
    return ans;
}


vector<char>decimal_to_hexa(long long int nums){
    vector<char>ans;
    string hex = "0123456789ABCDEF";
    while(nums>0){
        long long int reminder = nums%16;
        ans.push_back(hex[reminder]);
        nums /=16;
    }
    reverse(ans.begin() , ans.end());
    return ans;
}

long long hexa_to_decimal(string nums){
    long long int sum = 0;
    string hex = "0123456789ABCDEF";
    vector<int>ans;
    for (int i = nums.length()-1 ; i>=0 ; i--){
        if (nums[i] =='F'){
            ans.push_back(15);
        }
        else if (nums[i] =='E'){
            ans.push_back(14);
        }

        else if (nums[i] =='D'){
            ans.push_back(13);
        }

        else if (nums[i] =='C'){
            ans.push_back(12);
        }

        else if (nums[i] =='B'){
            ans.push_back(11);
        }
        else if (nums[i] =='A'){
            ans.push_back(10);
        }
        else{
            ans.push_back(nums[i]-'0');
        }
    }
    for (int i = ans.size()-1 ; i>=0 ; i--){
        int digits = ans[i];
        sum += digits * pow(16 , i); 
    }
    return sum;
}

vector<int>hexaDecimal_to_Binary(string nums){
    long long int decimal_form = hexa_to_decimal(nums);
    string DF = to_string(decimal_form);
    vector<int>result;
    while (decimal_form > 0){
        int reminder = decimal_form % 2;
        result.push_back(reminder);
        decimal_form /=2;
    }
    reverse(result.begin() , result.end());
    return result;
}

vector<char>Binary_to_Hexadecimal(string nums){
    long long int decimal_form = binary_to_decimal(nums);
    vector<char>ans = decimal_to_hexa(decimal_form);
    return ans;
}


int main() {
    /*string x;
    cout << "Enter the number in binary: " << endl;
    cin >> x;
    int base;
    cout << "Enter the number in base: " << endl;
    cin >> base;
    cout << binary_to_decimal(x,base)<<endl;

    cout << hexa_to_decimal("2F");
    */

   
   int option;
   cout << "Enter 1 to convert binary to decimal"<<endl;
   cout << "Enter 2 to convert decimal to binary"<<endl;
   cout << "Enter 3 to convert decimal to hexa"<<endl;
   cout << "Enter 4 to convert hexa to decimal"<<endl;
   cout << "Enter 5 to hexa to binary"<<endl;
   cout << "Enter 6 to convert binary to hexa"<<endl;
   cout << "You selected: ";
   cin >> option;
   switch (option)
   {
   case 1:
    {
    string x;
    cout << "Enter the number in binary"<<endl;
    cin >> x;
    cout << binary_to_decimal(x);
    break;
    }
    case 2:
    {
    int number;
    cout << "Enter the decimal form"<<endl;
    cin >> number;
    vector<int>temp = decimal_to_binary(number);
    for (auto c : temp){
        cout << c << " ";
    }
    break;
    }
    case 3:
   {
    long long hex_num ;
    cout << "Enter the number you want to conver to hexa: "<<endl;
    cin >> hex_num;
    vector<char>temp = decimal_to_hexa(hex_num);
    for (auto c : temp){
        cout << c;
    }
    break;
   }
    case 4:
   {
    string x ;
    cout << "Enter the hexadecimal form: "<<endl;
    cin >> x;
    long long temp = hexa_to_decimal(x);
    cout << temp;
    break;
   }
   case 5:
   {
    string x;
    cout << "Enter the hexadecimal form: " << endl;
    cin >> x;
    vector<int> temp = hexaDecimal_to_Binary(x);
    for (auto c : temp) {
        cout << c;
    }
    break;
   }
   case 6:
   {
    string x;
    cout << "Enter the number in binary: " << endl;
    cin >> x;
    vector<char> temp = Binary_to_Hexadecimal(x);
    for (auto c : temp) {
        cout << c;
    }
    break;
   }
   default:
   cout << "Invalid choice"<<endl;
    }
}
