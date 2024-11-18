#include <iostream>

using namespace std;

// Months short name
const string MONTHS_NAME[12] = {
    "January", 
    "February", 
    "March", 
    "April", 
    "May", 
    "June", 
    "July", 
    "August", 
    "September", 
    "October", 
    "November", 
    "December"
};

// Functions prototypes for rainfall array operations
void fillRainfallData(double *array, int arraySize);
double getTotalRainfall(double *array, int arraySize);
double getAverageRainfall(double *array, int arraySize);
double getHighestRainfall(double *array, int arraySize);
double getLowestRainfall(double* array, int arraySize);
int getRainfallIndexByValue(double searchValue, double *array, int arraySize);

// Prompt the user to fill the array with input values
void fillRainfallData(double *array, int arraySize) {

    int i = 0;

    while(i < arraySize) {
        cout << "Enter " << i + 1 << "# month :";
        cin >> array[i];

        // If value negative, re-enter data
        if(array[i] < 0){
            cout << "Please re-enter data. Data should not be negative." << endl;
        } else {
            i++;
        }
    }
}

// Calculate and return total Rainfall
double getTotalRainfall(double *array, int arraySize) {

    double total = 0.0;

    for(int i = 0; i < arraySize; i++) {
        total += array[i];
    }

    return total;
}

// Calculate and return average Rainfall
double getAverageRainfall(double *array, int arraySize) {

    double average = 0.0;
    double total = 0.0;

    for(int i = 0; i < arraySize; i++) {
        total += array[i];
    }
    // getTotalRainfall(array, arraySize) instead of loop, but will be more dependent

    average = total / arraySize;

    return average;
}

// Calculate and return highest Rainfall
double getHighestRainfall(double *array, int arraySize) {

    double highest = array[0];

    for(int i = 0; i < arraySize; i++) {
        if(array[i] > highest) {
            highest = array[i];
        }
    }

    return highest;
}

// Calculate and return lowest Rainfall
double getLowestRainfall(double* array, int arraySize) {

    double lowest = array[0];

    for(int i = 0; i < arraySize; i++) {
        if(array[i] < lowest) {
            lowest = array[i];
        }
    }

    return lowest;
}

// Get first Rainfall index by search value and return that index
int getRainfallIndexByValue(double searchValue, double *array, int arraySize) {

    int index = 0;

    for(int i = 0; i < arraySize; i++) {
        if(array[i] == searchValue) {
            index = i;
            
            break;
        }
    }

    return index;
}

int main() {

    const int MONTH_AMOUNT = 12;
    double monthlyRainfall[MONTH_AMOUNT] = {};

    double totalRainfall = 0.0;
    double averageRainfall = 0.0;
    double highestRainfall = 0.0;
    double lowestRainfall = 0.0;
    int highestRainfallIndex = 0;
    int lowestRainfallIndex = 0;

    // Prompt user to fill rainfall array
    fillRainfallData(monthlyRainfall, MONTH_AMOUNT);

    // Calculate and Display rainfall total per year
    totalRainfall = getTotalRainfall(monthlyRainfall, MONTH_AMOUNT);
    cout << "Total rainfall: " << totalRainfall << endl;

    // Calculate and Display rainfall average monthly 
    averageRainfall = getAverageRainfall(monthlyRainfall, MONTH_AMOUNT);
    cout << "Average rainfall per month: " << averageRainfall << endl;

    // Calculate highest and lowest rainfall and their index
    highestRainfall = getHighestRainfall(monthlyRainfall, MONTH_AMOUNT);
    lowestRainfall = getLowestRainfall(monthlyRainfall, MONTH_AMOUNT);
    highestRainfallIndex = getRainfallIndexByValue(highestRainfall, monthlyRainfall, MONTH_AMOUNT);
    lowestRainfallIndex = getRainfallIndexByValue(lowestRainfall, monthlyRainfall, MONTH_AMOUNT);

    // Display highest and lowest rainfall
    cout << "Highest rainfall: " << highestRainfall << " in " << MONTHS_NAME[highestRainfallIndex] << endl;
    cout << "Lowest rainfall: " << lowestRainfall << " in " << MONTHS_NAME[lowestRainfallIndex] << endl;

    return 1;
}