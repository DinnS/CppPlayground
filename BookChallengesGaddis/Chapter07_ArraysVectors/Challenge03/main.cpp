#include <iostream>

using namespace std;

// Prompt the user to input the number of jars sold for each salsa type
void fillJarsData(string *salsaTypesArray, int *jarsSoldArray, int arraySize);

// Display the sales summary, providing the salsa type name
void displayJarsSalsaData(string *salsaTypesArray, int *jarsSoldArray, int arraySize);

// Calculate and return the total number of jars sold
int getTotalJars(int *jarsSoldArray, int arraySize);

// Find and return the index of the salsa type with the highest sales
int getIndexMax(int *jarsSoldArray, int arraySize);

// Find and return the index of the salsa type with the lowest sales
int getIndexMin(int *jarsSoldArray, int arraySize);



void fillJarsData(string *salsaTypesArray, int *jarsSoldArray, int arraySize) {

    int i = 0;

    do {
        cout << "Enter the number of jars sold for " << salsaTypesArray[i] << " salsa: ";
        cin >> jarsSoldArray[i]; 

        // Validate input: Only accept non-negative values
        if(jarsSoldArray[i] >= 0) {
            i++;
        }

    } while(i < arraySize);
}

void displayJarsSalsaData(string *salsaTypesArray, int *jarsSoldArray, int arraySize) {
    
    cout << "Sales Summary: " << endl;

    for(int i = 0; i < arraySize; i++) {
        cout << salsaTypesArray[i] << ": " << jarsSoldArray[i] << endl;
    }
}

int getTotalJars(int *jarsSoldArray, int arraySize) {
    int total = 0;

    for(int i = 0; i < arraySize; i++) {
        total += jarsSoldArray[i];
    }
    
    return total;
}

int getIndexMin(int *jarsSoldArray, int arraySize) {

    int indexMin = 0;

    for(int i = 0; i < arraySize; i++) {

        if(jarsSoldArray[i] < jarsSoldArray[indexMin]) {
            indexMin = i;
        }
    }

    return indexMin;
}

int getIndexMax(int *jarsSoldArray, int arraySize) {

    int indexMax = 0;

    for(int i = 0; i < arraySize; i++) {
        if(jarsSoldArray[i] > jarsSoldArray[indexMax]) {
            indexMax = i;
        }
    }

    return indexMax;
}


int main() {

    // Number of salsa types to track
    const int SALSA_TYPES_AMOUNT = 4;
    string salsaTypes[SALSA_TYPES_AMOUNT] = {"mild", "medium", "hot", "zesty"};

    // Array to store the number of jars sold for each type
    int jarsSoldPerType[SALSA_TYPES_AMOUNT] = {};

    // Statistics variables
    int total = 0;
    int indexMax = 0;
    int indexMin = 0;

    // Gather sales data from the user
    fillJarsData(salsaTypes, jarsSoldPerType, SALSA_TYPES_AMOUNT);

    // Display detailed sales data
    displayJarsSalsaData(salsaTypes, jarsSoldPerType, SALSA_TYPES_AMOUNT);

    // Calculate and display total jars sold
    total = getTotalJars(jarsSoldPerType, SALSA_TYPES_AMOUNT);
    cout << "Total Jars Sold: " << total << endl;

    // Identify and display highest and lowest sales
    indexMax = getIndexMax(jarsSoldPerType, SALSA_TYPES_AMOUNT);
    indexMin = getIndexMin(jarsSoldPerType, SALSA_TYPES_AMOUNT);
    cout << "Highest Selling: " << jarsSoldPerType[indexMax] << " (" << salsaTypes[indexMax] << " jars)" << endl;
    cout << "Lowest Selling: " << jarsSoldPerType[indexMin] << " (" << salsaTypes[indexMin] << " jars)" << endl;


    return 1;
}