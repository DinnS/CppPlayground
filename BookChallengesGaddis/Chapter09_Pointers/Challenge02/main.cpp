#include <iostream>

using namespace std;

/******************** prototypes ********************/

// Getting the user number with defined prompt and validation of integer value
int getUserNumber(string prompt);

// Getting the user array size with validation, more than 0
int getUserArraySize();

// Filling the array score, using user defined score and with validation, more than 0
void fillScoreArray(int *scoreArray, const int size);

// Display array
void displayArray(const int *array, const int size);

// Sorting scores in ascending order
void sortScoreAscending(int *scoreArray, const int size);

// Calculating the average score in score Array
float calculateAverageScore(const int *scoreArray, const int size);

/******************** main program ********************/
int main()
{

    int size = 0;
    float averageScore = 0.0;
    int *scores = nullptr;

    size = getUserArraySize();

    scores = new int[size];

    fillScoreArray(scores, size);

    cout << "\nScore array before ascending sort" << endl;
    displayArray(scores, size);

    sortScoreAscending(scores, size);

    cout << "\n\nScore array after ascending sort" << endl;
    displayArray(scores, size);

    averageScore = calculateAverageScore(scores, size);
    cout << "\n\nAverage score: " << averageScore;

    // Free memory
    delete []scores;
    scores = nullptr;
    
    cout << endl;

    return 0;
}

/******************** functions implementation ********************/

int getUserNumber(string prompt)
{
    int number = 0;
    bool isNumberValid = false;

    while (!isNumberValid)
    {
        cout << prompt;
        cin >> number;

        if (cin.fail())
        {
            cout << "Number must be integer" << endl;

            // Clear the input, for immediately next using
            cin.clear();
            cin.ignore();
        }
        else
        {
           isNumberValid = true;
        }
    }

    return number;
}

int getUserArraySize()
{
    int size = 0;
    bool isSizeValid = false;

    while (!isSizeValid)
    {
        size = getUserNumber("Enter the array size: ");
        
        if (size > 0)
        {
            isSizeValid = true;
        }
        else
        {
            cout << "Size of array must be more than 0" << endl;
        }
    }

    return size;
}

void fillScoreArray(int *scoreArray, int size)
{
    int scoreNumber = 0;

    for (int i = 0; i < size; i++)
    {
        scoreNumber = getUserNumber("Enter #" + to_string(i + 1) + " score: ");

        if (scoreNumber <= 0)
        {
            cout << "Score must be more than 0" << endl;
            i--;
        }
        else
        {
            *(scoreArray + i) = scoreNumber;
        }
    }
}

void displayArray(const int *array, const int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << *(array + i) << " ";
    }
}

void sortScoreAscending(int *scoreArray, const int size)
{
    int tempNumber = 0;

    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < (size - i - 1); j++)
        {
            if (*(scoreArray + j) > *(scoreArray + (j + 1)))
            {
                // Swapping the numbers
                tempNumber = *(scoreArray + j);
                *(scoreArray + j) = *(scoreArray + (j + 1));
                *(scoreArray + (j + 1)) = tempNumber;
            }
        }
    }
}

float calculateAverageScore(const int *scoreArray, const int size)
{
    float averageScore = 0.0;

    for (int i = 0; i < size; i++)
    {
        averageScore += *(scoreArray + i);
    }

    averageScore /= size;

    return averageScore;
}