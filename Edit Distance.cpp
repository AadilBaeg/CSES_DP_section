// CSES Problem: Edit Distance
// Link: https://cses.fi/problemset/task/1639/
//
// My Thought Process:
// I recognized this as the classic edit distance (Levenshtein distance) problem.
// My approach was to use recursion with memoization, where the state represents
// the minimum operations needed to convert the first m characters of 'a' into
// the first n characters of 'b'. At each step, I either match characters or
// choose the cheapest edit (insert, delete, replace).

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string a, b;                 // Input strings
    int dp[5002][5002];          // dp[m][n] = min operations to convert first m chars of a to first n chars of b

    // Recursive DP function
    int f(int m, int n) {
        // Base case: if one string is empty, need to insert/delete all characters of the other
        if (m == 0 || n == 0) return max(m, n);

        // Check memoized result
        int &ans = dp[m][n];
        if (ans != -1) return ans;

        if (a[m - 1] == b[n - 1]) {
            // Characters match → no operation needed here
            ans = f(m - 1, n - 1);
        } else {
            // Characters differ → take min of replace, insert, delete
            ans = 1 + min({
                f(m - 1, n - 1), // Replace
                f(m, n - 1),     // Insert into 'a'
                f(m - 1, n)      // Delete from 'a'
            });
        }
        return ans;
    }

    void solve() {
        memset(dp, -1, sizeof dp);

        cin >> a >> b;
        int m = (int)a.size();
        int n = (int)b.size();

        int ans = f(m, n);
        cout << ans;
    }
};

int main() {
    Solution s;
    s.solve();
}
