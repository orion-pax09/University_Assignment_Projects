#include <iostream>
using namespace std;

// Function to count factors
int countFactors(int num) {
    int count = 0;
    for(int i = 1; i <= num; i++) {
        if(num % i == 0)
            count++;
    }
    return count;
}

// Function to fill factors
void fillFactors(int *arr, int num) {
    int index = 1; // 0 reserved for number itself
    arr[0] = num;
    for(int i = 1; i <= num; i++) {
        if(num % i == 0) {
            arr[index++] = i;
        }
    }
}

int main() {
    int m;
    cout << "Enter number of rows: ";
    cin >> m;

    int **A = new int*[m];   // 2D jagged array
    int *sizes = new int[m]; // store size of each row

    for(int i = 0; i < m; i++) {
        int num;

        // Input validation
        while(true) {
            cout << "Enter Number between 6 and 100: ";
            cin >> num;

            if(num > 6 && num < 100)
                break;
            else
                cout << "Wrong input. Please re-enter the number\n";
        }

        int factorCount = countFactors(num);

        sizes[i] = factorCount + 1; // +1 for storing number

        A[i] = new int[sizes[i]];

        fillFactors(A[i], num);
    }

    // Display
    cout << "\nFollowing are the factors of numbers entered:\n";

    for(int i = 0; i < m; i++) {
        cout << "Factors of " << A[i][0] << " are ";

        for(int j = 1; j < sizes[i]; j++) {
            cout << A[i][j];

            if(j < sizes[i] - 1)
                cout << ",";
        }
        cout << endl;
    }

    // Deallocation
    for(int i = 0; i < m; i++) {
        delete[] A[i];
    }
    delete[] A;
    delete[] sizes;

    return 0;
}