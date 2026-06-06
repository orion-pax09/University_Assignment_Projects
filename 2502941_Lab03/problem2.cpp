#include <iostream>
using namespace std;
void myTokenizer(char *data, char**list_tokens, char delimiter){
    int start = 0 ; //start index of current token
    int tokenindex = 0; //row index for all token
    for (int i = 0 ; ; i++){
        if (data[i] ==','||data[i] =='\0'){
            int length = i - start ; // length of current token
            list_tokens[tokenindex] = new char [length+1]; //Allocation of memory exactly
            for (int j = 0 ; j < length ; j++){
                list_tokens[tokenindex][j]= data[start+j]; // placing current index of data into new array list_token
            }
            list_tokens[tokenindex][length]='\0'; // null termination 
            tokenindex++;
            start = i+1;
        }
        if (data[i]=='\0'){
            break;
        }
    }
}

int main(){
    char Data[] = "My,name,is,Dr,Imran,Khan";
    char Delimeter = ',';
    int count = 1 ; // setting count to 1 because there are 5 commas but to store last word we set count = 0 + 1
    for (int i = 0 ;  Data[i] !='\0' ; i++){
        if (Data[i] == ','){
            count++;
        }
    }
    char**List_TOken = new char* [count];
    myTokenizer(Data , List_TOken , Delimeter);
    for (int i = 0 ; i < count  ; i++ ){
         cout << List_TOken[i]<<endl;
    }
    for (int i = 0 ; i < count ; i++){
        delete[]List_TOken[i];
    }
    delete[]List_TOken;
}