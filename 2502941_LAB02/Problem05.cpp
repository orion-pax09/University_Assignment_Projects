#include <iostream>
using namespace std;
int main(){
    int rows, cols;
    cout << "Enter the rows: ";
    cin >> rows;
    cout << "Enter the column number: ";
    cin >> cols;
    while (rows <= 0 || cols <= 0){
        cout << "Enter the valid rows: "<<endl;
        cin >> rows;
        cout << "Enter the cols: "<<endl;
        cin >> cols;
    }
    int** matrix = new int * [rows];
    for (int i = 0 ; i < rows ; i++){
        matrix[i] = new int [cols];
    }
    cout << "Enter the rows and column: ";
    for (int i = 0 ; i < rows ; i++){
        for (int j = 0 ; j < cols ; j++){
            cin >> matrix[i][j];
        }
    }
    for (int i = 0 ; i < rows ; i++){
        for (int j = 0 ; j < cols ; j++){
            cout << matrix[i][j]<<" ";
        }
        cout << endl;
    }
    for (int i = 0 ; i < rows ; i++){
        for (int j = 0 ; j < cols ; j++){
            matrix[i][j]+=matrix[i][j];
        }
    }
    cout << "------------Sum-----------"<<endl;

    for (int i = 0 ; i < rows ; i++){
        for (int j = 0 ; j < cols ; j++){
            cout << matrix[i][j]<<" ";
        }
        cout << endl;
    }
    for (int i = 0 ; i < rows ; i++){
        delete [] matrix [i];
    }
    delete [] matrix;
    matrix = nullptr;
} 