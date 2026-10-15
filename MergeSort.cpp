#include <iostream>
using namespace std;

const int MAX = 100;

// Merging two sorted halves: arr[left..mid] and arr[mid+1..right]
void merge(int arr[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    // Temporary arrays
    int* L = new int[n1];
    int* R = new int[n2];

    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = left;

    // Comparing the smallest remaining elements of both halves
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    // Copying remaining elements
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }

    delete[] L;
    delete[] R;
}

// Recursive Merge Sort
void mergeSort(int arr[], int left, int right) {
    if (left >= right)          // base case: 0 or 1 element
        return;

    int mid = left + (right - left) / 2;

    mergeSort(arr, left, mid);       // sorting left half
    mergeSort(arr, mid + 1, right);  // sorting right half
    merge(arr, left, mid, right);    // merge the two halves
}

// Displaying the array
void displayArray(int arr[], int n) {
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main() {
    int n;
    int arr[MAX];

    cout << "=== Task 3: Merge Sort for Student Marks ===\n";
    cout << "Enter number of students (n): ";
    cin >> n;

    if (n < 0 || n > MAX) {
        cout << "Invalid size.\n";
        return 1;
    }

    if (n > 0) {
        cout << "Enter the marks:\n";
        for (int i = 0; i < n; i++) {
            cout << "Mark[" << i << "]: ";
            cin >> arr[i];
        }
    }

    cout << "\nArray before sorting: ";
    displayArray(arr, n);

    mergeSort(arr, 0, n - 1);

    cout << "Array after sorting : ";
    displayArray(arr, n);

    return 0;
}


