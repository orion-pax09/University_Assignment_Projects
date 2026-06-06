#include <iostream>
using namespace std;
int input(int**A , int m , int n){
    cout << "==========Enter the 2D array=========="<<endl;
    for (int i = 0 ; i < m ; i++){
        for (int j = 0 ; j < n ; j++){
            cin >> A[i][j];
        }
    }
    return 0;
}
int output (int**A , int m , int n){
    cout << "==========Output the 2D array=========="<<endl;
    for (int i = 0 ; i < m ; i++){
        for (int j = 0 ; j < n ; j++){
            cout << A[i][j]<<" ";
        }
        cout << endl;
    }
    return 0;
}
int sum (int**A , int m , int n){
    cout << "==========Sum of the 2D array=========="<<endl;
    int totalsum = 0;
    for (int i = 0 ; i < m ; i++){
        for (int j = 0 ; j < n ; j++){
            totalsum+=A[i][j];
        }
        cout << "Total sum of all elements is "<<totalsum<<endl;
    }
    return totalsum;
}
int rows_sum(int**A , int m , int n){
    for (int i= 0 ; i < m ; i++){
    int rows_Sum = 0;
        for (int j = 0 ; j < n ; j++){
            rows_Sum+=A[i][j];
        }
        cout << "Sum of rows: "<< rows_Sum<<endl;
    }
}
int cols_sum(int**A , int m , int n){
    for (int i = 0 ; i < n ; i ++){
    int Cols_sum = 0;
        for (int j = 0 ; j < m ; j++){
            Cols_sum+=A[j][i];
        }
        cout << "Sum of cols: "<< Cols_sum<<endl;
    }
}
int transpose(int** A, int m, int n){
    int** B = new int*[n];
    for (int i = 0; i < n; i++){
        B[i] = new int[m]; 
    }
    for (int i = 0; i < m; i++){
        for (int j = 0; j < n; j++){
            B[j][i] = A[i][j];  
        }
    }

    cout << "==========Transpose=========" << endl;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            cout << B[i][j] << " ";
        }
        cout << endl;
    }

    for (int i = 0; i < n; i++){
        delete[] B[i];
    }
    delete[] B;

    return 0;
}
int main(){
    int rowssize;
    cout << "Entet the rows size: ";
    cin >> rowssize;
    int colssize;
    cout << "Enter the cols sizE: ";
    cin >> colssize;
    int**A = new int* [rowssize];
    int button;
        for (int i = 0 ; i < rowssize ; i++){
        A[i] = new int [colssize];
    }
    do
    {
        cout << "press 1 to enter input "<<endl;
        cout<<  "Enter the 2 to display"<<endl;
        cout << "Enter 3 to display all total of elements "<<endl;
        cout << "Enter 4 to display all rows sum "<<endl;
        cout<<  "Enter 5 to display all sum of cols "<<endl;
        cout << "Enter 6 to displat transpose"<<endl;
        cout << "Enter 7 to exit"<<endl;
        cout << "Enter the choice"<<endl;
        cin >> button;
        switch (button)
        {
            case 1:
            input(A , rowssize , colssize);
            break;
            case 2:
            output(A , rowssize , colssize);
            break;
            case 3:
            sum(A , rowssize , colssize);
            break;
            case 4:
            rows_sum(A , rowssize , colssize);
            break;
            case 5:
            cols_sum(A , rowssize , colssize);
            break;
            case 6:
            transpose(A , rowssize , colssize);
            break;
            case 7:
            cout << "You exist"<<endl;
            break;
        default:
        cout <<"Invalid choice, try again"<<endl;
            break;
        }
    } while (button!=7);
     for(int i = 0; i < rowssize; i++) {
        delete[] A[i];
    }
    delete[] A;

    return 0;
}