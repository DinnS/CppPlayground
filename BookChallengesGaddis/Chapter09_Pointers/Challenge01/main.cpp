#include <iostream>

using namespace std;

int main() {

    int number = 200;

    int *ptr = nullptr;

    ptr = &number;

    cout << "Number before: " << *ptr << endl;

    cin >> *ptr;

    cout << "Number after: " << *ptr << endl;


    return 1;
}