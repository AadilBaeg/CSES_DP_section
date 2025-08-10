// Problem: Coin Combinations I
// Link: https://cses.fi/problemset/task/1635/
// Thought process: This is a variation of the unbounded knapsack problem where the order of coins matters — 
// meaning we are counting permutations of coins that sum to `w`. I used a top-down recursive DP 
// with memoization to avoid recalculating the number of ways for the same remaining sum.

#include <bits/stdc++.h>
using namespace std;

#define int long long

class Solution {
public:
    int n, w;                      // Number of coin types and target sum
    int arr[102];                  // Coin denominations
    const int mod = 1e9 + 7;        // Modulo constant to prevent overflow
    int dp[(int)1e6 + 2];           // Memoization array for storing results

    // Recursive function to count permutations to make sum `target`
    int f(int target) {
        // Base case: If target is negative, no valid way; if zero, exactly 1 way (no coins)
        if (target <= 0) return target == 0;

        int &ans = dp[target];       // Reference to stored result
        if (ans != -1) return ans;   // Return cached value if computed before

        ans = 0;                     // Initialize ways for this target sum

        // Try every coin — order matters here, so all choices are explored
        for (int i = 0; i < n; i++) {
            ans += f(target - arr[i]);
            ans %= mod;              // Keep result within modulo
        }

        return ans;
    }

    void solve() {
        cin >> n >> w;
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }

        // Initialize DP array with -1 meaning "uncomputed"
        memset(dp, -1, sizeof dp);

        // Compute and output the number of permutations to reach sum w
        cout << f(w);
    }
};

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    Solution sol;
    sol.solve();
}
