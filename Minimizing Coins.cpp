// Problem: Minimizing Coins
// Link: https://cses.fi/problemset/task/1634/
// Thought process: I recognized this as a classic unbounded knapsack problem, 
// where we need to find the minimum number of coins to make a sum `w` from given denominations. 
// I used an iterative dynamic programming approach with a 2-row rolling array to optimize memory usage.

#include <bits/stdc++.h>
using namespace std;

#define int long long // Use long long to handle large values safely

class Solution {
public:
    int n, w;          // Number of coin types and target sum
    int arr[102];      // Array to store coin denominations

    // Core iterative DP function
    int iterative_f() {
        // dp[2][w+1]: Rolling array to reduce memory usage from O(n*w) to O(2*w)
        // dp[i%2][j] = min coins to make sum j using first i coins
        int dp[2][w + 1];

        // Initialize all states to "infinity" (unreachable)
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j <= w; j++) {
                dp[i][j] = INT_MAX;
            }
        }

        // Base case: 0 coins needed to make sum 0
        dp[0][0] = dp[1][0] = 0;

        // Process each coin type
        for (int i = 0; i < n; i++) {
            for (int j = 1; j <= w; j++) {
                // If we can use this coin without going negative in sum
                if (j - arr[i] >= 0) {
                    dp[i % 2][j] = 1 + dp[i % 2][j - arr[i]]; // Take the coin
                }
                // Always take the better option: use coin or skip it
                dp[i % 2][j] = min(dp[i % 2][j], dp[1 - i % 2][j]);
            }
        }

        // Return result or -1 if unreachable
        return dp[1 - n % 2][w] == INT_MAX ? -1 : dp[1 - n % 2][w];
    }

    void solve() {
        // Read inputs
        cin >> n >> w;
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }

        // Output result
        cout << iterative_f();
    }
};

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    Solution sol;
    sol.solve();
}
