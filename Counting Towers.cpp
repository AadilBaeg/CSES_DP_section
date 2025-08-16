/*
Problem: Domino Tiling
Link: https://cses.fi/problemset/task/2413/

My thought process: I noticed that for each length n, the number of ways depends on
how the last few tiles are placed. I broke the problem into two states (tile = 1 or 2),
used recursion with memoization, and derived the recurrence relations. Precomputing
values up to the maximum n ensures fast answers for multiple test cases.
*/

#include <bits/stdc++.h>
using namespace std;
#define int long long

const int mex = (int)1e6 + 2;
const int mod = (int)1e9 + 7;

// dp[n][tile] stores the number of ways for length n and ending tile type
int dp[mex + 1][3];

class Solution {
public:
    // Recursive function with memoization
    int f(int n, int tile) {
        // Base case: for length 1, only 1 way
        if (n == 1) return 1;

        int &ans = dp[n][tile];
        if (ans != -1) return ans;

        ans = 0;

        if (tile == 1) {
            // Case when the ending configuration is of type 1
            // Transition from previous state (same or different)
            ans = f(n - 1, 1) + f(n - 1, 1) + f(n - 1, 2);
        } else {
            // Case when the ending configuration is of type 2
            // Transition involves more combinations (including double placement)
            ans = f(n - 1, 2) + f(n - 1, 2) + f(n - 1, 1) + 2 * f(n - 1, 2);
        }

        ans %= mod;
        return ans;
    }

    void solve() {
        memset(dp, -1, sizeof dp);
        int tc; 
        cin >> tc;

        // Precompute values up to max constraint for efficiency
        f(mex, 1);
        f(mex, 2);

        while (tc--) {
            int n; 
            cin >> n;
            // Total ways is sum of both states
            int ans = f(n, 1) + f(n, 2);
            ans %= mod;
            cout << ans << endl;
        }
    }
};

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    Solution sol;
    sol.solve();
    return 0;
}
