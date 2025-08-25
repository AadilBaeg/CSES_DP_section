/*
CSES Problem: Removal Game
Link: https://cses.fi/problemset/task/1097/

Thought Process:
I realized this is a two-player game where both play optimally. 
To maximize my sum, I either take the leftmost or rightmost number, 
and my opponent will also try to minimize my future gain. 
I used dynamic programming to compute the best score for each subarray.

Time Complexity: O(n^2) because we fill a DP table of size n x n.
Space Complexity: O(n^2) for the DP table to store results for each subarray.
*/

#include <bits/stdc++.h>

using namespace std;
#define int long long

// Global variables for array size and values
int arr[5002];
int n;
int dp[5002][5002]; // For memoization in recursive approach (not used in final)

// Recursive DP solution (kept for reference; leads to TLE for n=5000)
int f(int i, int j) {
  if (i > j) return 0; // No elements left
  if (i == j) return arr[i]; // Single element
  if (i + 1 == j) return max(arr[i], arr[j]); // Two elements: take the max

  int & ans = dp[i][j];
  if (ans != -1) return ans; // Return cached answer

  // Choose either left or right, minimizing opponent's next move
  ans = max(arr[i] + min(f(i + 2, j), f(i + 1, j - 1)),
    arr[j] + min(f(i, j - 2), f(i + 1, j - 1)));
  return ans;
}

// Class containing the iterative DP solution (optimized)
class Solution {
  // this is kinda of completely derived from f(i, j) function.
  public: void solve() {
    // 2D DP table where d[i][j] stores the best score from arr[i..j]
    int d[n + 1][n + 1];
    for (int i = n - 1; i >= 0; i--) {
      for (int j = 0; j < n; j++) {
        if (i > j) d[i][j] = 0;
        else if (i == j) d[i][i] = arr[i];
        else if (i + 1 == j) d[i][j] = max(arr[i], arr[j]);
        else {
          d[i][j] = max(arr[i] + min(d[i + 2][j], d[i + 1][j - 1]), arr[j] + min(d[i][j - 2], d[i + 1][j - 1]));
        }
      }
    }
    // Maximum sum the first player can achieve
    cout << d[0][n - 1];
  }
};

signed main() {
  cin >> n;
  for (int i = 0; i < n; i++)
    cin >> arr[i];

  memset(dp, -1, sizeof dp); // Initialize memoization table (unused in final)

  Solution sol;
  sol.solve();
}
