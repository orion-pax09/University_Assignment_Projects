#include <iostream>
using namespace std;

int main()
{
    int rows;
    cout << "Enter number of rows: ";
    cin >> rows;

    int** factors = new int*[rows];
    int* sizes = new int[rows];   
    for (int i = 0; i < rows; i++)
    {
        int num;

        do {
            cout << "Enter Number between 6 and 100: ";
            cin >> num;

            if (num <= 6 || num >= 100)
                cout << "Wrong input. Please re-enter the number\n";

        } while (num <= 6 || num >= 100);

        int count = 0;
        for (int j = 1; j <= num; j++)
            if (num % j == 0)
                count++;

        sizes[i] = count + 1;
        factors[i] = new int[sizes[i]];

        factors[i][0] = num;

        int index = 1;
        for (int j = 1; j <= num; j++)
        {
            if (num % j == 0)
                factors[i][index++] = j;
        }
    }

    cout << "\nFollowing are the factors of numbers entered:\n";

    for (int i = 0; i < rows; i++)
    {
        cout << "Factors of " << factors[i][0] << " are ";

        for (int j = 1; j < sizes[i]; j++)
        {
            cout << factors[i][j];
            if (j < sizes[i] - 1)
                cout << ",";
        }
        cout << endl;
    }

    for (int i = 0; i < rows; i++)
        delete[] factors[i];

    delete[] factors;
    delete[] sizes;
    factors= nullptr;
    sizes = nullptr;
    return 0;
}
