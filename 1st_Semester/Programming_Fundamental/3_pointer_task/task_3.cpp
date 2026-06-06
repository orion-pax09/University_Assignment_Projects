#include <iostream>
#include <cstdlib>
using namespace std;

int main()
{
    int count;
    cout << "Enter the number: ";
    cin >> count;

    // Allocate memory dynamically
    int *numbers = (int *)malloc(count * sizeof(int));

    // Check if memory allocation failed
    if (numbers == NULL)
    {
        cout << "Memory allocation failed!" << endl;
        return 1;
    }

    // Input values
    int total = 0;
    for (int i = 0; i < count; i++)
    {
        cout << "Enter number " << i + 1 << ": ";
        cin >> numbers[i];
        total += numbers[i];
    }

    // Calculate and print average
    double avg = (double)total / count;
    cout << "Average = " << avg << endl;

    // Free allocated memory
    free(numbers);

    return 0;
}
