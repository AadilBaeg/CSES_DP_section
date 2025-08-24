/*
CSES Problem: Two Sets II
Link: https://cses.fi/problemset/task/1093/

Thought Process:
This is a classic dynamic programming subset sum counting problem. 
I realized the sum of numbers from 1 to n is n*(n+1)/2, so if it's odd, 
splitting into two equal subsets is impossible. Otherwise, I use DP to count 
the number of ways to form a subset with sum = total/2, optimizing space by 
storing only two DP rows at a time.
*/

#include <bits/stdc++.h>

using namespace std;
#define int long long
const int MOD = (int) 1e9 + 7;

// Solution class encapsulating the logic
class Solution {
  public: void solve() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    int t = (n * (n + 1)) / 2;
   // If total sum is odd, partition into two equal subsets is impossible
    if (t % 2 != 0) {
      cout << 0 << endl;
      return 0;
    }

    t /= 2;

    // DP array with 2 rows for space optimization
    int dp[2][t + 1];

    // Base case: There's exactly one way to achieve sum 0 (by picking nothing)    
    for (int i = 0; i < 2; i++)
      for (int j = 0; j <= t; j++)
        dp[i][j] = (j == 0);

    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= t; j++) {

        // Option 1: Exclude current number
        dp[i % 2][j] = dp[1 - i % 2][j];

        // Option 2: Include current number if possible
        if (j >= i) {
          dp[i % 2][j] += dp[1 - i % 2][j - i];
          dp[i % 2][j] %= mod;
        }
      }
    }
    cout << dp[1 - n % 2][t];
  }
};

/*
Time Complexity:
O(n * target) = O(n * totalSum/2) ≈ O(n^3) for large n 
(because totalSum ~ n^2), but works within CSES limits (n <= 500).

Space Complexity:
O(target) because we use only 2 rows of size target+1 for DP.

Key Idea:
We reduce the partition problem into counting subsets of sum totalSum/2. 
A bottom-up DP approach is used with space optimization. Each number from 
1 to n can either be included or not, and we accumulate the count modulo 1e9+7.
*/

signed main() {
  Solution().solve();
  return 0;
}
