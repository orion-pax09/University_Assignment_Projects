#include <iostream>
using namespace std;
char** allocate(int&rows , int&column){
    char** array = new char*[rows];
    for (int i = 0 ; i < rows ; i++){
        array[i] = new char [column];
    }
    return array;
}
void InputMatrix(char** matrix, const int rows, const int cols){
    cout << "Enter the the element of rows and column: "<<endl;
    for (int i = 0 ; i < rows ; i++){
        for (int j = 0 ; j < cols ; j++){
            cin>>matrix[i][j];
        }
    }
}
void DisplayMatrix(char** matrix, const int& rows, const int& cols){
    cout << "Displaying matrix........"<<endl;
    for (int i = 0 ; i < rows ; i++){
        for (int j = 0 ; j < cols ; j++){
            cout << matrix[i][j] <<" ";
        }
        cout << endl;
    }
}
void categoriesmatrix(char** matrix, const int& rows, const int& cols){
    int count_alpha = 0;
    int count_digit = 0;
    int count_specialchar = 0;
    // counting the alphabets number and special character first
    for (int i = 0 ; i < rows ; i++){
        for (int j = 0 ; j < cols ; j++){
            if (isdigit(matrix[i][j])){
                count_digit++;
            }
            else if (isalpha(matrix[i][j])){
                count_alpha++;
            }
            else{
                count_specialchar++;
            }
        }
    }
    cout << "Special character numbers: "<<count_specialchar<<endl;
    cout << "Number of digits: "<<count_digit<<endl;
    cout << "Alphabet numbers:"<<count_alpha<<endl;
    int alpha_index = 0;
    int digit_index = 0;
    int specialchar_index = 0;
    char*array_alpha = new char [count_alpha];
    char* array_digit = new char [count_digit];
    char* array_specialchar = new char [count_specialchar];
    for (int i = 0 ; i < rows ; i++){
        for (int j = 0 ; j < cols ; j++){
            if (isalpha(matrix[i][j])){
                array_alpha[alpha_index++] = matrix[i][j];
            }
            else if (isdigit(matrix[i][j])){
                array_digit[digit_index++] = matrix[i][j];
            }
            else{
                array_specialchar[specialchar_index++] = matrix[i][j];
            }
        }
    }
    cout << "Alphabets: ";
    for (int i = 0 ; i < count_alpha ; i++){
        cout <<array_alpha[i] <<" | ";
    }
    cout << endl;
    cout<< "Digits: ";
    for (int i = 0 ; i < count_digit ; i++){
        cout << array_digit[i]<<" | ";
    }
    cout << endl;
    cout << "Special character: ";
    for (int i = 0 ; i < count_specialchar ; i++){
        cout <<array_specialchar[i] <<" | ";
    }
    cout <<endl;
    delete [] array_alpha;
    array_alpha = nullptr;
    delete [] array_digit;
    array_digit = nullptr;
    delete [] array_specialchar;
    array_specialchar = nullptr;
}
void deallocate(char** pt ,int&rows ){
    for(int i = 0 ; i < rows ; i++){
        delete[] pt [i];
    }
    delete [] pt;
    pt = nullptr;
}
int main(){
    int rows ;
    cout << "Enter the rows: ";
    cin >> rows;
    int cols;
    cout << "Enter the columns: ";
    cin >> cols;
    char** ptr = allocate(rows , cols);
    InputMatrix(ptr , rows , cols);
    DisplayMatrix(ptr , rows , cols);
    categoriesmatrix(ptr , rows , cols);
    deallocate(ptr , rows);


}