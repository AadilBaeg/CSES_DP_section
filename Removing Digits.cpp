// Problem: Removing Digits
// Link: https://cses.fi/problemset/task/1637/
// Thought process: I saw that at each step, we can subtract one of the digits of `n` to reduce it.
// This naturally leads to a recursive solution where we try all possible digit choices and pick the minimum steps.
// Memoization is used to avoid recalculating results for the same `n`.

#include <bits/stdc++.h>
using namespace std;

#define int long long

class Solution {
public:
    int n;                            // The starting number
    int dp[(int)1e6 + 2];              // dp[x] = min steps to reduce x to 0

    // Recursive function to compute min steps to reduce `x` to 0
    int f(int x) {
        if (x == 0) return 0;          // Already at 0 → no steps needed
        if (x < 0) return INT_MAX;     // Invalid case → very large value

        int &ans = dp[x];
        if (ans != -1) return ans;     // Return cached result if already computed

        ans = INT_MAX;

        // Try subtracting each digit of x
        for (auto c : to_string(x)) {
            ans = min(ans, 1 + f(x - (c - '0')));
        }
        return ans;
    }

    void solve() {
        memset(dp, -1, sizeof dp);     // Initialize DP array
        cin >> n;
        cout << f(n);
    }
};

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    Solution sol;
    sol.solve();
}
