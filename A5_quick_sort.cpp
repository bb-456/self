// A5: Quick Sort, deterministic (last element as pivot) vs randomized (random pivot)
// Best/average O(n log n). Worst O(n^2): deterministic hits it on already-sorted input.
// Randomized: expected O(n log n) for every input. Space O(log n) average (recursion).
// This is a Divide and Conquer algorithm.
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <ctime>
using namespace std;

int comparisions = 0;

int partition(vector<int>& a, int low, int high) {
    int pivot = a[high], i = low - 1;
    cout << pivot << " ";
    for (int j = low; j < high; j++) {
        comparisions++;
        if (a[j] <= pivot) {
            swap(a[++i], a[j]);
        }
    }
    swap(a[i+1], a[high]);
    return i+1;
}

int randomPartition(vector<int>& a, int low, int high) {
    int random_pivot = low + rand() % (high - low + 1);
    swap(a[random_pivot], a[high]);
    return partition(a, low, high);
}

void quickSort(vector<int>& a, int low, int high, bool isRandom) {
    if (low < high) {
        int pivot_index;
        if (isRandom) {
            pivot_index = randomPartition(a, low, high);
        }
        else{
            pivot_index = partition(a, low, high);
        }
        quickSort(a, low, pivot_index-1, isRandom);
        quickSort(a, pivot_index+1, high, isRandom);
    }
}

int main() {
    srand(time(0));
    int n;
    cout << "Enter n :";
    cin >> n;
    vector<int> arr(n);
    cout << "Enter " << n << " numbers: ";
    for (int i=0; i<n; i++) cin >> arr[i];

    cout << "\nInitial Array: ";
    for (int x : arr) cout << x << " ";
    cout << endl;

    // 1. Deterministic Quick Sort
    vector<int> a1 = arr;
    comparisions = 0;
    cout << "\n--- Deterministic Quick Sort ---" << endl;
    cout << "Pivots chosen: ";
    quickSort(a1, 0, n-1, false); // IMPORTANT
    cout << "\nSorted Array: ";
    for (int x : a1) cout << x << " ";
    cout << "\nComparisions : " << comparisions << endl;

    // 2. Randomised Quick Sort
    vector<int> a2 = arr;
    comparisions = 0;
    cout << "\n--- Randomized Quick Sort ---" << endl;
    cout << "\nPivots chosen: ";
    quickSort(a2, 0, n-1, true); // IMPORTANT
    cout << "\nSorted Array: ";
    for (int x : a2) cout << x << " ";
    cout << "\nComparisions : " << comparisions << endl;

    return 0;
}