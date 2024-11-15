#include <iostream>

using namespace std;

// Functions prototypes for array operations
void fillArray(int *array, int arraySize);
void outputArray(int *array, int arraySize);
int getMaxValue(int *array, int arraySize);
int getMinValue(int *array, int arraySize);

// Prompt the user to fill the array with input values
void fillArray(int *array, int arraySize) {
    for(int i = 0; i < arraySize; i++) {
        cout << "Enter #" << i + 1 << " number : ";
        cin >> array[i];
    }
}

// Output each element in the array
void outputArray(int *array, int arraySize) {
    for(int i =0; i < arraySize; i++) {
        cout << array[i] << endl;
    }
}

// Find the maximum value in the array
int getMaxValue(int *array, int arraySize) {
    int max = array[0];

    for(int i = 0; i < arraySize; i++) {
        if(max < array[i]) {
            max = array[i];
        }
    }

    return max;
}

// Find the minimum value in the array
int getMinValue(int *array, int arraySize) {
    int min = array[0];

    for(int i = 0; i < arraySize; i++) {
        if(min > array[i]) {
            min = array[i];
        }
    }

    return min;
}


int main() {

    const int ARRAY_SIZE = 10;
    int array[ARRAY_SIZE] = {};
    
    int min = 0;
    int max = 0;
    
    // Fill array with inputs
    fillArray(array, ARRAY_SIZE);

    // Get min and max values
    min = getMinValue(array, ARRAY_SIZE);
    max = getMaxValue(array, ARRAY_SIZE);

    // Display the results
    cout << "Min Value: " << min << endl;
    cout << "Max Value: " << max << endl;

    return 1;
}