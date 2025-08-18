// Longest Common Subsequence
// Problem link: https://cses.fi/problemset/task/3403/
//
// My thought process: I recognized this as a classic dynamic programming problem.
// I used recursion with memoization to compute the LCS length, and then backtracked
// through the dp table to reconstruct the actual subsequence.

#include <bits/stdc++.h>
using namespace std;
#define int long long

// Global arrays for input sequences and dp table
int a[1002], b[1002];
int dp[1002][1002];

class Solution {
public:
    // Recursive function to compute the length of LCS of first m and n elements
    int f(int m, int n) {
        if (m == 0 || n == 0) return 0; // Base case: empty sequence
        int& ans = dp[m][n];
        if (ans != -1) return ans;      // Return memoized result if available

        ans = 0;
        if (a[m - 1] == b[n - 1]) {
            // If last elements match, include them in LCS
            ans = 1 + f(m - 1, n - 1);
        } else {
            // Otherwise, take the max by excluding one element from either sequence
            ans = max(f(m, n - 1), f(m - 1, n));
        }
        return ans;
    }

    // Function to reconstruct the LCS sequence using dp table
    vector<int> getLCS(int m, int n) {
        vector<int> result;
        while (m > 0 && n > 0) {
            if (a[m - 1] == b[n - 1]) {
                // If elements match, they are part of LCS
                result.push_back(a[m - 1]);
                m--, n--;
            } else if (dp[m - 1][n] > dp[m][n - 1]) {
                // Move in the direction of the larger dp value
                m--;
            } else {
                n--;
            }
        }
        reverse(result.begin(), result.end()); // Reverse to get correct order
        return result;
    }

    void solve() {
        memset(dp, -1, sizeof dp); // Initialize dp table with -1
        int m, n;
        cin >> m >> n;
        for (int i = 0; i < m; i++) cin >> a[i];
        for (int i = 0; i < n; i++) cin >> b[i];

        cout << f(m, n) << endl; // Print length of LCS

        // Print the actual LCS sequence
        for (auto i : getLCS(m, n)) {
            cout << i << ' ';
        }
        cout << endl;
    }
};

signed main() {
    Solution sol;
    sol.solve();
    return 0;
}
