#include <iostream>

using namespace std;

/******************** prototypes ********************/

// Swap numbers and multiple by 10, returning the sum
int swapMultipleGetSum(int *x, int *y);

/******************** main program ********************/
int main()
{
    int firstNumber = 5;
    int secondNumber = 8;
    int sum = 0;
    
    cout << "Before\n";
    cout << "First number: " << firstNumber << endl;
    cout << "Second number: " << secondNumber << endl;

    sum = swapMultipleGetSum(&firstNumber, &secondNumber);
    
    cout << "\nAfter\n";
    cout << "First number: " << firstNumber << endl;
    cout << "Second number: " << secondNumber << endl;

    cout << "Sum of two numbers: " << sum << endl;

    return 0;
}

/******************** functions implementation ********************/

int swapMultipleGetSum(int *x, int *y) {
    int temp = *x;
    *x = *y * 10;
    *y = temp * 10;
    return (*x) + (*y);
}
