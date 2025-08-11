// Problem: Book Shop
// Link: https://cses.fi/problemset/task/1158/
// Thought process: This is a classic 0/1 knapsack problem where we maximize the total number of pages 
// we can buy without exceeding the budget `w`. I used an iterative DP with a rolling array to optimize memory, 
// where dp[i%2][j] represents the maximum pages achievable using the first i books with budget j.

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int n, w;                     // Number of books and maximum budget
    vector<int> price, pages;      // Price and page count of each book

    int solve_knapsack() {
        // Rolling array for memory efficiency: dp[2][w+1]
        int dp[2][w + 1];
        memset(dp, 0, sizeof dp);

        // Process each book
        for (int i = 0; i < n; i++) {
            for (int j = 1; j <= w; j++) {
                int &ans = dp[i % 2][j];

                // If we can afford this book, check taking it
                if (j >= price[i]) {
                    ans = pages[i] + dp[1 - i % 2][j - price[i]];
                }
                ans = max(ans, dp[1 - i % 2][j]); // also consider the option of not taking this book
            }
        }

        // Final answer is in dp[1 - n%2][w]
        return dp[1 - n % 2][w];
    }

    void solve() {
        cin >> n >> w;
        price.resize(n);
        pages.resize(n);

        // Read book prices
        for (int i = 0; i < n; i++) {
            cin >> price[i];
        }

        // Read book page counts
        for (int i = 0; i < n; i++) {
            cin >> pages[i];
        }

        cout << solve_knapsack();
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    Solution sol;
    sol.solve();
}
