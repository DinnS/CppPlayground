#include <iostream>


using namespace std;

// Display numbers of array which greater than parameter n
void displayGreaterThan(int *array, int arraySize, int n);

// Prompt the user to input values to fill integer array
void fillArray(int *array, int arraySize);

void displayGreaterThan(int *array, int arraySize, int n) {

    for(int i = 0; i < arraySize; i++) {
        if(array[i] > n) {
            cout << array[i] << "  ";
        }
    }
}

void fillArray(int *array, int arraySize) {

    for(int i = 0; i < arraySize; i++) {
        cout << "Enter " << i + 1 << " number: ";
        cin >> array[i];
    }
}

int main() {

    const int ARRAY_SIZE = 10;
    int numberArray[ARRAY_SIZE] = {};

    int comparisonValue = 0;
    
    
    fillArray(numberArray, ARRAY_SIZE);

    cout << "Enter comparison value: ";
    cin >> comparisonValue;

    displayGreaterThan(numberArray, ARRAY_SIZE, comparisonValue);

    return 1;
}