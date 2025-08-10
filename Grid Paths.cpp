// Problem: Grid Paths
// Link: https://cses.fi/problemset/task/1638/
// Thought process: This problem is a classic grid DP where we count the number of ways to move from the 
// top-left corner to the bottom-right corner, moving only right or down, while avoiding blocked cells. 
// I used a top-down recursive DP with memoization to store results for each cell.

#include <bits/stdc++.h>
using namespace std;

#define int long long

class Solution {
public:
    int m;                                      // Grid size (m x m)
    vector<vector<char>> arr;                   // Grid representation
    const int mod = 1e9 + 7;                    // Modulo for large counts
    int dp[1002][1002];                         // dp[i][j] = ways to reach (i,j)

    // Recursive function to count paths from (1,1) to (r,c)
    int f(int r, int c) {
        if (r == 0 || c == 0) return 0;         // Out of bounds
        if (r == 1 && c == 1) {                 // Starting cell
            return arr[r][c] == '.';
        }

        int &ans = dp[r][c];
        if (ans != -1) return ans;              // Return cached result

        ans = 0;
        if (arr[r][c] == '.') {
            // Ways to reach (r,c) = from left + from top
            ans += f(r, c - 1) + f(r - 1, c);
            ans %= mod;
        }
        return ans;
    }

    void solve() {
        memset(dp, -1, sizeof dp);
        cin >> m;
        arr.assign(m + 1, vector<char>(m + 1, '.'));

        // Read grid (1-indexed for simplicity)
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= m; j++) {
                cin >> arr[i][j];
            }
        }

        cout << f(m, m);
    }
};

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    Solution sol;
    sol.solve();
}
