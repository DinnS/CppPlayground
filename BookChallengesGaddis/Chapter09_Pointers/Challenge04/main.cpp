#include <iostream>

using namespace std;

/******************** prototypes ********************/

// Getting the user number with defined prompt and validation of integer value
int getUserNumber(string prompt);

// Getting the user string with defined prompt
string getUserString(string prompt);

// Getting the user array size with validation, more than 0
int getUserArraySize(string prompt = "Enter the array size: ", string errorPrompt = "Size of array must be more than 0");

// Filling the arrays with students name and score info
void fillStudentArrays(string *studentNames, int *studentScores, const int size);

// Display Student info arrays
void displayStudentsInfo(string *studentNames, int *studentScores, const int size);

// Sorting scores in ascending order
void sortStudentAscendingByScore(string *studentNames, int *studentScores, const int size);

// Calculating the average score in score Array
float calculateAverageScore(const int *studentScores, const int size);

/******************** main program ********************/
int main()
{

    int size = 0;
    float averageScore = 0.0;
    string *studentNames = nullptr;
    int *studentScores = nullptr;

    size = getUserArraySize("Enter the number of students: ", "The number of students must be more than 0");

    studentNames = new string[size];
    studentScores = new int[size];
 
    fillStudentArrays(studentNames, studentScores, size);

    cout << "\nScore array before ascending sort" << endl;
    displayStudentsInfo(studentNames, studentScores, size);

    sortStudentAscendingByScore(studentNames, studentScores, size);

    cout << "\nScore array after ascending sort" << endl;
    displayStudentsInfo(studentNames, studentScores, size);

    cout << "\n\nAverage score: " << calculateAverageScore(studentScores, size) << endl;

    // Free memory
    delete []studentNames;
    studentNames = nullptr;

    delete []studentScores;
    studentScores = nullptr;
    
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

string getUserString(string prompt) {

    string word = "";

    cout << prompt;
    cin >> word;

    return word;
}

int getUserArraySize(string prompt, string errorPrompt)
{
    int size = 0;
    bool isSizeValid = false;

    while (!isSizeValid)
    {
        size = getUserNumber(prompt);
        
        if (size > 0)
        {
            isSizeValid = true;
        }
        else
        {
            cout << errorPrompt << endl;
        }
    }

    return size;
}

void fillStudentArrays(string *studentNames, int *studentScores, const int size) 
{
    string studentName = "";
    int studentScore = 0;

    for(int i = 0; i < size; i++) {
        cout << "Enter student info #" << (i + 1) << ": \n";

        studentName = getUserString("Student name: ");

        studentScore = getUserNumber("Student score: ");

        if(studentName == "") {
            cout << "Student name can't be empty" << endl;
            i--;
        } else if(studentScore < 0)  {
            cout << "Student score can't be negative" << endl;
            i--;
        } else {
            *(studentNames + i) = studentName;
            *(studentScores + i) = studentScore;
        }

        cout << "----------------------------------\n";
    }

}

void displayStudentsInfo(string *studentNames, int *studentScores, const int size) {
    for(int i = 0; i < size; i++) {
        cout << (i + 1) << ". " << "Name: " << *(studentNames + i) << " | Score: " << *(studentScores + i) << endl;
    }
}

void sortStudentAscendingByScore(string *studentNames, int *studentScores, const int size)
{
    string tempWord = "";
    int tempNumber = 0;

    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < (size - i - 1); j++)
        {
            if (*(studentScores + j) > *(studentScores + (j + 1)))
            {
                // Swapping the word
                tempWord = *(studentNames + j);
                *(studentNames + j) = *(studentNames + (j + 1));
                *(studentNames + (j + 1)) = tempWord;

                // Swapping the numbers
                tempNumber = *(studentScores + j);
                *(studentScores + j) = *(studentScores + (j + 1));
                *(studentScores + (j + 1)) = tempNumber;
            }
        }
    }
}

float calculateAverageScore(const int *studentScores, const int size)
{
    float averageScore = 0.0;

    for (int i = 0; i < size; i++)
    {
        averageScore += *(studentScores + i);
    }

    averageScore /= size;

    return averageScore;
}