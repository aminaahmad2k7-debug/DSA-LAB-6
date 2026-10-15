#include <iostream>
using namespace std;

const int MAX = 100;

// Reading registration numbers
void inputSortedIDs(int arr[], int n) {
    cout << "Enter " << n << " registration numbers in ascending order:\n";
    for (int i = 0; i < n; i++) {
        cout << "ID[" << i << "]: ";
        cin >> arr[i];
    }
}

// Check whether the array is sorted in ascending order
bool isSorted(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        if (arr[i] < arr[i - 1])
            return false;
    }
    return true;
}

// Iterative Binary Search
int binarySearch(int arr[], int low, int high, int target) {
    while (low <= high) {
        int mid = low + (high - low) / 2;   // avoids overflow

        if (arr[mid] == target)
            return mid;                     // found

        if (arr[mid] < target)
            low = mid + 1;                  // searching right half
        else
            high = mid - 1;                 // searching left half
    }
    return -1;                              // not found (also covers n == 0)
}

int main() {
    int n, target;
    int arr[MAX];

    cout << "=== Binary Search on Sorted Registration IDs ===\n";
    cout << "Enter number of students (n): ";
    cin >> n;

    if (n < 0 || n > MAX) {
        cout << "Invalid size.\n";
        return 1;
    }

    if (n > 0)
        inputSortedIDs(arr, n);
    else
        cout << "Array is empty.\n";

    if (!isSorted(arr, n)) {
        cout << "Error: Array is not sorted. Binary search requires sorted input.\n";
        return 1;
    }

    cout << "Enter the target Registration ID: ";
    cin >> target;

    int index = binarySearch(arr, 0, n - 1, target);

    if (index != -1)
        cout << "Found at index: " << index << endl;
    else
        cout << "Not found." << endl;

    return 0;
}