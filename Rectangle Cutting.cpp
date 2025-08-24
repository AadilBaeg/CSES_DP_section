// CSES Problem: Rectangle Cutting
// Link: https://cses.fi/problemset/task/1744/
//
// Thought process:
// I saw this as a DP problem where each rectangle (a x b) can be split either
// vertically or horizontally until we get squares. My approach is to use a
// 2D DP table where dp[i][j] represents the minimum number of cuts needed
// for a rectangle of size i x j. I initialize dp[i][i] = 0 since squares need
// no cuts, and for each state, I try all possible vertical and horizontal cuts
// to find the minimum. This bottom-up DP guarantees that all subproblems are
// solved efficiently.
//
// Time complexity: O(a * b * (a + b))
//   - For each rectangle size (a x b), we try all vertical (a-1) and horizontal (b-1) cuts.
//   - In worst case, a = b = 500 → ~500 * 500 * 1000 = 250M iterations.
//     This is acceptable in C++ with optimizations.
//
// Space complexity: O(a * b)
//   - We store a DP table of size (a+1) x (b+1), which fits comfortably in memory.

#include <bits/stdc++.h>
using namespace std;
#define int long long

class Solution {
public:
    void solve() {
        int a, b;
        cin >> a >> b;
        mex = a * b + 1; // Maximum cuts possible, used for initialization
        cout << minCuts(a, b);
    }

private:
    int mex; // Large initial value for DP table

    int minCuts(int a, int b) {
        const int MAX = 502; // Constraint limit for rectangle dimensions
        int dp[MAX][MAX];

        // Initialize DP table with a large value
        for (int i = 0; i < MAX; i++) {
            for (int j = 0; j < MAX; j++) {
                dp[i][j] = mex;
            }
        }

        // A square needs no cuts
        for (int i = 0; i < MAX; i++) {
            dp[i][i] = 0;
        }

        // Fill DP table bottom-up
        for (int i = 1; i <= a; i++) {
            for (int j = 1; j <= b; j++) {
                // Try vertical cuts
                for (int k = 1; k < i; k++) {
                    dp[i][j] = min(dp[i][j], 1 + dp[k][j] + dp[i - k][j]);
                }
                // Try horizontal cuts
                for (int k = 1; k < j; k++) {
                    dp[i][j] = min(dp[i][j], 1 + dp[i][k] + dp[i][j - k]);
                }
            }
        }

        return dp[a][b]; // Minimum cuts for a rectangle of size a x b
    }
    int minCutsRecursive_NotUsed_ButIterativeIsDerivedFromThisMethod(int a, int b) {
          if(a == b) return 0;
         	int& ans = dp[a][b];
         	if(ans != -1) return ans;
         
         	ans = mex;
         
         	for(int i = 1; i < a; i++) {
         		ans = min(ans, 1 + f(i, b) + f(a - i, b));
         	}
         	for(int i = 1; i < b; i++) {
         		ans = min(ans, 1 + f(a, i) + f(a, b - i));
         	}
         	return	 ans;
    }
};

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    Solution solution;
    solution.solve();
}
