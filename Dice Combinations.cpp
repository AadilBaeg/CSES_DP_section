// Problem: Dice Combinations
// Link: https://cses.fi/problemset/task/1633/
// Thought process: I recognized this as a classic dynamic programming problem where the number of ways 
// to reach sum `n` is the sum of ways to reach `n-1`, `n-2`, ..., `n-6`. I used recursion with memoization 
// to avoid recalculating subproblems and applied modulo to handle large numbers.

#include <bits/stdc++.h>
using namespace std;

// Define the modulo constant for large number handling
#define mod ((int)1e9 + 7)

// DP array to store intermediate results (memoization)
int dp[(int)1e6 + 2];

class Solution {
public:
    // Recursive function to calculate number of ways to get sum `n`
    int f(int n) {
        if (n == 0) return 1; // Base case: only 1 way to get sum 0 (no dice rolled)

        int &ans = dp[n]; // Reference to dp[n] for storing/retrieving computed value
        if (ans != -1) return ans; // If already computed, return stored value

        ans = 0; // Initialize answer for current `n`

        // Try all dice outcomes from 1 to 6
        for (int i = 1; i <= 6 && n - i >= 0; i++) {
            ans += f(n - i);  // Add ways from smaller subproblems
            ans %= mod;       // Keep result within modulo limit
        }

        return ans;
    }

    void solve() {
        int n;
        cin >> n;

        // Initialize dp array with -1 meaning "not computed yet"
        memset(dp, -1, sizeof dp);

        // Compute and print the number of ways to get sum n
        cout << f(n);
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    Solution sol;
    sol.solve();
}