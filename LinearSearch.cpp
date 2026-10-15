#include <iostream>
using namespace std;

const int MAX = 100;
// Reading n student IDs into the array
void inputIDs(int arr[], int n) {
    cout << "Enter " << n << " student IDs:\n";
    for (int i = 0; i < n; i++) {
        cout << "ID[" << i << "]: ";
        cin >> arr[i];
    }
}

// Linear Search: This will return index of first occurrence or -1
int linearSearch(int arr[], int n, int target) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == target)
            return i;               // found -> return first occurrence
    }
    return -1;                      // not found (also covers n == 0)
}

// Displaying the result
void displayResult(int index) {
    if (index != -1)
        cout << "Student ID found at index: " << index << endl;
    else
        cout << "Student ID is not registered." << endl;
}

int main() {
    int n, target;
    int arr[MAX];

    cout << "=== Linear Search for Student ID ===\n";
    cout << "Enter number of students (n): ";
    cin >> n;

    if (n < 0 || n > MAX) {
        cout << "Invalid size.\n";
        return 1;
    }

    if (n > 0)
        inputIDs(arr, n);
    else
        cout << "Array is empty.\n";

    cout << "Enter the target Student ID to search: ";
    cin >> target;

    int index = linearSearch(arr, n, target);
    displayResult(index);


    return 0;
}