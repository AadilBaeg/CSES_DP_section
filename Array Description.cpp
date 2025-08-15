// CSES Problem: Array Description
// Link: https://cses.fi/problemset/task/1746/
//
// My Thought Process:
// I realized that the problem essentially asks for the count of valid arrays
// where adjacent elements differ by at most 1. I decided to use DP with states
// representing the remaining elements to fill and the last chosen value.
// By filling from the end backwards, I can reuse results for overlapping subproblems.

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int m;                               // Upper bound for values in the array
    vector<int> arr;                     // The given array (0 = wildcard position)
    int mod = (int)1e9 + 7;               // Modulo for results
    vector<vector<int>> dp;              // Memoization table: dp[remaining][lastEle]

    // Recursive DP function
    // n = number of elements left to process (from the end)
    // lastEle = value of the next fixed element in the array
    int f(int n, int lastEle) {
        // Base case: no elements left to process → one valid way
        if (n == 0) return 1;

        // Special case: only one element left to process
        if (n == 1) {
            if (arr[n - 1] != 0) {
                // If it's fixed, check adjacency condition with lastEle
                return abs(arr[n - 1] - lastEle) <= 1;
            } else {
                // If it's a wildcard, it can be lastEle-1, lastEle, or lastEle+1 (within bounds)
                return (lastEle - 1 >= 1) + 1 + (lastEle + 1 <= m);
            }
        }

        // If already computed, return cached result
        int &ans = dp[n][lastEle];
        if (ans != -1) return ans;

        ans = 0; // Initialize answer for this state

        if (arr[n - 1] != 0) {
            // Fixed value at position n-1
            if (abs(arr[n - 1] - lastEle) <= 1) {
                ans += f(n - 1, arr[n - 1]);
                ans %= mod;
            }
        } else {
            // Wildcard value at position n-1 → try all adjacent possibilities
            for (auto i : {lastEle - 1, lastEle, lastEle + 1}) {
                if (i >= 1 && i <= m) {
                    ans += f(n - 1, i);
                    ans %= mod;
                }
            }
        }

        return ans;
    }

    void solve() {
        int n;
        cin >> n >> m;
        arr.resize(n);
        dp.assign(n + 1, vector<int>(m + 1, -1));

        for (auto &i : arr)
            cin >> i;

        int ans = 0;
        if (arr[n - 1] == 0) {
            // Last position is a wildcard → try all possible last values
            for (int i = 1; i <= m; i++) {
                ans += f(n - 1, i);
                ans %= mod;
            }
        } else {
            // Last position is fixed
            ans += f(n - 1, arr.back());
        }

        cout << ans;
    }
};

int main() {
    Solution s;
    s.solve();
}
