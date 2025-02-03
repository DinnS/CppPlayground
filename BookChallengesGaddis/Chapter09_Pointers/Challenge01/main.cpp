#include <iostream>

using namespace std;

/******************** prototypes ********************/

// Allocates a new array and returns a pointer to it.
int *allocateArray(int size);


/******************** main program ********************/

int main() {

    int *arrayPtr = nullptr;
    int arraySize = 0;

    // Prompt the user input
    cout << "Enter the size of array: ";
    cin >> arraySize;    

    // Allocating new array using function
    arrayPtr = allocateArray(arraySize);

    // Check if array works correctly
    cout << "Array content: ";
    for(int i = 0; i < arraySize; i++) {
        cout << *(arrayPtr + i) << " ";
    }

    // Free memory
    delete []arrayPtr;
    arrayPtr = nullptr;
    
    cout << endl;

    return 0;
}


/******************** functions implementation ********************/

int *allocateArray(int size) {

    int *newArray = nullptr;

    if(size <= 0) {
        cout << "Array size must be more than 0!" << endl;
    } else {
        newArray = new int[size];

        // Initialize the array to 0
        for(int i = 0; i < size; i++) {
            newArray[i] = 0;
        }
    }

    return newArray;
}