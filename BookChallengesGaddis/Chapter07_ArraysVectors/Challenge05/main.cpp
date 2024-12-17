#include <iostream>

using namespace std;

// Days of the week for better readability in input/output
const string DAYS_OF_WEEK[] = {"Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday"};

const int DAYS_IN_WEEK = 7;

// Prompts the user to input the amount of food consumed by monkeys
void inputMonkeyFoodData(int foodData[][DAYS_IN_WEEK], int monkeyCount);

// Displays the food data entered for each monkey
void displayFoodData(int foodData[][DAYS_IN_WEEK], int monkeyCount);

// Calculates the average food consumed each day by all monkeys
void calculateAverageFoodPerDay(int foodData[][DAYS_IN_WEEK], int monkeyCount, int dailyAverages[]);

// Finds the index of the day with the least amount of food consumed in the week
int getDayWithLeastFood(int weeklyFood[]);

// Finds the index of the day with the most amount of food consumed in the week
int getDayWithMostFood(int weeklyFood[]);

void inputMonkeyFoodData(int foodData[][DAYS_IN_WEEK], int monkeyCount) {

    for (int monkey = 0; monkey < monkeyCount; monkey++) {
        cout << "Enter food data for Monkey #" << monkey + 1 << ":" << endl;

        for (int day = 0; day < DAYS_IN_WEEK; day++) {
            cout << "  " << DAYS_OF_WEEK[day] << ": ";
            cin >> foodData[monkey][day];
            
            // Validate that food amount is non-negative
            if (foodData[monkey][day] < 0) {
                cout << "   Error: Food amount cannot be negative. Please re-enter." << endl;
                // Retry the same day
                day--; 
            }
        }
    }
}

void displayFoodData(int foodData[][DAYS_IN_WEEK], int monkeyCount) {

    cout << "Food data for all monkeys (in pounds):" << endl;

    for (int monkey = 0; monkey < monkeyCount; monkey++) {
        cout << "Monkey #" << monkey + 1 << ": ";

        for (int day = 0; day < DAYS_IN_WEEK; day++) {
            cout << foodData[monkey][day] << " ";
        }

        cout << endl;
    }
}

void calculateAverageFoodPerDay(int foodData[][DAYS_IN_WEEK], int monkeyCount, int dailyAverages[]) {
    // Sum food consumption for each day
    for (int monkey = 0; monkey < monkeyCount; monkey++) {

        for (int day = 0; day < DAYS_IN_WEEK; day++) {
            dailyAverages[day] += foodData[monkey][day];
        }
    }

    // Calculate the average for each day
    for (int day = 0; day < DAYS_IN_WEEK; day++) {
        dailyAverages[day] /= monkeyCount;
    }
}

int getDayWithLeastFood(int weeklyFood[]) {

    int minIndex = 0;
    int minFood = weeklyFood[0];

    for (int day = 1; day < DAYS_IN_WEEK; day++) {

        if (weeklyFood[day] < minFood) {
            minFood = weeklyFood[day];
            minIndex = day;
        }
    }
    return minIndex;
}

int getDayWithMostFood(int weeklyFood[]) {

    int maxIndex = 0;
    int maxFood = weeklyFood[0];

    for (int day = 1; day < DAYS_IN_WEEK; day++) {

        if (weeklyFood[day] > maxFood) {
            maxFood = weeklyFood[day];
            maxIndex = day;
        }
    }
    return maxIndex;
}

int main() {
    const int MONKEY_COUNT = 3; // Total number of monkeys
    int foodData[MONKEY_COUNT][DAYS_IN_WEEK] = {}; // 2D array for food data
    int dailyAverages[DAYS_IN_WEEK] = {}; // Stores average food consumption per day

    // Input food data
    cout << "Please enter the amount of food consumed by each monkey (in pounds):" << endl;
    inputMonkeyFoodData(foodData, MONKEY_COUNT);

    // Display food data
    cout << endl;
    displayFoodData(foodData, MONKEY_COUNT);

    // Calculate and display daily averages
    calculateAverageFoodPerDay(foodData, MONKEY_COUNT, dailyAverages);
    cout << "\nAverage food consumption per day (all monkeys):" << endl;
    for (int day = 0; day < DAYS_IN_WEEK; day++) {
        cout << "  " << DAYS_OF_WEEK[day] << ": " << dailyAverages[day] << " pounds" << endl;
    }

    // Display the least and greatest food day for each monkey
    cout << "\nDay with the least food consumed by each monkey:" << endl;
    for (int monkey = 0; monkey < MONKEY_COUNT; monkey++) {
        int leastFoodDay = getDayWithLeastFood(foodData[monkey]);
        cout << "  Monkey #" << monkey + 1 << ": " << DAYS_OF_WEEK[leastFoodDay] << endl;
    }

    cout << "\nDay with the most food consumed by each monkey:" << endl;
    for (int monkey = 0; monkey < MONKEY_COUNT; monkey++) {
        int mostFoodDay = getDayWithMostFood(foodData[monkey]);
        cout << "  Monkey #" << monkey + 1 << ": " << DAYS_OF_WEEK[mostFoodDay] << endl;
    }

    return 1;
}
