// A1: Fibonacci numbers, non-recursive vs recursive
// Non-recursive: Time O(n),   Space O(1)
// Recursive:     Time O(2^n), Space O(n) for the recursion stack
#include <iostream>
#include <string>
using namespace std;

int calls = 0;

int fibIterative(int n) {
    int a = 0, b = 1;
    for (int i = 1; i <= n; i++) {
        int c = a + b;
        a = b;
        b = c;
        cout << "Step " << i << ": F(" << i << ") = " << a << endl;
    }
    return a;
}

int fibRecursive(int n) {
    calls++;
    if (n <= 1)
        return n;
    return fibRecursive(n - 1) + fibRecursive(n - 2);
}

int main() {
    int n;
    cout << "Enter n: ";
    cin >> n;

    cout << "\nNon-recursive:" << endl;
    int result = fibIterative(n);
    cout << "F(" << n << ") = " << result << ", steps = " << n << endl;

    cout << "\nRecursive (call tree):" << endl;
    result = fibRecursive(n);
    cout << "F(" << n << ") = " << result << ", calls = " << calls << endl;
    return 0;
}
