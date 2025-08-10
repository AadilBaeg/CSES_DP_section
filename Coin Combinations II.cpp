// Problem: Coin Combinations II
// Link: https://cses.fi/problemset/task/1636/
// Thought process: I recognized this as a classic unbounded knapsack variation where order of coins 
// does not matter — combinations, not permutations. I used an iterative DP with a rolling array to 
// count the number of ways to make a sum `w` using given coin denominations, applying modulo to 
// prevent overflow.

#include <bits/stdc++.h>
using namespace std;

#define int long long

class Solution {
public:
    int n, w;          // Number of coin types and target sum
    int arr[102];      // Coin denominations
    const int mod = 1e9 + 7;

    // Iterative DP approach with rolling array optimization
    int iterative_f() {
        // dp[2][w+1]: Rolling array, dp[i%2][j] = number of ways to make sum j using first i coins
        int dp[2][w + 1];
        memset(dp, 0, sizeof dp);

        // Base case: There is exactly 1 way to make sum 0 irrespective of the number of coins you have — take no coins
        dp[0][0] = dp[1][0] = 1;

        // Process each coin type one by one
        for (int i = 0; i < n; i++) {
            for (int j = 1; j <= w; j++) {
                // By default, you can skip current coin
                dp[i % 2][j] = dp[1 - i % 2][j];

                // If we can use current coin without going negative
                if (j - arr[i] >= 0) {
                    // Add ways from the current row (plus, also allow multiple uses of the same coin)
                    dp[i % 2][j] += dp[i % 2][j - arr[i]];
                }

                // Keep result within modulo limit
                dp[i % 2][j] %= mod;
            }
        }

        // Final result is in row (1 - n%2) after processing all coins
        return dp[1 - n % 2][w];
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
