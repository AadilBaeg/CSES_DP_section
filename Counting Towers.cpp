/*
Problem: Domino Tiling
Link: https://cses.fi/problemset/task/2413/

My thought process:

Initially, I approached the problem by considering two states for each column:
- tile type 1 (ending with vertical dominoes)
- tile type 2 (ending with horizontal/L-shaped domino arrangements)

This led to the recursive function f(n, tile) with memoization:
- dp[n][tile] stores the number of ways to tile 2xn with the last column in state 'tile'.
- Recurrence:
    - f(n,1) = f(n-1,1) + f(n-1,1) + f(n-1,2)
    - f(n,2) = f(n-1,2) + f(n-1,2) + f(n-1,1) + 2*f(n-1,2)

With a bit of manipulation in above two equations, we can remove the second dimension s.t.
dp[n] = f(n,1) + f(n,2), can be expressed as a simpler recurrence:

    dp[n] = 4 * dp[n-1] + dp[n-2]

- Base cases: dp[1] = 2 (vertical or horizontal), dp[2] = 8 (these two by manually observing and doing on rough page)
- This eliminates the need for two states, allowing a **single 1-D DP**.
- We can implement this either iteratively or recursively with memoization.

Thus, fOptimized(n) implements this simpler 1-D recursive DP.
*/

/*
Note: In this code, we still call the original f() for demonstration,
but the optimized fOptimized() can be called instead for cleaner, faster computation.
*/

#include <bits/stdc++.h>
using namespace std;
#define int long long

const int mex = (int)1e6 + 2;
const int mod = (int)1e9 + 7;

// Global memoization array for optimized recursive approach
int memo[mex + 1];

// Global dp array for original 2-D DP recursive approach
int dp[mex + 1][3];

class Solution {
public:
    // Original recursive function with 2-D DP
    int f(int n, int tile) {
        if (n == 1) return 1;  // Base case: only 1 way for length 1

        int &ans = dp[n][tile];
        if (ans != -1) return ans;

        ans = 0;
        if (tile == 1) {
            // Ending with configuration type 1
            ans = f(n - 1, 1) + f(n - 1, 1) + f(n - 1, 2);
        } else {
            // Ending with configuration type 2
            ans = f(n - 1, 2) + f(n - 1, 2) + f(n - 1, 1) + 2 * f(n - 1, 2);
        }

        ans %= mod;
        return ans;
    }

    // Optimized recursive function using 1-D DP
    int fOptimized(int n) {
        if (n == 1) return 2; // Base case: 2 ways for 2x1
        if (n == 2) return 8; // Base case: 8 ways for 2x2

        if (memo[n] != -1) return memo[n];

        // Recurrence: total ways = 4*dp[n-1] + dp[n-2]
        memo[n] = (4 * fOptimized(n - 1) + fOptimized(n - 2)) % mod;
        return memo[n];
    }

    void solve() {
        memset(dp, -1, sizeof dp); // Initialize global dp array
        int tc;
        cin >> tc;

        // Precompute values up to max constraint for efficiency
        f(mex, 1);
        f(mex, 2);

        while (tc--) {
            int n;
            cin >> n;
            int ans = f(n, 1) + f(n, 2);
            ans %= mod;
            cout << ans << "\n";

            // Alternatively, we could call the optimized single DP recursive solution:
            // cout << fOptimized(n) << "\n";
        }
    }
};

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    Solution sol;

    // Initialize global memo array for fOptimized
    memset(memo, -1, sizeof memo);

    sol.solve();

    return 0;
}
