// A3: 0-1 Knapsack using Dynamic Programming
// dp[i][w] = best value using the first i items with capacity w
// Time O(n * W), Space O(n * W)
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n, W;
    cout << "Number of items: ";
    cin >> n;
    vector<int> val(n), wt(n);
    cout << "Values : ";
    for (int i = 0; i < n; i++) cin >> val[i];
    cout << "Weights: ";
    for (int i = 0; i < n; i++) cin >> wt[i];
    cout << "Capacity: ";
    cin >> W;

    // Creating the initial DP Table
    vector<vector<int>> dp(n + 1, vector<int>(W + 1, 0));

    // Processing all items
    for (int i = 1; i <= n; i++) {
        for (int w = 0; w <= W; w++) {
            dp[i][w] = dp[i - 1][w];  // don't take item i
            if (wt[i - 1] <= w)       // or take it, if it fits
                dp[i][w] = max(dp[i][w], val[i - 1] + dp[i - 1][w - wt[i - 1]]);
        }
    }

    cout << "\nDP table:" << endl;
    for (int i = 0; i <= n; i++) {
        for (int w = 0; w <= W; w++)
            cout << dp[i][w] << "\t";
        cout << endl;
    }

    cout << "\nMaximum value = " << dp[n][W] << endl;
    
    cout << "Items selected: ";
    for (int i = n, w = W; i > 0; i--) {
        if (dp[i][w] != dp[i - 1][w]) {  // value changed, so item i was taken
            cout << i << " ";
            w -= wt[i - 1];
        }
    }
    cout << endl;
    return 0;
}
